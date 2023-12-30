English ｜ [日本語](README-ja.md)
# vecmath-cpp

This is a C++ port of Java3D vecmath(vector/matrix mathmatics), implented as C++ template header files.
Often used in 3D graphics projects, math projects, dynamics or physics projects.

## Classes

Here's a class diagram of all the classes included.

![image](https://github.com/kenjihiranabe/vecmath-cpp/assets/1093925/7a562372-bbc6-43d4-ac7d-6ea66b7da3e4)


## Rationals

I thought a parallel C++ version of the Java package can make a FAST vector/matrix library by the original Java3D specification's unique natures.
Java3D designers decided to;

1. Make all member variables 'public'.
2. Make all methods(member functions) 'final' (non-virtual)
3. Avoid using arrays in Matrices and Vectors.
4. Distiguish Points from Vectors as different classes.

Design decision (1)-(3) are from Java's inherent speed problem. 

(1) looks like a bad approach in object-orientation and thread-safy sence, but if neccesary, encapsulation can be done by wrapper classes (Java3D does have wrappers for their SceneGraph use).

(2) can cause subclassing problems, but since each method does an apparent and natural job, the semantics can be kept consistent.

(3) can make a code bloat problem because no for/while loop with array indexing is in the library code.
But I found it not so bad after I tried implementation, and it makes this library FAST.

(4) was a very good decision. This makes your programs semanticly consistent and increases readabilty.

Luckly, these four points makes this parallel C++ library very unique. Highest priority to time efficiency. i.e. no 'virtual' calls, no 'new's, extensively inlined templates, public members, and para-phrazed calculation(no loops and array indexing in methods).

For example, not having an array representation in Matrices, the determinant of Matrix3 is coded as;

```C++
template < class T >
T Matrix3 < T >::determinant() const {
    // I believe this is the fastest way, less calculation and no indexing.
    return m00*(m11*m22 - m21*m12)
        - m01*(m10*m22 - m20*m12)
        + m02*(m10*m21 - m20*m11);
}
```

Off cource there are shortcomings in this C++ package.

- Element access by index is slow.
'operatoer[]' is not supported intensionally, because this can lead to a programming style which can cause a performance problem.

```C++
     // a bad user program
     Vector3d u(1,2,3), v;
     Matrix3d m(1,2,3,4,5,6,7,8,9);

     //  this can be very slow
     for (unsigned i = 0; i < 3; i++)
        for (unsigned j = 0; j < 3; j++)
            v[i] = m(i,j)*u[j];
```

This [] array element access syntax could have been supported in the library, but not. You should use METHODs.

```C++
     m.transform(u, &v);   // much faster

//      or

     v = m*u;              // others like this style better, but this operator is not supported either for now.
```

which are much faster, and readable. A lot of methods are prepared so that users don't have to access elements directly.

## Usage

Just copy all the '*.h' files into one of your C++ project directory and add its path to the compiler's include option.
Look at test.cpp files for typical usages.

## Environment

Developed and tested on MacOS with GNU gcc compiler. See Makefile for the compilation options.

```
gcc --version
Apple clang version 15.0.0 (clang-1500.0.40.1)
Target: arm64-apple-darwin23.1.0
Thread model: posix
```

It also worked on Windows. Please let me know if you have experienced difficulties, by adding issues.

## Other Features

All code is in *.h file. No need to compile. You can just place them and include them.

You can control whether to include the following options by editing Vm_conf.h.

- String representations of the objects. Define VM_INCLUDE_STRING.
- Output to <ostream>. Define VM_INCLUDE_IO.
- Whether to enclose this package in a namespace. Define VM_INCLUDE_NS. Default namespace is kh_vecmath, but you can use other names.

All supports are on by default. For example, you can code like;

```C++
Matrix3 m();
std::string s = m.toString(); // to get a string representation.
std::cout << m;               // output to ostream.
```

You can edit Vm_conf.h to disable them for some limited environment.

## Lisence

BSD Lisence.

## History

The original implemenation is at;

[http://objectclub.jp/download/vecmath_e](http://objectclub.jp/download/vecmath_e
)

The library was first implemented in 1997. In 2023, I (the original author) salvage the soruce code and put it onto GitHub.
The original above site includes a lot of references I used to implement this code.

