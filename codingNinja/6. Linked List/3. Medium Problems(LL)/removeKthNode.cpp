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
Node* constructLL(vector<int>& arr);
void PrintLL(Node* head);

Node* removeKthNode(Node* head, int K)
{
    Node* tmp = head;
    stack<Node*> st;
    while(tmp) {
        st.push(tmp);
        tmp = tmp->next;
    }
    int i = 0;
    while(i != K) {
        st.pop();
        i++;
    }
    if (st.size() == 0) {
        return head->next;
    }
    tmp = st.top();
    tmp->next = tmp->next->next;
    return head;
}

int main() {
    cout << "Starting Program" << endl;
    vector<int> v1 = {1,2,3,4,5,6};
    Node* head = constructLL(v1);
    PrintLL(head);
    head = removeKthNode(head, 3);
    PrintLL(head);
    return 0;
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

void PrintLL(Node* head) {
    if (head == nullptr) {
        cout << "There is nothing in LL to print🙂" << endl;
    } else {
        cout << "[";
        while(head->next != nullptr) {
            cout << head->data << ", ";
            head = head->next;
        }
        cout << head->data << "]" << endl;
    }
}
