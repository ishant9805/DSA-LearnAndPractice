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
// ListNode* removeNthFromEnd(ListNode* head, int K) {
//     ListNode* tmp = head;
//     stack<ListNode*> st;
//     while(tmp) {
//         st.push(tmp);
//         tmp = tmp->next;
//     }
//     int i = 0;
//     while(i != K) {
//         st.pop();
//         i++;
//     }
//     if (st.size() == 0) {
//         return head->next;
//     }
//     tmp = st.top();
//     tmp->next = tmp->next->next;
//     return head;
// }

// Optimal Solution
ListNode* removeNthFromEnd(ListNode* head, int K) {
    ListNode* fast = head;
    ListNode* slow = head;
    for (int i = 0; i < K; i++) {
        fast = fast->next;
    }
    if (fast == NULL) return head->next;
    while(fast->next != NULL) {
        fast = fast->next;
        slow = slow->next;
    }
    ListNode* delN = slow->next;
    slow->next = slow->next->next;
    delete delN;
    return head;
}

int main() {
    cout << "Starting Program" << endl;
    vector<int> v1 = {1,2,3,4,5};
    ListNode* head = constructLL(v1);
    PrintLL(head);
    head = removeNthFromEnd(head, 2);
    PrintLL(head);
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
