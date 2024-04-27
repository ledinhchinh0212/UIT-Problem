#include <iostream>
#include <exception>
#include <climits>
#include <vector>
#include <stdexcept>
#include <cmath>

using namespace std;

class Stack {
private:
    int *stack_Array_Class;
    int stack_Size_Class;
public:
    Stack();
    ~Stack();
    int top();
    void push(int data_Into_Stack);
    bool empty() const;
    void pop();
};

Stack::Stack() {
    this->stack_Size_Class = 0;
    this->stack_Array_Class = new int[this->stack_Size_Class + 1];
}

Stack::~Stack() {
    if(this->stack_Array_Class != nullptr) {
        delete []this->stack_Array_Class;
    }
}

int Stack::top() {
    if(this->stack_Size_Class == 0) {
        return INT_MAX;
    }
    return this->stack_Array_Class[this->stack_Size_Class - 1];
}

void Stack::push(int data_Into_Stack) {
    int *copy_Stack_Array_Stack = new int[this->stack_Size_Class + 1];
    for(int i = 0; i < this->stack_Size_Class; i++) {
        copy_Stack_Array_Stack[i] = this->stack_Array_Class[i];
    }
    copy_Stack_Array_Stack[this->stack_Size_Class] = data_Into_Stack;
    delete []this->stack_Array_Class;
    this->stack_Array_Class = nullptr;
    this->stack_Array_Class = copy_Stack_Array_Stack;
    this->stack_Size_Class++;
}

bool Stack::empty() const {
    return this->stack_Size_Class == 0;
}

void Stack::pop() {
    if(this->stack_Size_Class == 0) {
        cout << "Invalid\n";
        throw runtime_error("out of size Stack");
    }
    else {
        int *copy_Stack_Array_Stack = new int[this->stack_Size_Class - 1];
        this->stack_Size_Class--;
        for(int i = 0; i < this->stack_Size_Class; i++) {
            copy_Stack_Array_Stack[i] = this->stack_Array_Class[i];
        }
        delete []this->stack_Array_Class;
        this->stack_Array_Class = nullptr;
        this->stack_Array_Class = copy_Stack_Array_Stack;
    }
}

bool isPrime(int n) {
    for(int i = 2; i <= sqrt(n); i++) {
        if(n % i == 0) {
            return false;
        }
    }
    return n > 1;
}

int main() {

    int n;
    cin >> n;
    int temp = n;
    int i = 2;
    Stack stack;
    while(temp > 1) {
        if(isPrime(i) && temp % i == 0) {
            temp = temp / i;
            stack.push(i);
        }
        else {
            i++;
        }
    }
    cout << n << " = ";
    while(true) {
        cout << stack.top();
        stack.pop();
        if(!stack.empty()) {
            cout << " * ";
        }
        else break;
    }
    return 0;
}