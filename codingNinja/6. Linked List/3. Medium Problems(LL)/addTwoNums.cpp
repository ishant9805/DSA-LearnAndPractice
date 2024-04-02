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


Node* addTwoNumbers(Node* num1, Node* num2) {
    Node *t1 = new Node((num1->data + num2->data) % 10);
    Node *t2 = t1;
    int carry = (num1->data + num2->data) / 10;
    num1 = num1->next;
    num2 = num2->next;
    while(num1 && num2) {
        Node* tmp = new Node((num1->data + num2->data + carry) % 10);
        t2->next = tmp;
        t2 = tmp;
        carry = (num1->data + num2->data + carry) / 10;
        num1 = num1->next;
        num2 = num2->next;
    }
    while (num1) {
        Node* tmp = new Node((num1->data + carry) % 10);
        t2->next = tmp;
        t2 = tmp;
        carry = (num1->data + carry) / 10;
        num1 = num1->next;
    }
    while (num2) {
        Node* tmp = new Node((num2->data + carry) % 10);
        t2->next = tmp;
        t2 = tmp;
        carry = (num2->data + carry) / 10;
        num2 = num2->next;
    }
    if (carry != 0) {
        t2->next = new Node(carry);
    }
    return t1;
}

int main() {
    cout << "Starting Program" << endl;
    vector<int> v1 = {1, 5, 5, 0, 9, 0, 7, 5, 1, 9, 6, 0, 5, 0, 1, 2, 8, 5, 6, 1, 7, 8};
    vector<int> v2 = {1, 2, 3, 9, 4, 3, 9, 9, 9};
    Node* num1 = constructLL(v1);
    Node* num2 = constructLL(v2);
    PrintLL(num1);
    PrintLL(num2);
    num2 = addTwoNumbers(num1, num2);
    PrintLL(num2);
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
