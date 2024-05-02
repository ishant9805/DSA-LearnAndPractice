#include<bits/stdc++.h>

using namespace std;

void insert(stack<int> &st, int x) {
    if (st.size() == 0) {
        st.push(x);
        return;
    }
    if (x < st.top()) {
        int a = st.top();
        st.pop();
        insert(st, x);
        st.push(a);
    } else {
        st.push(x);
    }
}

stack<int> sortStack(stack<int> &s)
{
    if (s.size() == 0 || s.size() == 1) return s;
    int a = s.top();
    s.pop();
    s = sortStack(s);
    insert(s, a);
    return s;
}

int main() {
    cout << "Starting Program" << endl;
    stack<int> st;
    st.push(2);
    st.push(4);
    st.push(3);
    st.push(1);
    st = sortStack(st);
    int sz = st.size();
    for (int i = 0; i < sz; i++) {
        cout << st.top() << endl;
        st.pop();
    }
    return 0;
}