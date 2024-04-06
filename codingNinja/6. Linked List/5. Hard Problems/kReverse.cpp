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

Node* rev(Node* head) {
    Node *tmp = head;
    Node *prev = NULL;
    while (tmp != NULL) {
        Node* front = tmp->next;
        tmp->next = prev;
        prev = tmp;
        tmp = front;
    }
    return prev;
}

Node* findKthNode(Node *tmp, int k) {
    k-=1;
    while(tmp != NULL && k > 0) {
        k--;
        tmp=tmp->next;
    }
    return tmp;
}

Node* kReverse(Node* head, int k) {
    Node* tmp = head;
    Node* prevNd = NULL;
    while(tmp) {
        Node *kthNode = findKthNode(tmp, k);
        if (kthNode == NULL) {
            if (prevNd) {
                prevNd->next = tmp;
            }
            break;
        }
        Node* nxtNd = kthNode->next;
        kthNode->next = NULL;
        rev(tmp);
        if (tmp == head) {
            head = kthNode;
        } else {
            prevNd->next = kthNode;
        }
        prevNd = tmp;
        tmp = nxtNd;
    }
    return head;
}

int main() {
    cout << "Starting Program" << endl;
    vector<int> v1 = {1, 2, 3, 4};
    Node* num1 = constructLL(v1);
    PrintLL(num1);
    num1 = kReverse(num1, 3);
    PrintLL(num1);
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
