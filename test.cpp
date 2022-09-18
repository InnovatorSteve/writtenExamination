#include <iostream> 
class Test { public:
Test() = default;
~Test() { std::cout << "~Test"
                    << std::endl; }
void print1() { std::cout << "print1"
                          << std::endl; }
void print2() { std::cout << "print2"  //virtual 
                                  << std::endl; }
}
;
int main()
{
    {
        Test *t = nullptr;
        t->print1();
        t->print2();
    }
    std::cout << "I'm OK"
              << std::endl;
    return 0;
}