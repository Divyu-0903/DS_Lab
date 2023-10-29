#include <iostream>
#include <stack>

using namespace std;

class MinStack {
    stack<int> mainStack;
    stack<int> minStack;

public:
    void push(int x) {
        mainStack.push(x);

        if (minStack.empty() || x <= getMin()) {
            minStack.push(x);
        }
    }

    void pop() {
        if (mainStack.top() == getMin()) {
            minStack.pop();
        }
        mainStack.pop();
    }

    int top() {
        return mainStack.top();
    }

    int getMin() {
        return minStack.top();
    }
};

int main() {
    MinStack minStack;

    minStack.push(3);
    minStack.push(5);
    minStack.push(2);
    minStack.push(1);

    cout << "Minimum Element: " << minStack.getMin() << endl;

    minStack.pop();
    cout << "Minimum Element: " << minStack.getMin() << endl;

    return 0;
}
