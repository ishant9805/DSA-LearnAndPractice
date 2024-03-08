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
    while(head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
}

int main() {
    cout << "Starting Program" << endl;
    vector<int> v = {1,2,3,4};
    Node* head = constructDLL(v);
    print(head);
    return 0;
}