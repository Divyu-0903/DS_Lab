#include <iostream>
using namespace std;
const int MAX_SIZE = 100; 

int main() {
    int arr[MAX_SIZE];
    int n, choice, element, size = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        size++;
    }
    cout<<"ENTER CHOICE : "<<endl;
    cout<<"1.Insert at end"<<endl;
    cout<<"2.Delete at end"<<endl;
    cin >> choice;

    if (choice == 1) {
        cout<<"Enter element to be inserted : ";
        cin >> element;
        if (size < MAX_SIZE) {
            arr[size] = element;
            size++;
        } else {
            cout << "Overflow!" << endl;
        }
    } else if (choice == 2) {
        if (size > 0) {
            size--;
        } else {
            cout << "Underflow!" << endl;
        }
    }

    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}