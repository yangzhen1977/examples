// Example program
#include <cassert>
#include <cstdlib>
#include <iostream>
#include <string>
#include <regex>

int test_string_length_size(int argc, char *argv[])
{
    std::string str;
    str.resize(3);
    str.reserve(50);
    std::cout << "str.size() is " << str.size() << std::endl;
    std::cout << "str.length() is " << str.length() << std::endl;
    std::cout << "str.capacity() is " << str.capacity() << std::endl;
    assert(3 == str.size());
    assert(3 == str.length());
    assert(50 < str.capacity());

    *(char *)(&str[2]) = 'a';
    std::cout << "str.size() is " << str.size() << std::endl;
    std::cout << "str.length() is " << str.length() << std::endl;
    std::cout << "str.capacity() is " << str.capacity() << std::endl;
    assert(3 == str.size());
    assert(3 == str.length());
    assert(50 < str.capacity());

    str = "a";
    std::cout << "str.size() is " << str.size() << std::endl;
    std::cout << "str.length() is " << str.length() << std::endl;
    std::cout << "str.capacity() is " << str.capacity() << std::endl;
    assert(1 == str.size());
    assert(1 == str.length());
    assert(50 < str.capacity());

    return 0;
}
int main(int argc, char *argv[])
{
    test_string_length_size(argc, argv);
    return 0;
}
