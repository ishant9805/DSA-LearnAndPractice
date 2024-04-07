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
int lengthLL(Node* head);

Node *rotate(Node *head, int k) {
    if (k == 0) return head;
    Node *tmp = head;
    int rem = lengthLL(tmp);
    if (k < rem) rem -= k;
    else {
        k %= rem;
        rem-=k;
    }
    Node* prev = NULL;
    while(rem--) {
        prev = tmp;
        tmp = tmp->next;
    }
    if (!tmp) return head;
    if (prev) prev->next = NULL;
    Node* nH = tmp;
    while(tmp->next) {
        tmp = tmp->next;
    }
    tmp->next = head;
    return nH;
}

int main() {
    cout << "Starting Program" << endl;
    vector<int> v1 = {1, 2, 3, 4, 5, 6};
    Node* num1 = constructLL(v1);
    PrintLL(num1);
    num1 = rotate(num1, 10);
    PrintLL(num1);
    return 0;
}

int lengthLL(Node* head){
    Node* tmp = head;
    int len = 0;
    while(tmp) {
        len++;
        tmp = tmp->next;
    }
    return len;
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
