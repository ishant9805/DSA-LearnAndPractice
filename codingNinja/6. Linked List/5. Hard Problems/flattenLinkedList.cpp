#include<bits/stdc++.h>

using namespace std;
class Node {
 public:
	int data;
	Node *next;
	Node *child;
	Node() : data(0), next(nullptr), child(nullptr){};
	Node(int x) : data(x), next(nullptr), child(nullptr) {}
	Node(int x, Node *next, Node *child) : data(x), next(next), child(child) {}
};
Node* constructLL(vector<int>& arr);
void PrintLL(Node* head);

Node* flattenLinkedList(Node* head) 
{
	Node* tmp = head;
    Node* nH = tmp;
    Node* it = nH;
    while(tmp) {
        Node *child = tmp->child;
        while(child->next){
            child = child->next;
        }
        it->next = tmp->child;
        child->next = tmp->next;
        tmp = tmp->next;
        it = tmp;
    }
    return nH;
}

int main() {
    cout << "Starting Program" << endl;
    vector<vector<int>> v1 = {{1, 2, 3}, {4, 5, 6}, {7,8}, {9,12}, {20}};
    Node* num1 = constructLL(v1);
    PrintLL(num1);
    return 0;
}

Node* constructLL(vector<vector<int>>& arr) {
    int len = arr.size();
    Node* prev = new Node(arr[0], nullptr, nullptr);
    Node* head = prev;
    for (int i = 1; i < len; i++) {
        Node *temp = new Node(arr[i], nullptr, nullptr);
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
