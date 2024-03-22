#include<bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// bool isPalindrome(ListNode *head) {
//     vector<int> v;
//     ListNode *s = head;
//     while(s != NULL) {
//         v.push_back(s->val);
//         s = s->next;
//     }
//     int vSz = v.size();
//     for(int i = 0; i < vSz / 2; i++) {
//         if (v[i]  != v[vSz - i - 1]) {
//             return false;
//         }
//     }
//     return true;
// }

// Optimized
ListNode* reverseLL(ListNode* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }
    ListNode* nH = reverseLL(head->next);
    ListNode* front = head->next;
    front->next = head;
    head->next = NULL;
    return nH;
}
bool isPalindrome(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;
    while(fast->next != NULL && fast->next->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    ListNode* newHead = reverseLL(slow->next);

    slow = head, fast = newHead;
    while(fast != NULL) {
        if (slow->val != fast->val) {
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
    ListNode* h = new ListNode(1);
    h->next = new ListNode(2);
    h->next->next = new ListNode(2);
    h->next->next->next = new ListNode(1);
    cout << isPalindrome(h) << endl;
    return 0;
}