// Example program
#include <cstdlib>
#include <experimental/filesystem>
#include <iostream>
#include <string>
#include <regex>

int test_regex(int argc, char *argv[])
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
int main(int argc, char *argv[])
{
    return test_regex(argc, argv);
    return 0;
}
