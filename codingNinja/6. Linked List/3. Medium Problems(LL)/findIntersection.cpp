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
// Node* findIntersection(Node *firstHead, Node *secondHead)
// {
//     vector<Node*> fHead;
//     vector<Node*> sHead;
//     Node* fTmp = firstHead;
//     Node* sTmp = secondHead;
//     vector<Node*>::iterator it;
//     while(true) {
//         fHead.push_back(fTmp);
//         sHead.push_back(sTmp);
//         it = find(fHead.begin(), fHead.end(), sTmp);
//         if (it != fHead.end()) {
//             return sTmp;
//         }
//         it = find(sHead.begin(), sHead.end(), fTmp);
//         if (it != sHead.end()) {
//             return fTmp;
//         }
//         if (fTmp != NULL)
//             fTmp = fTmp->next;
//         if (sTmp != NULL)
//             sTmp = sTmp->next;
//     }
//     return NULL;
// }

// Optimized
Node* findIntersection(Node* first, Node* sec) {
    Node* fHead = first;
    Node* sHead = sec;
    int firstlen = 0;
    int seclen = 0;
    while (fHead) {
        firstlen++;
        fHead = fHead->next;
    }
    while (sHead) {
        seclen++;
        sHead = sHead->next;
    }

    int diff = abs(firstlen - seclen);

    if (firstlen > seclen) {
        while(diff) {
            first = first->next;
            diff--;
        }
    } else {
        while(diff) {
            sec = sec->next;
            diff--;
        }
    }
    while(first && sec && first != sec) {
        first = first->next;
        sec = sec->next;
    }
    return first;
}

int main() {
    cout << "Starting Program" << endl;
    // vector<int> v1 = {1,9,3,8,4,6,5};
    vector<int> v1 = {4,1,8};
    Node* head = constructLL(v1);
    Node* insx = head->next->next;
    Node* tHead = new Node(5);
    tHead->next = new Node(6, insx);
    // tHead->next->next = new Node(2, insx);
    PrintLL(head);
    PrintLL(tHead);
    head = findIntersection(head, tHead);
    PrintLL(head);
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
