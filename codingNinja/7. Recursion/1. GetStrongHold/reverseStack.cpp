#include<bits/stdc++.h>

using namespace std;

void insertAtBottom(stack<int> &st, int x) {
    if (st.size() == 0) {
        st.push(x);
        return;
    }
    int a = st.top();
    st.pop();
    insertAtBottom(st, x);
    st.push(a);
    return;
}

void reverseStack(stack<int> &stack) {
    if (stack.size() == 0 || stack.size() == 1) return;
    int x = stack.top();
    stack.pop();
    reverseStack(stack);
    insertAtBottom(stack, x);
}

int main() {
    cout << "Starting Program" << endl;
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    reverseStack(st);
    cout << "Printing reverse of stack." << endl;
    int sz = st.size();
    for (int i = 0; i < sz; i++) {
        cout << st.top() << endl;
        st.pop();
    }
    return 0;
}