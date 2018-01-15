// Example program
#include <cassert>
#include <cstdlib>
#include <experimental/filesystem>
#include <iostream>
#include <string>
#include <regex>

int loop_from_a_file()
{
    std::experimental::filesystem::path p1 = std::experimental::filesystem::current_path();
    std::experimental::filesystem::path real_p1 = std::experimental::filesystem::canonical(p1);

    auto parent = real_p1.parent_path();
    while(!parent.empty()){
        std::cout << parent.string() << std::endl;
        parent = parent.parent_path();
    }

    return 0;
}
int main(int argc, char *argv[])
{
    loop_from_a_file();
    return 0;
}
