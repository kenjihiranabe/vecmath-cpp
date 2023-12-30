#include "vecmath.h"
#include <iostream>

using namespace kh_vecmath;

int main(int, char**) {
    Matrix3d m(1,2,3,4,5,6,7,8,9);
    Vector3d v(2,3,4);
    std::cout << m*v << std::endl;
    return 0;
}
