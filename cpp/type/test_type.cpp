#include <iostream>
#include <typeinfo>
#include <typeindex>

class CParent
{

};
class CChild1: public CParent
{

};

namespace ns
{

class CParent
{
};
class CChild1 : public CParent
{
};
}

template<class TYPE>
void test_type_info(const std::string test_name)
{
    const std::type_info &info = typeid(TYPE);

    std::cout << "type_info(" << test_name <<"):" << std::endl;
    std::cout << "     name is '" << info.name() << "'" << std::endl;
    std::cout << "     hash_code is '" << info.hash_code() << "'" << std::endl;
}

template <class TYPE>
void test_type_index(const std::string test_name)
{
    const std::type_index &info = typeid(TYPE);

    std::cout << "type_info(" << test_name <<"):" << std::endl;
    std::cout << "     name is '" << info.name() << "'" << std::endl;
    std::cout << "     hash_code is '" << info.hash_code() << "'" << std::endl;
}
int main(int argc, char* argv[])
{
    test_type_info<CChild1>("CChild1");
    test_type_index<CChild1>("CChild1");
    
    test_type_info<ns::CChild1>("ns::Child1");
    test_type_index<ns::CChild1>("ns::CChild1");
    return 0;
}