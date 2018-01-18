// Example program
#include <cassert>
#include <experimental/filesystem>
#include <iostream>
#include <string>

int parent_relation()
{
    std::experimental::filesystem::path p1 = std::experimental::filesystem::current_path();
    auto real_p1 = std::experimental::filesystem::canonical(p1);
    auto parent = real_p1.parent_path();
    assert(!parent.empty());


    assert(false);
    std::cerr << "not impl now" << std::endl;
    return 0;
}


int main(int argc, char *argv[])
{
    parent_relation();

    return 0;
}
