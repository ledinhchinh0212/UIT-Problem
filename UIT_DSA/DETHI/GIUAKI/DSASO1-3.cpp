#include <iostream>

using namespace std;

void PrintMap(int arr[], const int n) {
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
}

void Merge(int arr[], int a[], int &n, int b[], int &m) {
    int i = 0, j = m - 1, index = 0;
    while(i < n && j >= 0) {
        if(a[i] >= b[j]) {
            arr[index] = a[i];
            index++; i++;
        }
        else {
            arr[index] = b[j];
            index++; j--;
        }
    }    

    while(i < n) {
        arr[index++] = a[i++];
    }

    while(j >= 0) {
        arr[index++] = b[j--];
    }
}

int main() {

    int a[] = {7, 5, 3, 2, 1, 0};
    int b[] = {-2, 1, 4, 6, 7, 8, 10};
    int n = sizeof(a)/sizeof(a[0]);
    int m = sizeof(b)/sizeof(b[0]);

    const int p = n + m;
    int c[p];
    
    Merge(c, a, n, b, m);
    PrintMap(c, p);

    // dpt: O(n + m)
    return 0;
}