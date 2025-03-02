#include <iostream>

class A
{
public:
    A(int) { std::cout << "A::A(int)\n"; }
    A(int, int) { std::cout << "A::A(int, int)\n"; }
    A(const A&) { std::cout << "A::A(const A&)\n"; }
    operator bool() const { std::cout << "A::bool()\n"; return true; }
};

class B
{
public:
    explicit B(int) { std::cout << "B::B(int)\n"; }
    explicit B(int, int) { std::cout << "B::B(int, int)\n"; }
    explicit operator bool() const { std::cout << "B::bool()\n"; return true; }
};

int main()
{
    A a1 = 1;         
    A a2(2);          
    A a3{ 4, 5 };     
    A a4 = { 4, 5 };  
    A a5 = (A)1;       

    if (a1)             
        bool na1 = a1;      
    bool na2 = static_cast<bool>(a1); 

    // B b1 = 1;    
    B b2(2);          
    B b3{ 4, 5 };      
    B b5{ static_cast<B>(1) }; 

    if (b2)             
    bool nb2 = static_cast<bool>(b2); 
}
