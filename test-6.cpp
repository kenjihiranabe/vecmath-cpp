#include "Point4.h"
#include "Vector4.h"

template<class T, class S>
bool equals(T a, S b) {
    return fabs(a - b) < 1.0e-8;
}

#ifdef VM_INCLUDE_NAMESPACE
using namespace kh_vecmath;
#endif

/**
 * test for Point4
 */
#ifdef TESTALL
int test_6() {
#else
int main(int, char**) {
#endif
    const double da[] =
             { 1, 2, 3, 4, 5 };
    Point4d p1(da);
    Point4d p2(4, 6, 1, -1);

    // distance
    Point4d::value_type d = p1.distance(p2);
    Vector4d dv = p2 - p1;
    assert(equals(d, dv.length()));

    // distance L1
    d = p1.distanceL1(p2);
    assert(d == 14);

    // distance Linf
    d = p1.distanceLinf(p2);
    assert(d == 5);

    // project
    p1.project(Point4d(6, 4, 2, 2));
    assert(p1 == Point4d(3, 2, 1, 1));

    return 0;
}
