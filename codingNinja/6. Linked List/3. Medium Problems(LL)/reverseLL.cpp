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

Node* reverseLinkedList(Node *head)
{
    if (head == NULL || head->next == NULL) {
        return head;
    }
    Node* tmp = head;
    stack<int> st;
    while(tmp != NULL) {
        st.push(tmp->data);
        tmp = tmp->next;
    }
    tmp = head;
    while(tmp != NULL) {
        tmp->data = st.top();
        st.pop();
        tmp = tmp->next;
    }
    return head;
}

Node* constructLL(vector<int>& arr) {
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
    vector<int> v = {1,2,4,-1};
    Node* head = constructLL(v);
    printll(head);
    head = reverseLinkedList(head);
    printll(head);
    return 0;
}