#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    if (n < 0) {
        cout << "Underflow!" << endl;
        return 1;
    }

    int *arr = new int[n];

    for (int i = 0; i < n; i++) {
        cout << "Enter element " << i << ": ";
        cin >> arr[i];
    }

    int choice;
    cout << "Choose an operation:"<<endl;
    cout << "1. Insert an element"<<endl;
    cout << "2. Delete an element"<<endl;
    cin >> choice;

    if (choice == 1) { 
        int index;
        cout << "Enter index: ";
        cin >> index;

        int element;
        cout << "Enter Element: ";
        cin >> element;

        if (index < 0) {
            cout << "Underflow!" << endl;
        } else if (index > n) {
            cout << "Overflow!" << endl;
        } else {
            for (int i = n; i > index; i--) {
                arr[i] = arr[i - 1];
            }

            arr[index] = element;
            n++;

            cout << "Updated Array: ";
            for (int i = 0; i < n; i++) {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
    } else if (choice == 2) { 
        int index;
        cout << "Enter index to delete: ";
        cin >> index;

        if (index < 0) {
            cout << "Underflow!" << endl;
        } else if (index >= n) {
            cout << "Overflow!" << endl;
        } else {
            for (int i = index; i < n - 1; i++) {
                arr[i] = arr[i + 1];
            }

            n--;

            cout << "Updated Array: ";
            for (int i = 0; i < n; i++) {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
    } else {
        cout << "Invalid choice!" << endl;
    }

    delete[] arr;
    return 0;
}
