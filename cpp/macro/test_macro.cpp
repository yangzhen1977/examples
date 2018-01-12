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

void test1()
{
    assert(-1 == g_value_1);
    std::tuple<int32_t, std::string> res;
    FUNC(1);
    int32_t res1 = std::get<0>(res);
    std::string res2 = std::get<1>(res);
    std::cout << "FUNC(1)=(" << res1 << "," << res2 << ")" << std::endl;
    std::cout << "g_value_1 = " << g_value_1 << std::endl;
    assert(1 == res1);
    assert(std::string("1") == res2);
    assert(1 == g_value_1);
}
struct CS
{
    std::string attr_ = "attr default";
    std::string is_attr_ = "is_attr default";
};
CS g_cs;
#define FUNC2(key)                    \
    do                                \
    {                                 \
        g_cs.key##_ = "attr changed"; \
        g_cs.is_##key##_ = "is attr changed"; \
    } while (0)

void test2()
{
    std::cout << "attr_ is " << g_cs.attr_ << std::endl;
    std::cout << "is_attr_ is " << g_cs.is_attr_ << std::endl;
    FUNC2(attr);
    std::cout << "attr_ is " << g_cs.attr_ << std::endl;
    std::cout << "is_attr_ is " << g_cs.is_attr_ << std::endl;
    assert(g_cs.attr_ == "attr changed");
    assert(g_cs.is_attr_ == "is attr changed");
}
int main(int argc, char *argv[])
{
    test1();
    test2();
    return 0;
}
