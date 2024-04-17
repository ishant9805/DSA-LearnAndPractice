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

Node* flattenLinkedList(Node* head) 
{
	Node* tmp = head;
    vector<int> arr;
    while(tmp) {
        Node *ch = tmp;
        while(ch) {
            arr.push_back(ch->data);
            ch = ch->child;
        }
        tmp = tmp->next;
    }
    sort(arr.begin(), arr.end());
    if (arr.size() == 0) return NULL;
    Node* newH = new Node(arr[0]);
    tmp = newH;
    for(int i = 1; i < arr.size(); i++) {
        Node *hh = new Node(arr[i]);
        tmp->child = hh;
        tmp = tmp->child;
    }
    return newH;
}

int main() {
    cout << "Starting Program" << endl;
    cout << "NO DRIVER CODE PRESENT" << endl;
    return 0;
}
