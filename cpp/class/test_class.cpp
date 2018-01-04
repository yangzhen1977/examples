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

namespace t2{
    class CParent
    {
    public:
        virtual std::string called_class_name(){
            return "CParent";
        }
    };

    class CChild1 : public CParent
    {
      public:
        virtual std::string called_class_name()
        {
            return "CChild1";
        }
    };

    template<class T>
    class CTemplate2
    {
      public:
        virtual std::string called_class_name()
        {
            return "CTemplate2";
        }
    };

    class CChild2 : public CParent, public CTemplate2<CChild2>
    {
      public:
    };

    template <class P, class T>
    class CTemplate3: public P
    {
      public:
        virtual std::string called_class_name()
        {
            return "CTemplate3";
        }
    };

    class CChild3 : public CTemplate3<CParent, CChild3>
    {
      public:
    };
}

int test_inherient_and_template(int argc, char *argv[])
{
    //std::cout << std::boolalpha;
    t2::CParent* p = nullptr;
    t2::CChild2 c2;
    p = & c2;
    std::cout << "Parent->on CChild2:" << p->called_class_name() << std::endl;
    assert(p->called_class_name() == "CParent");
    #if 0
    //compiler failed
    std::cout << "CChild2->on CChild2:" << c2.called_class_name() << std::endl;
    assert(p->called_class_name() == "CChild2");
    #endif

    t2::CChild3 c3;
    p = &c3;
    std::cout << "Parent->on CChild3:" << p->called_class_name() << std::endl;
    assert(p->called_class_name() == "CTemplate3");
    std::cout << "CChild3->on CChild3:" << c3.called_class_name() << std::endl;
    assert(c3.called_class_name() == "CTemplate3");
    return 0;
}
int main(int argc, char *argv[])
{
    test_is_base_of(argc, argv);
    test_inherient_and_template(argc, argv);
    return 0;

}
