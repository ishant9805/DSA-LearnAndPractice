#include<bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *middleNode(ListNode *head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }
    ListNode* fast = head;
    ListNode* slow = head;
    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}

ListNode* arr2LL(vector<int>& arr) {
    int len = arr.size();
    ListNode* prev = new ListNode(arr[0], nullptr);
    ListNode* head = prev;
    for (int i = 1; i < len; i++) {
        ListNode *temp = new ListNode(arr[i]);
        prev -> next = temp;
        prev = temp;
    }
    return head;
}

void printll(ListNode *head) {
    while (head->next!=NULL)
    {
        cout << head->val << " ";
        head = head->next;
    }
    cout << head->val << endl;    
}

int main() {
    cout << "Starting Program" << endl;
    vector<int> v = {4,1,8,2,4};
    ListNode* head = arr2LL(v);
    printll(head);
    head = middleNode(head);
    printll(head);
    return 0;
}