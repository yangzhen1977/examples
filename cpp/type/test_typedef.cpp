#include <cassert>
#include <cstdint>
#include <iostream>
#include <typeinfo>
#include <typeindex>

class CParent
{
    public:
    typedef char  data_type[1];
};
class CChild1 : public CParent
{
  public:
    typedef char data_type[2];
  public:
    void check_parent_typedef(){
        std::cout << "call in Child1 sizeof(CParent::data_type):" << sizeof(CParent::data_type) << std::endl;
        assert(1 == sizeof(CParent::data_type));
    }
    void check_self_typedef(){
        std::cout << "call in Child1 sizeof(data_type):" << sizeof(data_type) << std::endl;
        assert(2 == sizeof(data_type));
        
        std::cout << "call in Child1 sizeof(CChild1::data_type):" << sizeof(CChild1::data_type) << std::endl;
        assert(2 == sizeof(CChild1::data_type));
    }
};

int main(int argc, char *argv[])
{
    std::cout << "sizeof(CParent::data_type):" << sizeof(CParent::data_type) << std::endl;
    assert(1 == sizeof(CParent::data_type));

    std::cout << "sizeof(CChild1::data_type):" << sizeof(CChild1::data_type) << std::endl;
    assert(2 == sizeof(CChild1::data_type));

    CChild1().check_parent_typedef();
    CChild1().check_self_typedef();
    return 0;
}