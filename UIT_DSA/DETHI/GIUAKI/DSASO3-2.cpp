#include <iostream>

using namespace std;

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void Heapify(int arr[], int i, int N) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    
    if(left < N && arr[left] > arr[largest]) {
        largest = left;
    }

    if(right < N && arr[right] > arr[largest]) {
        largest = right;
    }

    if(largest != i) {
        swap(arr[largest], arr[i]);
        Heapify(arr, largest, N);
    }
}

void HeapSort(int arr[], int n) {
    for(int i = n / 2 - 1; i >= 0; i--) {
        Heapify(arr, i, n);
    }

    for(int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        Heapify(arr, 0, i);
    }
}

void PrintArray(int arr[], int n) {
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
}

int main() {
    int arr[] = {10, 25, 12, 9, 7, 31, 19, 27, 5};
    int n = sizeof(arr)/sizeof(arr[0]);

    HeapSort(arr, n);

    PrintArray(arr, n);

    /*
    b. arr = 10, 25, 12, 9, 7, 31, 19, 27, 5
    ta có thể trình bày thành cây nhị phân hoàn chỉnh như sau
                                    10
                        25                          12
                9               7           31              19
        27              5
    // bước 1: build max heap (đưa giá trị max lên arr[0])
        - i = n / 2 - 1 = 9 / 2 - 1 = 3
            largest = 3, left = 7, right = 8
            27 > 9 -> largest = 7
            largest đã thay đổi -> swap -> 
            arr = 10, 25, 12, 27, 7, 31, 19, 9, 5
            heapify(arr, 7, N)
            + largest = 7, left = 15, right = 16
            left > N <-> 15 >= 9 -> return
        - i = 2
            largest = 2, left = 5, right = 6
            31 > 12 -> largest = 5
            largest đã thay đổi -> swap ->
            arr = 10, 25, 31, 27, 7, 12, 19, 9, 5
            heapify(arr, 5, N)
            + largest = 5, left = 11, right = 12
            left > N <-> 11 >= 9 -> return
        - i = 1
            largest = 1, left = 3, right = 4
            27 > 25 -> largest = 3
            largest đã thay đổi -> swap ->
            arr = 10, 27, 31, 25, 7, 12, 19, 9, 5
            heapify(arr, 3, N)
            + largest = 3, left = 7, right = 8
            25 > 9 && 25 > 5 -> return
        - i = 0
            largest = 0, left = 1, right = 2
            31 > 10 -> largest = 2
            largest đã thay đổi -> swap ->
            arr = 31, 27, 19, 25, 7, 12, 10, 9, 5
    // bước 2: swap arr[0] với phần tử cuối mảng và tiếp tục build max heap đưa phần tử max lên đầu 
                và duyệt dần theo n - i (i <= 1 và i giảm dần)
        arr = 31, 27, 19, 25, 7, 12, 10, 9, 5
        - với i = n - 1 = 8
            arr = 5, 9, 10, 12, 7, 25, 19, 27, 31 (duyệt phần tử ngược)
            swap 5 với 31 -> 
            arr = 31, 9, 10, 12, 7, 25, 19, 27, 5
            ta giả sử có một stack và và đưa phần tử mà vòng lặp không xét nữa vào stack
            stack(31)
            sau đó heapify(arr, 0, 8) 
            arr = 9, 10, 12, 7, 25, 19, 27, 5
            ta biểu diễn thành cây nhị phân hoàn chỉnh
                                            9
                                    10              12
                        7              25       19         27
                5
            sau khi heapify:
                                            12
                                    10              9
                        7              25       19         27
                5
            tương đương với
                arr = 27, 25, 19, 9, 7, 12, 10, 5
        - với i = 7
            arr = 5, 10, 12, 7, 9, 19, 25, 27
            swap với phần tử cuối vào đẩy vào stack
            arr = 27, 25, 19, 9, 7, 12, 10, 5
            stack(27, 31)
            heapify(arr, 0, 7)
            arr = 5, 10, 12, 7, 9, 19, 25
            ta biẻu diễn thành cây nhị phân hoàn chỉnh
                                            5
                                    10             12
                            7             9      19         25                   
            sau khi heapify:
                                            12
                                    10               25
                            7             9      19         5        
    */

    return 0;
}