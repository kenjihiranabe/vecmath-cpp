#ifndef M_PI
#define M_PI        3.14159265358979323846
#endif



#include "vecmath.h"

#ifdef VM_INCLUDE_NAMESPACE
using namespace kh_vecmath;
#endif


/**
 * test for toString()
 */
#ifdef TESTALL
int test_12() {
#else
int main(int, char**) {
#endif
#ifdef VM_INCLUDE_TOSTRING
    AxisAngle4d aa(1,2,3,4);
    std::cout << aa.toString() << std::endl;
    assert(aa.toString() == "(1,2,3,4)");

    Color3d c3(1,2,3);
    std::cout << c3.toString() << std::endl;
    assert(c3.toString() == "(1,2,3)");

    Color4f c4(1,2,3,4);
    std::cout << c4.toString() << std::endl;
    assert(c4.toString() == "(1,2,3,4)");
    Matrix3d m3d(1,2,3,4,5,6,7,8,9);
    std::cout << m3d.toString() << std::endl;
    assert(m3d.toString() ==
           "[ [1,2,3]\n"
           "  [4,5,6]\n"
           "  [7,8,9] ]");

    Point2f p2f(3,4);
    std::cout << p2f.toString() << std::endl;
    assert(p2f.toString() == "(3,4)");

    Quat4d q4d(3,4,1,2);
    std::cout << q4d.toString() << std::endl;
    assert(q4d.toString() == "(3,4,1,2)");

    Vector4d v4d(3,4,1,2);
    std::cout << v4d.toString() << std::endl;
    assert(v4d.toString() == "(3,4,1,2)");
#endif

    return 0;
}
