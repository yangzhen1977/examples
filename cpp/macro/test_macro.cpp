// Example program

#include <cassert>
#include <iostream>
#include <tuple>

int32_t test_()
{
    return 0;
}
int g_value_1 = -1;
int g_value_2 = -2;
std::tuple<int32_t, std::string> test_1( std::string index)
{
    return std::make_tuple(1, index);
}

#define FUNC(index) \
    do{ \
        g_value_##index = index;    \
        res = test_##index(#index);   \
    }while(0)

int main(int argc, char *argv[])
{
    assert( -1 == g_value_1);
    std::tuple<int32_t, std::string> res;
    FUNC(1);
    int32_t res1 = std::get<0>(res);
    std::string res2 = std::get<1>(res);
    std::cout << "FUNC(1)=(" << res1 << "," << res2 << ")" << std::endl;
    std::cout << "g_value_1 = " << g_value_1 << std::endl;
    assert(1 == res1);
    assert(std::string("1") == res2);
    assert(1 == g_value_1);
    return 0;
}
