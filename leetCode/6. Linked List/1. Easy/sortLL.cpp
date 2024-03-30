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
// Naive Solution
vector<int> llToVec(ListNode* head);
ListNode* sortList(ListNode* head){
    ListNode *tmp = head;
    vector<int> v = llToVec(tmp);
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++, tmp = tmp->next)
    {
        tmp->val = v[i];
    }
    return head;
}


int main() {
    cout << "Starting Program" << endl;
    vector<int> v1 = {1,9,3,8,4,6,5};
    ListNode* head = constructLL(v1);
    PrintLL(head);
    head = sortList(head);
    PrintLL(head);
    return 0;
}

vector<int> llToVec(ListNode* head) {
    vector<int> v;
    while(head) {
        v.push_back(head->val);
        head = head->next;
    }
    return v;
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
