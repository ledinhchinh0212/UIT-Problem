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

class List {
private:
    Node *head;
    Node *tail;
public:
    List() {
        this->head = this->tail = nullptr;
    }
    void ThemDau(int data) {
        Node *node = new Node(data);
        if(head == nullptr) {
            head = node;
            tail = node;
        }
        else {
            node->next = head;
            head = node;
        }
    }
    void ThemCuoi(int data) {
        Node *node = new Node(data);
        if(head == nullptr) {
            head = node;
        }
        else {
            tail->next = node;
        }
        tail = node;
    }
    void Menu() {
        cout << "\n1. Them dau\n";
        cout << "2. Them cuoi\n";
        cout << "3. Xuat\n";
        cout << "0. Thoat\n";
    }
    int NhapData() {
        cout << "Nhap data: ";
        int data; cin >> data;
        system("cls");
        return data;
    }
    void NhapMenu() {
        bool loop = true;
        while(loop) {
            Menu();
            int choose;
            cin >> choose;
            if(choose == 0) {
                loop = false;
            }
            else if(choose == 1) {
                int data = NhapData();
                ThemDau(data);
            }
            else if(choose == 2) {
                int data = NhapData();
                ThemCuoi(data);
            }
            else if(choose == 3) {
                system("cls");
                Xuat();
            }
        }
    }
    void Xuat() {
        Node *current = head;
        while(current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
    }
    ~List() {
        if(head != nullptr) {
            while(head != nullptr) {
                Node *current = head;
                head = head->next;
                delete current;
                current = nullptr;
            }
        }
    }
};

int main() {

    List *list = new List();
    list->NhapMenu();

    return 0;
}