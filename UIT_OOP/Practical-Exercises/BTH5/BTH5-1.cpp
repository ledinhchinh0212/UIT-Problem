#include <iostream>
#include <string.h>

using namespace std;

class String {
private:
    int size;
    char *stringType;
public:
    String();
    ~String();
    int length() const;
    void append(const String &string);
    void reverse();
    friend istream &operator>>(istream &in, String &string);
    friend ostream &operator<<(ostream &out, const String &string);
};

String::String() {
    this->size = 0;
    this->stringType = new char[this->size + 1];
}

String::~String() {
    if(this->stringType != nullptr) {
        delete []this->stringType;
        this->stringType = nullptr;
    }
    this->size = 0;
}

int String::length() const {
    return this->size;
}

void String::append(const String &string) {
    int sizeHere = this->length();
    int sizeOthers = string.length();
    char *copy_String = new char[sizeHere + sizeOthers + 1];
    for(int i = 0; i < sizeHere; i++) {
        copy_String[i] = this->stringType[i];
    }
    int index = 0;
    for(int i = sizeHere; i < sizeOthers; i++) {
        copy_String[i] = string.stringType[index++];
    }
    if(this->stringType != nullptr) {
        delete []this->stringType;
    }
    this->stringType = nullptr;
    this->stringType = copy_String;
    this->size = sizeHere + sizeOthers;
}

istream &operator>>(istream &in, String &string) {
    const int realSize = 1000;
    char buffer[realSize];
    in.getline(buffer, realSize);
    delete []string.stringType;
    string.size = strlen(buffer);
    string.stringType = new char[string.size + 1];
    strcpy(string.stringType, buffer);
    return in;
}

ostream &operator<<(ostream &out, const String &string) {
    cout << string.stringType;
    return out;
}

void String::reverse() {
    int len = this->length();
    for(int i = 0; i < len / 2; i++) {
        char temp = this->stringType[i];
        this->stringType[i] = this->stringType[len - i - 1];
        this->stringType[len - i - 1] = temp;
    }
}

int main() {

    String a, b;
    cin >> a;
    a.reverse();
    cout << a;

    return 0;
}