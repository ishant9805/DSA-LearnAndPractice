#include<bits/stdc++.h>

using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data; 
        this->next = NULL;
    }
    Node(int data, Node* next)
    {
        this->data = data;
        this->next = next;
    }
};


Node *findMiddle(Node *head) {
    Node* tmp = head;
    int i = 0;
    while (tmp != NULL)
    {
        i++;
        if (i==2) {
            head = head->next;
            i = 0;
        }
        tmp = tmp->next;
    }
    return head;
}

Node* arr2LL(vector<int>& arr) {
    int len = arr.size();
    Node* prev = new Node(arr[0], nullptr);
    Node* head = prev;
    for (int i = 1; i < len; i++) {
        Node *temp = new Node(arr[i]);
        prev -> next = temp;
        prev = temp;
    }
    return head;
}

void printll(Node *head) {
    while (head->next!=NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << head->data << endl;    
}

int main() {
    cout << "Starting Program" << endl;
    vector<int> v = {4,1,8,2,4};
    Node* head = arr2LL(v);
    printll(head);
    head = findMiddle(head);
    printll(head);
    return 0;
}