// Example program
#include <cassert>
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
    std::string target = "/Users/zyang2/build";
    assert(p3.string() == target);

    return 0;
}
int test_filesystem3(int argc, char *argv[])
{
    std::experimental::filesystem::path p1 = std::experimental::filesystem::current_path();
    std::experimental::filesystem::path p2 = ".";
    std::cout << "current_path p1:" << std::experimental::filesystem::absolute(p1) << std::endl;
    std::cout << ". p2:" << std::experimental::filesystem::absolute(p2) << std::endl;
    assert(p1.string() != p2.string());
    assert(std::experimental::filesystem::equivalent(p1,p2));
    return 0;
}
int main(int argc, char *argv[])
{
    test_filesystem1(argc, argv);
    test_filesystem2(argc, argv);
    test_filesystem3(argc, argv);
    return 0;
}
