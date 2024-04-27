#include <iostream>
#include <stdexcept>
#include <exception>
#include <string>

using namespace std;

// default values {Integer}
class Queue {
private:
    int *queue_Array_Class;
    int queue_Size_Class;
public:
    Queue();
    ~Queue();
    int front();
    int back();
    void pop();
    void push(int data_Into_Queue);
    bool empty();
    int size();
    void invalidAccess();
};

Queue::Queue() {
    this->queue_Size_Class = 0;
    this->queue_Array_Class = new int[this->queue_Size_Class + 1];
}

Queue::~Queue() {
    if(this->queue_Array_Class != nullptr) {
        delete []this->queue_Array_Class;
        this->queue_Array_Class = nullptr;
    }
    this->queue_Size_Class = 0;
}

void Queue::invalidAccess() {
    if(this->queue_Size_Class == 0) {
        throw runtime_error("Access to empty element");
    }
}

int Queue::front() {
    invalidAccess();
    return this->queue_Array_Class[0];
}

int Queue::back() {
    invalidAccess();
    return this->queue_Array_Class[this->queue_Size_Class - 1];
}

void Queue::pop() {
    invalidAccess();
    int *copy_Queue_Array = new int[this->queue_Size_Class - 1];
    int index_Start = 1;
    for(int i = 0; i < this->queue_Size_Class - 1; i++) {
        copy_Queue_Array[i] = this->queue_Array_Class[index_Start++];
    }
    this->queue_Size_Class--;
    delete []this->queue_Array_Class;
    this->queue_Array_Class = copy_Queue_Array;
}

void Queue::push(int data_Into_Queue) {
    int *copy_Queue_Array = new int[this->queue_Size_Class + 1];
    for(int i = 0; i < this->queue_Size_Class; i++) {
        copy_Queue_Array[i] = this->queue_Array_Class[i];
    }
    copy_Queue_Array[this->queue_Size_Class] = data_Into_Queue;
    delete []this->queue_Array_Class;
    this->queue_Array_Class = copy_Queue_Array;
    this->queue_Size_Class++;
}

bool Queue::empty() {
    return this->queue_Size_Class == 0;
}

int Queue::size() {
    return this->queue_Size_Class;
}

int main() {

    Queue q;
    q.push(4);
    q.push(5);
    q.push(6);
    q.push(7);
    q.push(8);
    q.push(9);
    q.push(10);
    q.push(11);
    q.push(12);
    q.push(13);
    cout << "Not empty: " << q.size() << "\n";
    while(!q.empty()) {
        cout << q.front() << "\n";
        q.pop();
    }
    cout << "Empty: " << q.size() << "\n";
    

    return 0;
}