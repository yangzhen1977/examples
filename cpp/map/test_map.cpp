// Example program
#include <cassert>
#include <cstdint>
#include <iostream>
#include <map>
#include <string>

void test_lower_bound()
{
    std::map<int32_t, std::string> m;
    m[1] = "is 1";
    m[5] = "is 5";
    m[9] = "is 9";

    auto iter = m.lower_bound(3);
    assert(5 == iter->first);
    std::cout << "3 lower_bound:" << iter->second << std::endl;

    iter = m.lower_bound(5);
    assert(5 == iter->first);
    std::cout << "5 lower_bound:" << iter->second << std::endl;

    iter = m.lower_bound(9);
    assert(9 == iter->first);
    std::cout << "9 lower_bound:" << iter->second << std::endl;

    iter = m.lower_bound(7);
    assert(9 == iter->first);
    std::cout << "7 lower_bound:" << iter->second << std::endl;
}


void test_upper_bound()
{
    std::map<int32_t, std::string> m;
    m[1] = "is 1";
    m[5] = "is 5";
    m[9] = "is 9";
    m[20] = "is 20";

    auto iter = m.upper_bound(3);
    assert(5 == iter->first);
    std::cout << "3 upper_bound:" << iter->second << std::endl;

    iter = m.upper_bound(5);
    assert(9 == iter->first);
    std::cout << "5 upper_bound:" << iter->second << std::endl;

    iter = m.upper_bound(9);
    assert(20 == iter->first);
    std::cout << "9 upper_bound:" << iter->second << std::endl;
    
    iter = m.upper_bound(7);
    assert(9 == iter->first);
    std::cout << "7 upper_bound:" << iter->second << std::endl;
}

int main(int argc, char* argv[])
{
    test_lower_bound();
    test_upper_bound();
    return 0;
}
