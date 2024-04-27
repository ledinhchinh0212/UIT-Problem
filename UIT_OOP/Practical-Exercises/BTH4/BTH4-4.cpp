#include <iostream>
#include <exception>
#include <climits>
#include <vector>
#include <stdexcept>
#include <cmath>

using namespace std;

template<typename type>
class Stack {
private:
    type *stack_Array_Class;
    int stack_Size_Class;
public:
    Stack();
    ~Stack();
    type top();
    void push(type data_Into_Stack);
    bool empty() const;
    void pop();
};

template<typename type>
Stack<type>::Stack() {
    this->stack_Size_Class = 0;
    this->stack_Array_Class = new type[this->stack_Size_Class + 1];
}

template<typename type>
Stack<type>::~Stack() {
    if(this->stack_Array_Class != nullptr) {
        delete []this->stack_Array_Class;
    }
}

template<typename type>
type Stack<type>::top() {
    if(this->stack_Size_Class == 0) {
        throw runtime_error("access the empty element");
    }
    return this->stack_Array_Class[this->stack_Size_Class - 1];
}

template<typename type>
void Stack<type>::push(type data_Into_Stack) {
    type *copy_Stack_Array_Stack = new type[this->stack_Size_Class + 1];
    for(int i = 0; i < this->stack_Size_Class; i++) {
        copy_Stack_Array_Stack[i] = this->stack_Array_Class[i];
    }
    copy_Stack_Array_Stack[this->stack_Size_Class] = data_Into_Stack;
    delete []this->stack_Array_Class;
    this->stack_Array_Class = nullptr;
    this->stack_Array_Class = copy_Stack_Array_Stack;
    this->stack_Size_Class++;
}

template<typename type>
bool Stack<type>::empty() const {
    return this->stack_Size_Class == 0;
}

template<typename type>
void Stack<type>::pop() {
    if(this->stack_Size_Class == 0) {
        //cout << "Invalid\n";
        throw runtime_error("access the empty element");
    }
    else {
        type *copy_Stack_Array_Stack = new type[this->stack_Size_Class - 1];
        this->stack_Size_Class--;
        for(int i = 0; i < this->stack_Size_Class; i++) {
            copy_Stack_Array_Stack[i] = this->stack_Array_Class[i];
        }
        delete []this->stack_Array_Class;
        this->stack_Array_Class = nullptr;
        this->stack_Array_Class = copy_Stack_Array_Stack;
    }
}

Stack<int> heNhiPhan(int n) {
    Stack<int> stack;
    while(n > 0) {
        int x = n % 2;
        n = n / 2;
        stack.push(x);
    }
    return stack;
}

Stack<int> heBatPhan(int n) {
    Stack<int> stack;
    while(n > 0) {
        int x = n % 8;
        n = n / 8;
        stack.push(x);
    }
    return stack;
}

char heThapLucPhanTuongUng(const int &n) {
    char origin = 'A';
    if(n >= 10) {
        return origin + n - 10;
    }
    return n + '0';
}

Stack<char> heThapLucPhan(int n) {
    Stack<char> stack;
    while(n > 0) {
        int x = n % 16;
        char result = heThapLucPhanTuongUng(x);
        stack.push(result);
        n = n / 16;
    }
    return stack;
}

template<typename type>
void print(Stack<type> stack) {
    while(!stack.empty()) {
        cout << stack.top();
        stack.pop();
    }
}

int main() {

    int n; cin >> n;

    cout << "He nhi phan: ";
    print<int>(heNhiPhan(n));
    cout << "\nHe bat phan: ";
    print<int>(heBatPhan(n));
    cout << "\nHe thap luc phan: ";
    print<char>(heThapLucPhan(n));


    return 0;
}