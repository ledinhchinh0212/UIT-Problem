#include <iostream>
#include <vector>

using namespace std;

void Merge(int arr[], int left, int mid , int right) {
    vector<int> x(arr + left, arr + mid + 1);
    vector<int> y(arr + mid + 1, arr + right + 1);
    int i = 0, j = 0, index = left;
    while(i < x.size() && j < y.size()) {
        if(x[i] <= y[j]) {
            arr[index] = x[i];
            index++; i++;
        }
        else {
            arr[index] = y[j];
            index++; j++;
        }
    }

    while(i < x.size()) {
        arr[index] = x[i];
        index++; i++;
    }
    
    while(j < y.size()) {
        arr[index] = y[j];
        index++; j++;
    }
}

void MergeSort(int arr[], int left, int right) {
    if(left >= right) {
        return;
    }
    int mid = (left + right) / 2;
    MergeSort(arr, left, mid);
    MergeSort(arr, mid + 1, right);
    Merge(arr, left, mid, right);
}

void PrintArray(int a[], int n) {
    for(int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
}

int main() {
    
    int arr[] = {27, 32, 12, 52, 39, 76, 18, 4, 25, 69, 10, 8, 16};
    int n = sizeof(arr)/sizeof(arr[0]);

    MergeSort(arr, 0, n - 1);

    PrintArray(arr, n);

    /*
        a. Một thuật toán đã từng học là MergeSort
        b. Giải tay từng bước thuật toán thay đổi:
        n = 13
        - stack 1:
            0 < n - 1 = 12:
            mid = 12 / 2 = 6
            left -> mid: 27, 32, 12, 52, 39, 76, 18
        - stack 2:       
            0 < 6:
            mid = 6 / 2 = 3
            left -> mid: 27, 32, 12, 52
        - stack 3:
            0 < 3:
            mid = 3 / 2 = 1
            left -> mid: 27, 32
        - stack 4:
            0 < 1:
            mid = 1 / 2 = 0
            left -> mid: 27
        - stack 5:
            0 = 0 (left = right)
        - return stack 4:
            mid + 1 -> right: 32
        - merge in stack 4:
            merge(0, 0, 1)
            arr = 27, 32, 12, 52, 39, 76, 18, 4, 25, 69, 10, 8, 16
        - return stack 3:
            mid + 1 -> right: 12, 52
            2 < 3:
            mid = 5 / 2 = 2
            left -> mid = 12
        - stack 4:
            2 = 2 (left = right)
        - return stack 3:
            mid + 1 -> right = 52
        - stack 4:
            3 = 3 (left = right)
        - return stack 3:
            merge(2, 2, 3)
            arr = 27, 32, 12, 52, 39, 76, 18, 4, 25, 69, 10, 8, 16
        - return stack 2:
            merge(0, 1, 3)
            arr = 12, 27, 32, 52, 39, 76, 18, 4, 25, 69, 10, 8, 16
        ..
        arr = 4 8 10 12 16 18 25 27 32 39 52 69 76
        apply divde and comquer
        c. Thuật toán trên có độ phức tạp O(nlog(n))
        nên dễ dàng xử lí những bài toán có số lượng phần tử lớn,
        với số lượng phần tử ít thì ta cũng không cân nhắc sử dụng thuật toán này
        vì nó khá mất thời gian để khởi tạo MergeSort trong khi đó ta có thể dùng
        Bubble Sort, InsertSort..
        d.
        Thuật toán trên có rất nhiều cách để cải thiện:
        - ta có thể sắp xếp 3 biến x, y, z theo thứ tự nhất định, thậm chí là nhiều  biến hơn
        - ta có thể dùng con trỏ hàm để điều hướng sort tuỳ ý tăng và giảm dần
    */

    return 0;
}