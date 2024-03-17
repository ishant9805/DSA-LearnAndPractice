#include<bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Iterative Method
// ListNode* reverseList(ListNode *head)
// {
//     ListNode *prev = NULL;
//     ListNode *curr = head;
//     while (curr != NULL)
//     {
//         ListNode *front = curr->next;
//         curr->next = prev;
//         prev = curr;
//         curr = front;
//     }
//     return prev;
// }

// Recursive Method
ListNode* reverseList(ListNode *head) {
    if (head == NULL || head->next == NULL) return head;

    ListNode* nH = reverseList(head->next);
    ListNode* front = head->next;
    front->next = head;
    head->next = NULL;
    return nH;
}

int main() {
    cout << "Starting Program" << endl;
    vector<int> v1 = {};
    
    return 0;
}