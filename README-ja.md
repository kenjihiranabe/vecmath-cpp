[English](README.md) | 日本語
# vecmath-cpp

Java(TM) 3D API 1.2 で仕様が公開されている，javax.vecmath パッケージの，非公式な C++ 実装です．3D グラフィックス，数学，力学や物理のプロジェクトでよく利用されるものです．

## クラス図とドキュメント

すべてのクラスが含まれるクラス図です．

![image](https://github.com/kenjihiranabe/vecmath-cpp/assets/1093925/7a562372-bbc6-43d4-ac7d-6ea66b7da3e4)

このライブラリについての数学の詳細が，[vecmath.pdf](vecmath.pdf) にあります．
また，Quaternions については [Qiita記事：Quaternionの数学解説](https://qiita.com/kenjihiranabe/items/945232fbde58fab45681) に詳説があります．


## 実装方針

Java3D vecmath のデザイン以下の点でユニークであるため，
高速な平行 C++ バージョンを実装することに意味があると考え，実装しました．
Java3D のデザイナーは，次のような方針をとりました．

1. すべてのメンバ変数が `public` である．
2. すべてのメソッド(メンバ関数)が `final` (non-virtual) である．
3. `Matrix` や `Vector` 中に，配列の表現を持たない．
4. `Point` と `Vector` が別クラスとして（型安全に）区別されている．

(1)-(3)の設計は，もともと Java の速度上の問題から決定されたと思われます．

(1) はオブジェクト指向的にあるいはスレッド セーフ的に良くないスタイルのように見えますが，必要であれば上位でカプセル化することができます(実際 Java3D の SceneGraph ではラッパを作っています)． 

(2) はサブクラス化の際に問題になるかもしれませんが，1つ1つのメソッドが明確で自然な仕事をしているため，セマンティクスの一貫性は保たれるでしょう．

(3) は for/while ループと添字による要素アクセスがないため，ライブラリコードの増大をもたらす可能性があります．しかし実際に実装してみるとそうでもないことに気付きました．また，これがこのライブラリの最大の特徴である速度を稼ぐポイントとなっています．

(4) はとてもよい設計判断だったと思います．コードがセマンティクス的に一貫し，可読性も向上します．

幸運なことに，上記の4つの点は，この C++ 版バージョンをとてもユニークなものにしています．速度に最高のプライオリティを置いているのです．すなわち， 仮想関数呼び出しがなく，new 演算子がなく，inline 化された template をヘビーに使用し，メンバ変数は public で，かつ，各メソッド中の数値計算はパラフレーズされています(ループや配列要素への添字によるアクセスが皆無です)．

たとえば，Matrix は配列表現を内部にもたないため，`Matrix3` の中では次のようなコーディングがされています．


```C++
template < class T >
T Matrix3 < T >::determinant() const {
    // I believe this is the fastest way, less calculation and no indexing.
    return m00*(m11*m22 - m21*m12)
        - m01*(m10*m22 - m20*m12)
        + m02*(m10*m21 - m20*m11);
}
```

もちろん，この C++ バージョンには欠点もあります．
添字による要素アクセスの `operatoer[]` は意図的にサポートしませんでした．これを使用したユーザプログラム は速度の問題を起こす可能性があるからです．

```C++
     // a bad user program
     Vector3d u(1,2,3), v;
     Matrix3d m(1,2,3,4,5,6,7,8,9);

     //  this can be very slow
     for (unsigned i = 0; i < 3; i++)
        for (unsigned j = 0; j < 3; j++)
            v[i] = m(i,j)*u[j];
```

このようなシンタクスはサポートしてもよかったのですが，むしろ，名前の付いたメソッドや数学的な記法を使ってオペレータを呼び出したほうがよいのです．

```C++
     m.transform(u, &v);   // much faster

//      or

     v = m*u;              // others like this style better
```

これらは，ずっと高速で，かつ読みやすいものです．ユーザープログラムでは，要素を直接アクセスする必要はほとんどないように多数のメソッドが用意されていますので，そちらを使うように心がけるべきでしょう．

## 利用方法

この実装には，.cpp ファイルがなく，ヘッダファイルのみで構成されていますのでビルドする必要はありません．
すべての '*.h' ファイルをご自身の C++ プロジェクトのサブディレクトリにコピーし，
コンパイラの include オプションにそのパスを追加してください．

vecmath のクラスを利用するには，`vecmath.h` ヘッダファイルをインクルードしてください．
以下は `hello-vecmath.cpp` の例です．

```C++ hello-vecmath.cpp
#include <iostream>
#include "vecmath.h"

using namespace kh_vecmath;

int main(int, char**) {
    Matrix3d m(1,2,3,4,5,6,7,8,9);
    Vector3d v(2,3,4);
    std::cout << m*v << std::endl;
    return 0;
}
```

## 環境

MacOS で GNU gcc コンパイラで開発・テストしました．コンパイルオプションは `Makefile` を見てください．

```
gcc --version
Apple clang version 15.0.0 (clang-1500.0.40.1)
Target: arm64-apple-darwin23.1.0
Thread model: posix
```

Windows でも動作した実績もあります．問題があればこのサイトの issue に追加してください．

## その他の特徴

いくつかのオプションを用意しており，`Vm_conf.h` を編集することで，以下のような機能を制御できます．

- オブジェクトの文字列表現．`VM_INCLUDE_STRING` を define してください．
- ostream への出力．`VM_INCLUDE_IO` を define してください．
- このパッケージを名前空間で囲むかどうか．`VM_INCLUDE_NS` を define してください．デフォルトの名前空間は `kh_vecmath` ですが，他の名前を使うこともできます．

すべてのオプションはデフォルトで有効になっています．たとえば，以下のようにコードを書くことができます．

```C++
Matrix3 m();
std::string s = m.toString(); // to get a string representation.
std::cout << m;               // output to ostream.
```

`Vm_conf.h` を編集することで，これらの機能を無効にすることもできます．
なんらかの制限のある環境での利用を想定しています．

## ライセンス

BSD Lisence.

## 履歴

オリジナルの実装は以下のサイトにあります．

[http://objectclub.jp/download/vecmath1](http://objectclub.jp/download/vecmath1
)

このライブラリは1997年に初めて実装されました．2023年に，私(オリジナルの作者)はソースコードを回収し，GitHub に置きました．2023年の大晦日の大掃除のようなものです．


