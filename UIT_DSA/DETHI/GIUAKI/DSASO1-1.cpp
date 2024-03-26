#include <iostream>

using namespace std;

int swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void BubbleSort(int arr[], int n) {
    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < n - i - 1; j++) {
            if(arr[j] < arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

int main() {
// a
    int arr[] = {3, 8 , 4, 9, 1, 2};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    BubbleSort(arr, n);

    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
// b
    /*  mục tiêu: nếu phần tử trước bé hơn phần từ sau thì ta sẽ hoán đổi vị trị để đưa phần tử lớn lên trước
        - i = 0, i duyệt qua j từ 0 đến n - i - 2 = 6 - 0 - 2 = 4
        + so sánh cho đến ghi gặp 3 < 8 sau đó swap
        + 8 3 4 9 1 2
        + tiếp tục 3 < 4
        + 8 4 3 9 1 2
        + tiếp tục 3 < 9
        + 8 4 9 3 1 2
        + tiếp tục 1 < 2
        + 8 4 9 3 2 1
        - i = 1, i duyệt qua j từ 0 đến 3
        + so sánh cho đến khi gặp 4 < 9
        + 8 9 4 3 2 1
        - i = 2, i duyệt qua j từ 0 đến 2
        + so sánh cho đnế khi gặp 8 < 9
        + 9 8 4 3 2 1
        - tiếp tục duyệt hết với điều kiện i < n - 1 = 6 - 1 = 5

    */
    return 0;
}