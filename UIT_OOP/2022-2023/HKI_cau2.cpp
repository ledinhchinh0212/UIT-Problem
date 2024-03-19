#include <iostream>

using namespace std;

class IntArr {
private:
    int count; //tổng số lượng phần tử có trong values
    int * values; //mảng các số nguyên đang có trong đối tượng hiện tại
public:
    IntArr(){
        this->count = 0;
    }

    ~IntArr() {
        delete []values;
    }

    IntArr(int count, int x = 0) {
        this->count = count;
        values = new int[count];

        for(int i = 0; i < count; i++) {
            values[i] = x;
        }
    }

    IntArr concat(IntArr &arr) {
        int newsize = arr.count + this->count;
        IntArr IArr;
        IArr.count = newsize;

        IArr.values = new int[newsize];

        for(int i = 0; i < this->count; i++) {
            IArr.values[i] = this->values[i];
        }
        int index = 0;
        for(int i = this->count; i < newsize; i++) {
            IArr.values[i] = arr.values[index++];
        }
        
        return IArr;
    }

    void push(int x) {
        int size = this->count + 1;
        int *arr = new int[size];

        for(int i = 0; i < this->count; i++) {
            arr[i] = this->values[i];
        }

        arr[this->count] = x;

        delete []this->values;

        this->values = arr;
        this->count = size;
    }


    friend istream &operator>>(istream &in, IntArr &intArr) {
        if(intArr.values != nullptr) {
            delete []intArr.values;
            intArr.values = nullptr;
            intArr.count = 0;
        }
        if(intArr.values == nullptr) {
            in >> intArr.count;
            for(int i = 0; i < intArr.count; i++) {
                in >> intArr.values[i];
            }
        }

        return in;
    }

    friend ostream &operator<<(ostream &out,const IntArr &IntArr) {
        for(int i = 0; i < IntArr.count; i++) {
            out << IntArr.values[i] << " ";
        }
        return out;
    }
};
int main() {
    IntArr l1;//tạo mảng không chứa bất kì phần tử nào
    IntArr l2(3,2);// tạo một mảng với 3 phần tử, tất cả phần tử đều có giá trị là 2
    IntArr l3(2);//tạo một mảng với 2 phần tử, tất cả phần tử đều có giá trị là 0
    IntArr l4 = l2.concat(l3);//tạo ra một IntArr mới có nội dung là kết quả của việc nối các
    //phần tử l3 vào cuối các phần tử của l2 theo thứ tự
    l2.push(3);//thêm số 3 vào cuối danh sách trong đối tượng l2
    cin >> l2;//Xoá các giá trị hiện có trong l2 và cho phép người dùng nhập số lượng phần tử
    //mới và giá trị các phần tử mới vào l2 (cần xoá các vùng nhớ không sử dụng nếu có)
    cout << l2 << "\n";//in ra các số nguyên có trong danh sách
    //Khi vượt quá phạm vi sử dụng cần huỷ tất cả các vùng nhớ được cấp phát cho các values
    //của IntArr
    cout << l4;
    return 0;
}