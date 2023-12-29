#include <cassert>

#include "TexCoord2.h"
#include "Color3.h"
#include "Color4.h"

#ifdef VM_INCLUDE_NAMESPACE
using namespace kh_vecmath;
#endif

/**
 * test for Simple tuples.
 */
#ifdef TESTALL
int test_10() {
#else
int main(int, char**) {
#endif
    Color4<float> c;
    TexCoord2f tc;
    Color3b cb(255, 123, 254);
    cb.x = 0;
    tc.x = 10;
    c.y = 1.0f;
    return 0;
}
