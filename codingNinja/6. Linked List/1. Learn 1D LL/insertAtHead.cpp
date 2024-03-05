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

Node* insertAtFirst(Node* list, int newValue) {
    Node* newNode = new Node(newValue, list);
    return newNode;
}

int main() {
    cout << "Starting Program" << endl;
    
    return 0;
}