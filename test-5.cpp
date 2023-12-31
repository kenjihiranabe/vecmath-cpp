#include "Vector3.h"

template<class T, class S>
bool equals(T a, S b) {
    return fabs(a - b) < 1.0e-8;
}

#ifdef VM_INCLUDE_NAMESPACE
using namespace kh_vecmath;
#endif

/**
 * test for Vector3
 */
#ifdef TESTALL
int test_5() {
#else
int main(int, char**) {
#endif
    Vector3d p1(1,2,3);
    Vector3d p2(4,6,1);

    // dot product
    Vector3d::value_type d = p1.dot(p2);
    assert(equals(d, 19));

    // length
    d = p1.length();
    assert(equals(d, sqrt(p1.dot(p1))));

    // normalize
    p1.normalize();
    assert(equals(p1.x,1/d));
    assert(equals(p1.y,2/d));
    assert(equals(p1.z,3/d));

    p1.set(-1,3,1);
    d = p1.length();
    p2.normalize(p1);
    assert(equals(p2.x,-1/d));
    assert(equals(p2.y, 3/d));
    assert(equals(p2.z, 1/d));
    
    // angle
    p1.set(3, 4, 1);
    p2.set(-4, 3, 1);
    d = p1.angle(p2);
    assert(equals(d, acos(p1.dot(p2)/p1.length()/p2.length())));
    d = p2.angle(p1);
    assert(equals(d, acos(p1.dot(p2)/p1.length()/p2.length())));
    d = p1.angle(p1);
    assert(equals(d, 0));
    d = p2.angle(p2);
    assert(equals(d, 0));

    return 0;
}
