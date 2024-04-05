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

Node *removeDuplicates(Node* head) {
    Node *tmp = head;
    while(tmp) {
        Node* nxt = tmp->next;
        while(nxt != NULL && nxt->data == tmp->data) {
            nxt = nxt->next;
        }
        tmp->next = nxt;
        if (nxt)
            nxt->prev = tmp;
        tmp = tmp->next;
    }
    return head;
}



int main() {
    cout << "Starting Program" << endl;
    vector<int> v = {1, 2, 2, 2, 3};
    Node* head = constructDLL(v);
    print(head);
    head = removeDuplicates(head);
    print(head);
    return 0;
}