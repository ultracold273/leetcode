/**
 * LeetCode Q155 - Min Stack
 * Design a stack that supports push, pop, top, and retrieving the 
 * minimum element in constant time.
 *
 *   push(x) -- Push element x onto stack.
 *   pop() -- Removes the element on top of the stack.
 *   top() -- Get the top element.
 *   getMin() -- Retrieve the minimum element in the stack.
 *
 * Example:
 *
 *   MinStack minStack = new MinStack();
 *   minStack.push(-2);
 *   minStack.push(0);
 *   minStack.push(-3);
 *   minStack.getMin();   --> Returns -3.
 *   minStack.pop();
 *   minStack.top();      --> Returns 0.
 *   minStack.getMin();   --> Returns -2.
 */

#include <iostream>
#include <stack>
using namespace std;

class MinStack {
public:
    /** initialize your data structure here. */
    stack<int> st;
    stack<int> minSt;

    MinStack() {
    }

    void push(int x) {
        st.push(x);
        if (minSt.empty() || x <= minSt.top()) minSt.push(x);
    }

    void pop() {
        int x = st.top();
        if (x == minSt.top()) minSt.pop();
        st.pop();
    }

    int top() {
        return st.top();
    }

    int getMin() {
        return minSt.top();
    }
};

int main() {
    MinStack * obj = new MinStack();
    obj->push(-2);
    obj->push(0);
    obj->push(-3);
    cout << obj->getMin() << endl;
    obj->pop();
    cout << obj->top() << endl;
    cout << obj->getMin() << endl;
}
