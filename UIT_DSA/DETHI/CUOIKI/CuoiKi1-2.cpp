#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node *next;
    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

class NodeList {
private:
    Node *head;
    Node *tail;
public:
    void AddFirstNodeList(int data) {
        Node *node = new Node(data);
        if(head == nullptr) {
            head = node;
        }
        else {
            node->next = head;
            head = node;
        }
        tail = node;
    }
    int firstElement() {
        return head->data;
    }
    int findTheElement(int x) {
        Node *current = head;
        int count = 0;
        while(current != nullptr && current->data != x) {
            count++;
            current = current->next;
        }
        if(current == nullptr) {
            return -1;
        }
        return count;
    }
    ~NodeList() {
        while(head != nullptr) {
            Node *temp = head;
            head = head->next;
            delete temp;
            temp == nullptr;
        }
    }
};

int main() {

    return 0;
}