// Example program
#include <cstdlib>
#include <experimental/filesystem>
#include <iostream>
#include <string>
#include <regex>

int test_filesystem1(int argc, char *argv[])
{
    std::experimental::filesystem::path p1 = "../";
    std::cout << "absolute:" << p1.is_absolute() << std::endl;
    std::cout << "relative:" << p1.is_relative() << std::endl;
    std::experimental::filesystem::path p2 = "build";
    auto p3 = p1 / p2;
    std::cout << "p3:" << p3 << std::endl;
    return 0;
}
int test_filesystem2(int argc, char *argv[])
{
    std::experimental::filesystem::path p1 = "/Users/zyang2/";
    std::experimental::filesystem::path p2 = "build";
    auto p3 = p1 / p2;
    std::cout << "p3:" << p3 << std::endl;
    return 0;
}
int main(int argc, char *argv[])
{
    test_filesystem1(argc, argv);
    test_filesystem2(argc, argv);
    return 0;
}
