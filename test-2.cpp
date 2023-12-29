#include "Vector2.h"
#include "Tuple2.h"
#include "Point2.h"

#ifdef VM_INCLUDE_NAMESPACE
using namespace kh_vecmath;
#endif

/**
 * test-2 for Vector2
 */
#ifdef TESTALL
int test_2() {
#else
int main(int, char**) {
#endif
    Point2d p1(1,2);
    Point2d p2(4,6);

    // distance
    Point2d::value_type d = p1.distance(p2);
    assert(fabs(d - 5) < 1.0e-5);

    // distance L1
    d = p1.distanceL1(p2);
    assert(d == 7);

    // distance Linf
    d = p1.distanceLinf(p2);
    assert(d == 4);

    return 0;
}
