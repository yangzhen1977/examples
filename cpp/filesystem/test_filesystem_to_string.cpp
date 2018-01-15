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
int main(int argc, char *argv[])
{
    path_to_string();
    return 0;
}
