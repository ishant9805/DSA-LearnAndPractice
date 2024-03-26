#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* oddEvenList(ListNode* head)
{
    if (head == NULL || head->next == NULL){
        return head;
    }
    ListNode* f = head;
    ListNode* mem = head->next;
    ListNode* s;
    while (f != NULL && f->next != NULL && f->next->next)
    {
        ListNode* s = f->next;
        f->next = s->next;
        f = f->next;
        s->next = f->next;
    }
    f->next = mem;
    return head;
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

int main() {
    cout << "Starting Program" << endl;
    vector<int> v1 = {1,2,3,4,5,6,7,8};
    ListNode* head = constructLL(v1);
    PrintLL(head);
    head = oddEvenList(head);
    PrintLL(head);
    return 0;
}