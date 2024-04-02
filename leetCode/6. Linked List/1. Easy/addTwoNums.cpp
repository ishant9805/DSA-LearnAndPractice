#include<bits/stdc++.h>

using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
ListNode* constructLL(vector<int>& arr);
void PrintLL(ListNode* head);


ListNode* addTwoNumbers(ListNode* num1, ListNode* num2) {
    ListNode *t1 = new ListNode((num1->val + num2->val) % 10);
    ListNode *t2 = t1;
    int carry = (num1->val + num2->val) / 10;
    num1 = num1->next;
    num2 = num2->next;
    while(num1 && num2) {
        ListNode* tmp = new ListNode((num1->val + num2->val + carry) % 10);
        t2->next = tmp;
        t2 = tmp;
        carry = (num1->val + num2->val + carry) / 10;
        num1 = num1->next;
        num2 = num2->next;
    }
    while (num1) {
        ListNode* tmp = new ListNode((num1->val + carry) % 10);
        t2->next = tmp;
        t2 = tmp;
        carry = (num1->val + carry) / 10;
        num1 = num1->next;
    }
    while (num2) {
        ListNode* tmp = new ListNode((num2->val + carry) % 10);
        t2->next = tmp;
        t2 = tmp;
        carry = (num2->val + carry) / 10;
        num2 = num2->next;
    }
    if (carry != 0) {
        t2->next = new ListNode(carry);
    }
    return t1;
}

int main() {
    cout << "Starting Program" << endl;
    vector<int> v1 = {1, 5, 5, 0, 9, 0, 7, 5, 1, 9, 6, 0, 5, 0, 1, 2, 8, 5, 6, 1, 7, 8};
    vector<int> v2 = {1, 2, 3, 9, 4, 3, 9, 9, 9};
    ListNode* num1 = constructLL(v1);
    ListNode* num2 = constructLL(v2);
    PrintLL(num1);
    PrintLL(num2);
    num2 = addTwoNumbers(num1, num2);
    PrintLL(num2);
    return 0;
}

ListNode* constructLL(vector<int>& arr) {
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

void PrintLL(ListNode* head) {
    if (head == nullptr) {
        cout << "There is nothing in LL to print🙂" << endl;
    } else {
        cout << "[";
        while(head->next != nullptr) {
            cout << head->val << ", ";
            head = head->next;
        }
        cout << head->val << "]" << endl;
    }
}
