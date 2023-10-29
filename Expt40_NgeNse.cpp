#include <iostream>
#include <stack>
#include <vector>

using namespace std;

vector<int> nextGreaterToRight(const vector<int>& arr, int n) {
    vector<int> result(n, -1);
    stack<int> st;

    for (int i = 0; i < n; ++i) {
        while (!st.empty() && arr[i] > arr[st.top()]) {
            result[st.top()] = arr[i];
            st.pop();
        }
        st.push(i);
    }

    return result;
}

vector<int> nextGreaterToLeft(const vector<int>& arr, int n) {
    vector<int> result(n, -1);
    stack<int> st;

    for (int i = n - 1; i >= 0; --i) {
        while (!st.empty() && arr[i] > arr[st.top()]) {
            result[st.top()] = arr[i];
            st.pop();
        }
        st.push(i);
    }

    return result;
}

vector<int> nearestSmallerToLeft(const vector<int>& arr, int n) {
    vector<int> result(n, -1);
    stack<int> st;

    for (int i = 0; i < n; ++i) {
        while (!st.empty() && arr[i] < arr[st.top()]) {
            result[i] = arr[st.top()];
            st.pop();
        }
        st.push(i);
    }

    return result;
}

vector<int> nextSmallerToRight(const vector<int>& arr, int n) {
    vector<int> result(n, -1);
    stack<int> st;

    for (int i = n - 1; i >= 0; --i) {
        while (!st.empty() && arr[i] < arr[st.top()]) {
            result[st.top()] = arr[i];
            st.pop();
        }
        st.push(i);
    }

    return result;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);

    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    vector<int> ngr = nextGreaterToRight(arr, n);
    vector<int> ngl = nextGreaterToLeft(arr, n);
    vector<int> nsl = nearestSmallerToLeft(arr, n);
    vector<int> nsr = nextSmallerToRight(arr, n);

    cout << "Next Greater to Right: ";
    for (int i = 0; i < n; ++i) {
        cout << ngr[i] << " ";
    }
    cout << endl;

    cout << "Next Greater to Left: ";
    for (int i = 0; i < n; ++i) {
        cout << ngl[i] << " ";
    }
    cout << endl;

    cout << "Nearest Smaller to Left: ";
    for (int i = 0; i < n; ++i) {
        cout << nsl[i] << " ";
    }
    cout << endl;

    cout << "Next Smaller to Right: ";
    for (int i = 0; i < n; ++i) {
        cout << nsr[i] << " ";
    }
    cout << endl;

    return 0;
}