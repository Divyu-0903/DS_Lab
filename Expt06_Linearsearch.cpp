#include <iostream>
using namespace std;

int linear(int *arr, int size, int x) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == x) {
            return i;
        }
    }
    return -1;
}

int main() {
    int n;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout<<"Enter element to be searched : ";
    int x;
    cin >> x;
    cout<<"Index of element is : " <<endl;
    cout << linear(arr, n, x);
    delete[] arr; 
}