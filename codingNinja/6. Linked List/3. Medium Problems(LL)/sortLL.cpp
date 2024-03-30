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
// Naive Solution
vector<int> llToVec(Node* head);
Node* sortList(Node* head){
    Node *tmp = head;
    vector<int> v = llToVec(tmp);
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++, tmp = tmp->next)
    {
        tmp->data = v[i];
    }
    return head;
}


int main() {
    cout << "Starting Program" << endl;
    vector<int> v1 = {1,9,3,8,4,6,5};
    Node* head = constructLL(v1);
    PrintLL(head);
    head = sortList(head);
    PrintLL(head);
    return 0;
}

vector<int> llToVec(Node* head) {
    vector<int> v;
    while(head) {
        v.push_back(head->data);
        head = head->next;
    }
    return v;
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
