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

Node *deleteLast(Node *list){
    Node* head = list;
    Node* prev = head;
    while (true)
    {
        Node *temp = prev->next;
        if (temp->next == nullptr) {
            prev->next = nullptr;
            break;
        }
        prev = temp;
    }
    return head;
}

int main() {
    cout << "Starting Program" << endl;
    
    return 0;
}