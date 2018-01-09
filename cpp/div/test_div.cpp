// Example program
#include <cassert>
#include <cstdlib>
#include <iostream>
#include <string>
#include <regex>

void test_div()
{
    int32_t i1 = 4;
    int32_t i2 = 5;
    int32_t i3 = i1 / i2;

    assert( 0 == i3);

    i1 = 1;
    i2 = 5;
    i3 = i1 / i2;
    assert( 0 == i3);

    i1 = 6;
    i2 = 5;
    i3 = i1 / i2;
    assert(1 == i3);

    i1 = 9;
    i2 = 5;
    i3 = i1 / i2;
    assert(1 == i3);
}
int main(int argc, char *argv[])
{
    test_div();
    return 0;
}
