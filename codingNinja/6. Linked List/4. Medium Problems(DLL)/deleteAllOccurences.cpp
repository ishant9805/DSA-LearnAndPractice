#include<bits/stdc++.h>

using namespace std;

class Node
{
public:
    int data;
    Node *prev;
    Node *next;
    Node() {
        this->data = 0;
        this->prev = NULL;
        this->next = NULL;
    }
    Node(int data) {
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }
    Node (int data, Node *next, Node *prev) {
        this->data = data;
        this->prev = prev;
        this->next = next;
    }
};
Node* constructDLL(vector<int>& arr) {
    int len = arr.size();
    Node* head = new Node(arr[0]);
    Node* prev = head;
    for (int i = 1; i < len; i++)
    {
        Node* curr = new Node(arr[i], nullptr, prev);
        prev->next = curr;
        prev = prev->next;
    }
    return head;    
}

void print(Node* head) {
    if (head == NULL) {
        cout << "NULL" << endl;
        return;
    }
    while(head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
}

Node * deleteAllOccurrences(Node* head, int k) {
    Node *tmp = head->next;
    while(tmp) {
        Node *it = tmp;
        tmp = tmp->prev;
        if (it->data == k) {
            tmp->next = it->next;
            tmp = tmp->next;
        } else {
            tmp = it->next;
        }
    }
    while(head->data == k && head->next) {
        head = head->next;
    }
    if (head->data == k) {
        return NULL;
    }
    return head;
}


int main() {
    cout << "Starting Program" << endl;
    vector<int> v = {10, 4, 10, 3, 5, 20, 10};
    Node* head = constructDLL(v);
    print(head);
    head = deleteAllOccurrences(head, 10);
    print(head);
    return 0;
}