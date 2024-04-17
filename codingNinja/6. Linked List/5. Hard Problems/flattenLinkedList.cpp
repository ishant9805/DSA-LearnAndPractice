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

// Naive Solution
// Node* flattenLinkedList(Node* head) 
// {
// 	Node* tmp = head;
//     vector<int> arr;
//     while(tmp) {
//         Node *ch = tmp;
//         while(ch) {
//             arr.push_back(ch->data);
//             ch = ch->child;
//         }
//         tmp = tmp->next;
//     }
//     sort(arr.begin(), arr.end());
//     if (arr.size() == 0) return NULL;
//     Node* newH = new Node(arr[0]);
//     tmp = newH;
//     for(int i = 1; i < arr.size(); i++) {
//         Node *hh = new Node(arr[i]);
//         tmp->child = hh;
//         tmp = tmp->child;
//     }
//     return newH;
// }

// Merge method
// Merge method
Node* merge(Node* list1, Node* list2) {
    if (list1 == NULL) {
        list2->next = nullptr;
        return list2;
    }
    if (list2 == NULL) {
        list1->next = nullptr;
        return list1;
    }
    Node* merg = NULL;
    if(list2->data < list1->data) {
        merg = list2;
        merg->child = merge(list2->child, list1);
    } else {
        merg = list1;
        merg->child = merge(list1->child, list2);
    }
    merg->next = nullptr;
    return merg;
}

Node* flattenLinkedList(Node* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }
    head->next = flattenLinkedList(head->next);
    head = merge(head, head->next);
    return head;
}

int main() {
    cout << "Starting Program" << endl;
    cout << "NO DRIVER CODE PRESENT" << endl;
    return 0;
}
