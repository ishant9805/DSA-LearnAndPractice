#include<bits/stdc++.h>

using namespace std;

class Node
{
public:
   int data;
   Node *next, *prev;
   Node() : data(0), next(nullptr), prev(nullptr) {}
   Node(int x) : data(x), next(nullptr), prev(nullptr) {}
   Node(int x, Node *next, Node *prev) : data(x), next(next), prev(prev) {}
};

Node * insertAtTail(Node *head, int k) {
    if (head == NULL) {
        return new Node(k);
    }
    Node* temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = new Node(k, nullptr, temp);
    return head;
}

void print(Node* head) {
    cout << "[";
    while(head != NULL) {
        cout << head->data;
        if (head->next != NULL) cout << ", ";
        head = head->next;
    }
    cout << "]" << endl;
}

int main() {
    cout << "Starting Program" << endl;
    Node* head = new Node(4);
    head->next = new Node(10, nullptr, head);
    head->next->next = new Node(3, nullptr, head->next);
    head->next->next->next = new Node(5, nullptr, head->next->next);
    print(head);
    head = insertAtTail(head, 12);
    print(head);
    head = new Node();
    print(head);
    head = insertAtTail(head, 5);
    print(head);

    return 0;
}