#include<bits/stdc++.h>

using namespace std;

class Node
{
    public:
        int data;
        Node* next;

    public:
        Node(int data1, Node* next1) {
            data = data1;
            next = next1;
        }
    public:
        Node(int data1) {
            data = data1;
            next = nullptr;
        }
};

Node* constructLL(vector<int>& arr) {
    int len = arr.size();
    Node* prev = new Node(arr[0], nullptr);
    Node* res = prev;
    for (int i = 1; i < len; i++) {
        Node *temp = new Node(arr[i]);
        prev -> next = temp;
        prev = temp;
    }
    return res;
}

int main() {
    cout << "Starting Program" << endl;
    int x = 5;
    Node *y = new Node(x);
    cout << y->data << endl;
    return 0;
}