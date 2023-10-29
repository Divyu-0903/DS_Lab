#include <iostream>
using namespace std;

int binary(int *arr, int size, int x) {
    int start=0;
    int end=size-1;
    while(start<=end){
        int mid=start+((end-start)/2);
        if(arr[mid]==x){
            return mid;
        }else if(arr[mid]>x){
            end=mid-1;
        }else{
            start=mid+1;
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
    cout << binary(arr, n, x);
    delete[] arr; 
}