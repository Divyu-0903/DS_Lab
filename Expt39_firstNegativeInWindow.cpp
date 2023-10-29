#include <iostream>
#include <deque>
#include <vector>

using namespace std;

void firstNegativeInWindow(const vector<int>& arr, int n, int k) {
    deque<int> negIndices;

    for (int i = 0; i < k; ++i) {
        if (arr[i] < 0) {
            negIndices.push_back(i);
        }
    }

    for (int i = k; i < n; ++i) {
        if (!negIndices.empty()) {
            cout << arr[negIndices.front()] << " ";
        } else {
            cout << "0 ";
        }

        while (!negIndices.empty() && negIndices.front() <= i - k) {
            negIndices.pop_front();
        }

        if (arr[i] < 0) {
            negIndices.push_back(i);
        }
    }

    if (!negIndices.empty()) {
        cout << arr[negIndices.front()] << " ";
    } else {
        cout << "0 ";
    }

    cout << endl;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);

    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    firstNegativeInWindow(arr, n, k);

    return 0;
}