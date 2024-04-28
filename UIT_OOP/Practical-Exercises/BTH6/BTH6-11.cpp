#include <iostream>

using namespace std;

class Program {
public:
    Program();
    ~Program();
};

Program::Program() {
    cout << "Entering the Hello program saying..\n";
}

Program::~Program() {
    cout << "Then exiting...\n";
}

Program program;

main(){
	cout << "Hello, world.\n";
}
