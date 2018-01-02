// Example program
#include <cassert>
#include <cstdlib>
#include <iostream>
#include <string>
#include <regex>

int test_regex_match(int argc, char *argv[])
{
    std::regex re("(.*) (.*)");
    std::string line = "abc 123";
    std::smatch m;
    if (std::regex_match(line, m, re))
    {
        std::cout << "match" << std::endl;
        std::cout << "m[1]" << m[1] << std::endl;
        std::cout << "m[2]" << std::stoi(m[2]) << std::endl;
    }
    else
    {
        std::cerr << "not match" << std::endl;
    }

    line = "<scratch space>12 <scratch space> 34";
    std::string new_line = line;
    auto new_line2 = std::regex_replace(new_line, std::regex("<scratch space>"), "");
    std::cout << "new line:" << new_line << std::endl;
    std::cout << "new line2:" << new_line2 << std::endl;
    return 0;
}
int test_regex_replace(int argc, char *argv[])
{
    std::string ori_str = "/Users/test/testapp.o.ast.dump";
    const std::string target_str = "/Users/test/testapp.o.info.json";
    std::string new_str = std::regex_replace(ori_str, std::regex("ast\\.dump$"), "info.json");
    std::cout <<"ori_str:" << ori_str << std::endl;
    std::cout <<"new_str:" << new_str << std::endl;
    assert(new_str == target_str);
    return 0;
}
int main(int argc, char *argv[])
{
    test_regex_match(argc, argv);
    test_regex_replace(argc, argv);
    return 0;
}