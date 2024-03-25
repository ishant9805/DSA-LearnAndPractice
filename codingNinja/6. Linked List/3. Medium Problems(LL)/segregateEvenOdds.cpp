#include<bits/stdc++.h>
using namespace std;

class Node {
 public:
    int data;
    Node *next;
    Node() : data(0), next(nullptr) {};
    Node(int x) : data(x), next(nullptr) {}
    Node(int x, Node *next) : data(x), next(next) {}
};

Node* segregateEvenOdd(Node* head)
{
    vector<int> ev;
    vector<int> od;
    Node* curr = head;
    while(curr) {
        if (curr->data % 2 == 0) {
            ev.push_back(curr->data);
        } else {
            od.push_back(curr->data);
        }
        curr = curr->next;
    }
    curr = head;
    for(int i = 0; i < ev.size(); i++, curr = curr->next) {
        curr->data = ev[i];
    }
    for(int i = 0; i < od.size(); i++, curr = curr->next) {
        curr->data = od[i];
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

int main() {
    cout << "Starting Program" << endl;
    vector<int> v1 = {1, 15, 15, 13, 7, 0, 15, 8, 15, 5, 6, 3, 17, 18, 16,19, 10, -1};
    Node* head = constructLL(v1);
    PrintLL(head);
    head = segregateEvenOdd(head);
    PrintLL(head);
    return 0;
}