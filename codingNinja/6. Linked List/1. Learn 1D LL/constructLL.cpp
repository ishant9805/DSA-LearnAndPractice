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


int main() {
    cout << "Starting Program" << endl;
    int x = 5;
    Node *y = new Node(x);
    cout << y->data << endl;
    return 0;
}