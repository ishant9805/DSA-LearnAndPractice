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
// Extreme naive method
// bool isPalindrome(Node *head) {
//     vector<int> v;
//     Node *s = head;
//     while(s != NULL) {
//         v.push_back(s->data);
//         s = s->next;
//     }
//     int vSz = v.size();
//     for(int i = 0; i < vSz / 2; i++) {
//         cout << v[i] << "and" << v[vSz - (i + 1)] << endl;
//         if (v[i]  != v[vSz - i - 1]) {
//             return false;
//         }
//     }
//     return true;
// }

Node* reverseLL(Node* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }
    Node* nH = reverseLL(head->next);
    Node* front = head->next;
    front->next = head;
    head->next = NULL;
    return nH;
}

// Optimized
bool isPalindrome(Node* head) {
    Node* slow = head;
    Node* fast = head;
    while(fast->next != NULL && fast->next->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    Node* newHead = reverseLL(slow->next);

    slow = head, fast = newHead;
    while(fast != NULL) {
        if (slow->data != fast->data) {
            reverseLL(newHead);
            return false;
        }
        slow = slow->next;
        fast = fast->next;
    }
    reverseLL(newHead);
    return true;
}

int main() {
    cout << "Starting Program" << endl;
    Node* h = new Node(1);
    h->next = new Node(2);
    h->next->next = new Node(2);
    h->next->next->next = new Node(1);
    cout << isPalindrome(h) << endl;
    return 0;
}