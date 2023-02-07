#include <iostream>
#include <vector>
#include <limits>
#include <memory>
using namespace std;


class B {
public:
    char* stack;
    int* b;
    B();
    ~B();
};

B::B() {
    stack = new char[9];
    b = new int(9);
}

B::~B() {
    cout << "B desturctor" << endl;
    delete[] stack;
    delete b;
}

class A {
public:
    A();
    ~A();
    std::shared_ptr<B> ptr;
};

A::A () {
    // ptr = make_shared<B>();
}

A::~A () {
    cout << "A destructor" << endl;
}

int main () {
    {
        A* A_ptr = new A;
        A_ptr->ptr = make_shared<B>();
        delete A_ptr;
    }
    cout << "out of scope" << endl;
    return 0;
}
