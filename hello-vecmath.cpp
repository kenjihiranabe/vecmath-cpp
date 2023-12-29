#define VM_INCLUDE_IO
#include "vecmath.h"
#include <iostream>

using namespace kh_vecmath;
using namespace std;

int main(int, char**) {
    Matrix3d m(1,2,3,4,5,6,7,8,9);
    Vector3d v(2,3,4);
    cout << m*v << endl;
    return 0;
}
