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
int test_regex_match_prefix_suffix(int argc, char *argv[])
{
    std::regex re("([a-z]*) ([a-z]*)");
    std::string line = "123aaa bbb456";
    std::smatch m;
    if (std::regex_search(line, m, re))
    {
        std::cout << "match" << std::endl;
        std::cout << "m[1]" << m[1] << std::endl;
        std::cout << "m.prefix:" << m.prefix().str() << std::endl;
        std::cout << "m.suffix:" << m.suffix().str() << std::endl;
        std::cout << "m[1]" << m[1] << std::endl;
        std::cout << "m[2]" << m[2] << std::endl;
        assert(m.prefix().str() == "123");
        assert(m.suffix().str() == "456");
        assert(m[1] == "aaa");
        assert(m[2] == "bbb");
    }
    else
    {
        assert(false);
        std::cerr << "not match" << std::endl;
    }
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


    ori_str = "123abc456abc";
    target_str = "123def456def";
    new_str = std::regex_replace(ori_str, std::regex("abc"), "def");
    std::cout << "ori_str:" << ori_str << std::endl;
    std::cout << "target:" << target_str << std::endl;
    std::cout << "new_str:" << new_str << std::endl;
    assert(new_str == target_str);
    assert(new_str !=  ori_str);


    ori_str = "'int32_t (class wme::IWmeExternalInputter **)'";
    target_str = "'int32_t (wme::IWmeExternalInputter **)'";
    new_str = std::regex_replace(ori_str, std::regex("\\\(class "), "\(");
    std::cout << "ori_str:" << ori_str << std::endl;
    std::cout << "target:" << target_str << std::endl;
    std::cout << "new_str:" << new_str << std::endl;
    assert(new_str == target_str);
    assert(new_str !=  ori_str);


    ori_str = "'int32_t (int32_t a, class wme::IWmeExternalInputter **)'";
    target_str = "'int32_t (int32_t a, wme::IWmeExternalInputter **)'";
    new_str = std::regex_replace(ori_str, std::regex(", class "), ", ");
    std::cout << "ori_str:" << ori_str << std::endl;
    std::cout << "target:" << target_str << std::endl;
    std::cout << "new_str:" << new_str << std::endl;
    assert(new_str == target_str);
    assert(new_str !=  ori_str);


    ori_str = "'int32_t (class wme::IWmeExternalInputter **, class wme::IWmeExternalInputter **)'";
    target_str = "'int32_t (wme::IWmeExternalInputter **, wme::IWmeExternalInputter **)'";
    new_str = std::regex_replace(ori_str, std::regex(", class "), ", ");
    std::cout << "ori_str:" << ori_str << std::endl;
    std::cout << "target:" << target_str << std::endl;
    std::cout << "new_str:" << new_str << std::endl;
    assert(new_str == target_str);
    assert(new_str !=  ori_str);
    return 0;
}

void check_multiple_regex_search( const std::string str, std::regex re)
{
    std::smatch m;
    if (std::regex_search(str, m, re))
    {
        std::cout << str << ": " <<m[1] << ", " << m[2] << ":" << m[3] << ":" << m[4] << std::endl;
    }else{
        std::cerr << "not match " << str << std::endl;
    }
}
void test_multiple()
{
    std::cout << "***************************************************" << std::endl;
    std::cout << "test_multiple  begin:" << std::endl;
    const std::string str1 = "public 'struct abc::C1'";
    const std::string str2 = "public 'class abc::C2'";
    const std::string str3 = "private 'struct abc::C3'";
    const std::string str4 = "private 'class abc::C4'";
    const std::string str5 = "virtual public 'struct abc::C1'";
    const std::string str6 = "virtual public 'class abc::C2'";
    const std::string str7 = "virtual private 'struct abc::C3'";
    const std::string str8 = "virtual private 'class abc::C4'";

    auto re = std::regex("^(virtual|) *(public|private) '(struct|class) (.*)'$");
    check_multiple_regex_search(str1, re);
    check_multiple_regex_search(str2, re);
    check_multiple_regex_search(str3, re);
    check_multiple_regex_search(str4, re);
    check_multiple_regex_search(str5, re);
    check_multiple_regex_search(str6, re);
    check_multiple_regex_search(str7, re);
    check_multiple_regex_search(str8, re);
    std::cout << "test_multiple  end." << std::endl;
}
int main(int argc, char *argv[])
{
    test_regex_match_without_result(argc, argv);
    test_regex_match_with_result(argc, argv);
    test_regex_match_prefix_suffix(argc, argv);
    test_regex_replace(argc, argv);
    test_multiple();
    return 0;
}
