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

ListNode* rev(ListNode* head) {
    ListNode *tmp = head;
    ListNode *prev = NULL;
    while (tmp != NULL) {
        ListNode* front = tmp->next;
        tmp->next = prev;
        prev = tmp;
        tmp = front;
    }
    return prev;
}

ListNode* findKthListNode(ListNode *tmp, int k) {
    k-=1;
    while(tmp != NULL && k > 0) {
        k--;
        tmp=tmp->next;
    }
    return tmp;
}

ListNode* reverseKGroup(ListNode* head, int k) {
    ListNode* tmp = head;
    ListNode* prevNd = NULL;
    while(tmp) {
        ListNode *kthListNode = findKthListNode(tmp, k);
        if (kthListNode == NULL) {
            if (prevNd) {
                prevNd->next = tmp;
            }
            break;
        }
        ListNode* nxtNd = kthListNode->next;
        kthListNode->next = NULL;
        rev(tmp);
        if (tmp == head) {
            head = kthListNode;
        } else {
            prevNd->next = kthListNode;
        }
        prevNd = tmp;
        tmp = nxtNd;
    }
    return head;
}

int main() {
    cout << "Starting Program" << endl;
    vector<int> v1 = {1, 2, 3, 4};
    ListNode* num1 = constructLL(v1);
    PrintLL(num1);
    num1 = reverseKGroup(num1, 3);
    PrintLL(num1);
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
