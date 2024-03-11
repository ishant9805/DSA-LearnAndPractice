#include<bits/stdc++.h>

using namespace std;

class Node
{
public:
    int data;
    Node *next,*prev;
    Node()
    {
        this->data = 0;
        next = NULL;
        prev= NULL;
    }
    Node(int data)
    {
        this->data = data; 
        this->next = NULL;
        this->prev= NULL;
    }
    Node(int data, Node* next, Node *prev)
    {
        this->data = data;
        this->next = next;
        this->prev= prev;
    }
};

Node* reverseDLL(Node* head)
{   
    if (head == NULL || head->next == NULL) {
        return head;
    }
    Node* prev;
    Node* current = head;
    while(current != NULL){
        prev = current->prev;

        current->prev = current->next;
        current->next = prev;
        current = current->prev;
    }
    return prev->prev;
}

void printdll(Node* head){
    cout << "[";
    while(head != NULL) {
        cout << head->data << ", ";
        head = head->next;
    }
    cout << "]" << endl;
}

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

int main() {
    cout << "Starting Program" << endl;
    vector<int> v = {0,1,2,3,4};
    Node* head = constructDLL(v);
    printdll(head);
    head = reverseDLL(head);
    printdll(head);
    return 0;
}