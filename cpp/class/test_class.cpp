// Example program
#include <cassert>
#include <iostream>
#include <type_traits>

class A
{
};

class B : A
{
};

class C: public B
{
};

class D
{

};

int test_is_base_of(int argc, char *argv[])
{
    //std::cout << std::boolalpha;
    assert(1 == (std::is_base_of<A, B>::value));
    std::cout << "A2B:" << std::is_base_of<A, B>::value << std::endl;

    assert(1 == (std::is_base_of<A, C>::value));
    std::cout << "A2C:" << std::is_base_of<A, C>::value << std::endl;

    assert(1 == (std::is_base_of<B, C>::value));
    std::cout << "B2C:" << std::is_base_of<B, C>::value << std::endl;

    assert(0 == (std::is_base_of<A, D>::value));
    std::cout << "A2D:" << std::is_base_of<A,D>::value << std::endl;
    return 0;
}
int main(int argc, char *argv[])
{
    test_is_base_of(argc, argv);
    return 0;

}
