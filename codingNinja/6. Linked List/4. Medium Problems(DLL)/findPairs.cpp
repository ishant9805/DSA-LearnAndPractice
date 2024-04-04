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

vector<pair<int, int>> findPairs(Node* head, int k)
{
    Node *left = head;
    Node *right = head;
    vector<pair<int, int>> res;
    while(right->next) {
        right = right->next;
    }
    while(left != right) {
        if (left->data + right->data > k) {
            right = right->prev;
        } else if (left->data + right->data < k) {
            left = left->next;
        } else {
            res.push_back({left->data, right->data});
            left = left->next;
        }
    }
    return res;
}

int main() {
    cout << "Starting Program" << endl;
    vector<int> v = {1, 2, 3, 4, 9};
    Node* head = constructDLL(v);
    print(head);
    vector<pair<int, int>> b = findPairs(head, 5);
    for(auto it:b) {
        cout << it.first << ", " << it.second << endl;
    }
    return 0;
}