#include <iostream>

using namespace std;

class LinkedListNode {
public:
    int x;
    LinkedListNode *next;

    LinkedListNode(int x) {
        this->x = x;
        this->next = nullptr;
    }
};

class LinkedList {
private:
    LinkedListNode* head;
    LinkedListNode* tail;
public:
    LinkedList() {
        this->head = nullptr;
        this->tail = nullptr;
    }

    void PrintList() {
        LinkedListNode* node = head;
        while(node != nullptr) {
            cout << node->x << "\n";
            node = node->next;
        }
    }

    void AddNode(int x) {
        LinkedListNode* temp = new LinkedListNode(x);
        if(head == nullptr) {
            head = temp;
            tail = temp;
        }
        else {
            tail->next = temp;
            tail = temp;
        }
    }    

    void DeleteNode(int x) {
        LinkedListNode *prev = nullptr;
        LinkedListNode *curr = head;

        while(curr != nullptr) {
            if(curr->x == x) {
                if(prev == nullptr) {
                    head = curr->next;
                }
                else {
                    prev->next = curr->next;
                }
                if(curr == tail) {
                    tail = prev;
                }
            }
            prev = curr;
            curr = curr->next;
        }
    }
};

int main() {

    LinkedList* list = new LinkedList();

    list->AddNode(1);
    list->AddNode(2);
    list->AddNode(3);
    list->AddNode(4);
    list->AddNode(5);
    list->AddNode(6);
    list->AddNode(5);

    int x; cin >> x;
    list->DeleteNode(x);
    list->PrintList();

    delete list;

    return 0;
}