#include <stack>
using namespace std;

// Auxiliary stack to store minimum elements
stack<int> minStack;

void push(stack<int>& s, int a) {
    s.push(a);

    // Push into minStack if empty or new element <= current min
    if (minStack.empty() || a <= minStack.top()) {
        minStack.push(a);
    }
}

bool isFull(stack<int>& s, int n) {
    return (s.size() == n);
}

bool isEmpty(stack<int>& s) {
    return s.empty();
}

int pop(stack<int>& s) {
    if (s.empty())
        return -1;

    int topElement = s.top();
    s.pop();

    // If popped element is minimum, pop from minStack also
    if (!minStack.empty() && topElement == minStack.top()) {
        minStack.pop();
    }

    return topElement;
}

int getMin(stack<int>& s) {
    if (minStack.empty())
        return -1;

    return minStack.top();
}
