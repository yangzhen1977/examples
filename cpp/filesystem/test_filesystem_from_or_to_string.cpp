// Example program
#include <cassert>
#include <experimental/filesystem>
#include <iostream>
#include <string>

int path_to_string()
{
    std::experimental::filesystem::path p1 = std::experimental::filesystem::current_path();
    
    std::cout << "current path is " << p1.string() << std::endl;
    return 0;
}

void path_from_string()
{
    auto cur_path = std::experimental::filesystem::current_path();
    const std::string str = cur_path.string();
    auto path_from_string = std::experimental::filesystem::path(str);
    assert(cur_path == path_from_string);
}

void implict_path_from_string()
{
    auto cur_path = std::experimental::filesystem::current_path();
    const std::string str = cur_path.string();
    auto canonical_path_from_string = std::experimental::filesystem::canonical(str);
    assert(cur_path == canonical_path_from_string);
}

int main(int argc, char *argv[])
{
    path_to_string();
    path_from_string();
    implict_path_from_string();
    return 0;
}
