// Example program
#include <cassert>
#include <cstdlib>
#include <iostream>
#include <string>
#include <regex>

int test_regex_match_without_result(int argc, char *argv[])
{
    std::regex re("(.*) (.*)");
    std::string line = "abc 123";
    if (std::regex_match(line, re))
    {
        std::cout << "match" << std::endl;
    }
    else
    {
        assert(false);
        std::cerr << "not match" << std::endl;
    }

    return 0;
}
int test_regex_match_with_result(int argc, char *argv[])
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
    std::string ori_str;
    std::string target_str;
    std::string new_str;

    ori_str = "/Users/test/testapp.o.ast.dump";
    target_str = "/Users/test/testapp.o.info.json";
    new_str = std::regex_replace(ori_str, std::regex("ast\\.dump$"), "info.json");
    std::cout << "ori_str:" << ori_str << std::endl;
    std::cout << "target:" << target_str << std::endl;
    std::cout <<"new_str:" << new_str << std::endl;
    assert(new_str == target_str);
    assert(new_str != ori_str);

    ori_str = "1\r\n2\n3\r\n";
    target_str = "123";
    new_str = std::regex_replace(ori_str, std::regex("\r|\n"), "");
    std::cout << "ori_str:" << ori_str << std::endl;
    std::cout << "target:" << target_str << std::endl;
    std::cout << "new_str:" << new_str << std::endl;
    assert(new_str == target_str);
    assert(new_str !=  ori_str);
    return 0;
}
int main(int argc, char *argv[])
{
    test_regex_match_without_result(argc, argv);
    test_regex_match_with_result(argc, argv);
    test_regex_replace(argc, argv);
    return 0;
}
