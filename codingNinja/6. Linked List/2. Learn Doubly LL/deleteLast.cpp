#include<bits/stdc++.h>

using namespace std;

struct Node {
    int data;
    Node *prev;
    Node *next;
    Node() : data(0), prev(nullptr), next(nullptr) {}
    Node(int val) : data(val), prev(nullptr), next(nullptr) {}
    Node(int val, Node *p, Node *n) : data(val), prev(p), next(n) {}
};

Node * deleteLastNode(Node *head) {
    if (head->next == NULL) {
        return NULL;
    }
    Node* temp = head;
    while(temp->next != NULL) {
        temp = temp->next;
    }
    temp->prev->next = NULL;
    return head;
}

int main() {
    cout << "Starting Program" << endl;
    
    return 0;
}