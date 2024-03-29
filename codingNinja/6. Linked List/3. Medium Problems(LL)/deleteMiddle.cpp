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

Node* deleteMiddle(Node* head) {
    if (head == NULL || head->next == NULL) {
        return NULL;
    }
    Node* fast = head;
    Node* slow = head;
    Node* prev;
    while (fast && fast->next) {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    prev->next = slow->next;
    delete slow;
    return head;
}

int main() {
    cout << "Starting Program" << endl;
    vector<int> v1 = {1,2,3,4,5};
    Node* head = constructLL(v1);
    PrintLL(head);
    head = deleteMiddle(head);
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
