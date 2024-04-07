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
int lengthLL(ListNode* head);

ListNode *rotateRight(ListNode *head, int k) {
    if (k == 0) return head;
    ListNode *tmp = head;
    int rem = lengthLL(tmp);
    if (k < rem) rem -= k;
    else {
        k %= rem;
        rem-=k;
    }
    ListNode* prev = NULL;
    while(rem--) {
        prev = tmp;
        tmp = tmp->next;
    }
    if (!tmp) return head;
    if (prev) prev->next = NULL;
    ListNode* nH = tmp;
    while(tmp->next) {
        tmp = tmp->next;
    }
    tmp->next = head;
    return nH;
}

int main() {
    cout << "Starting Program" << endl;
    vector<int> v1 = {1, 2, 3, 4, 5, 6};
    ListNode* num1 = constructLL(v1);
    PrintLL(num1);
    num1 = rotateRight(num1, 10);
    PrintLL(num1);
    return 0;
}

int lengthLL(ListNode* head){
    ListNode* tmp = head;
    int len = 0;
    while(tmp) {
        len++;
        tmp = tmp->next;
    }
    return len;
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
