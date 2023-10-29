#include <iostream>
using namespace std;

int Floor(const int arr[], int size, int target) {
    int left = -1;
    int right = size - 1;
    int floorValue = -1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) {
            return arr[mid];
        } else if (arr[mid] < target) {
            floorValue = arr[mid];
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return floorValue;
}

int Ceil(const int arr[], int size, int target) {
    int left = 0;
    int right = size - 1;
    int ceilValue = -1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) {
            return arr[mid];
        } else if (arr[mid] > target) {
            ceilValue = arr[mid];
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    return ceilValue;
}

int Peak(const int arr[], int size) {
    int left = 0;
    int right = size - 1;

    while (left < right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] > arr[mid + 1]) {
            return arr[mid];
        }

        if (arr[mid] < arr[mid + 1]) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }

    return arr[left];
}

int findMin(const int arr[], int size) {
    int left = 0;
    int right = size - 1;

    while (left < right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] > arr[right]) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }

    return arr[left];
}

int main() {
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;

    int arr[size];
    cout << "Enter " << size << " elements: ";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    int target;
    cout << "Enter the target value: ";
    cin >> target;

    int floorValue = Floor(arr, size, target);
    int ceilValue = Ceil(arr, size, target);
    int peakValue = Peak(arr, size);
    int minInRotatedArray = findMin(arr, size);

    cout << "Floor value of " << target << " is: " << floorValue << endl;
    cout << "Ceil value of " << target << " is: " << ceilValue << endl;
    cout << "Peak value in the array is: " << peakValue << endl;
    cout << "Minimum value in the rotated sorted array is: " << minInRotatedArray << endl;

    return 0;
}