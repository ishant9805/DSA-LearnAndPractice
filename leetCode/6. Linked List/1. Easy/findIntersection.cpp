#include<bits/stdc++.h>

using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
// Naive Solution
// ListNode* findIntersection(ListNode *firstHead, ListNode *secondHead){
//     vector<ListNode*> fHead;
//     vector<ListNode*> sHead;
//     ListNode* fTmp = firstHead;
//     ListNode* sTmp = secondHead;
//     vector<ListNode*>::iterator it;
//     while(true) {
//         fHead.push_back(fTmp);
//         sHead.push_back(sTmp);
//         it = find(fHead.begin(), fHead.end(), sTmp);
//         if (it != fHead.end()) {
//             return sTmp;
//         }
//         it = find(sHead.begin(), sHead.end(), fTmp);
//         if (it != sHead.end()) {
//             return fTmp;
//         }
//         if (fTmp != NULL)
//             fTmp = fTmp->next;
//         if (sTmp != NULL)
//             sTmp = sTmp->next;
//     }
//     return NULL;
// }

// Optimized Solution
ListNode* getIntersectionNode(ListNode* first, ListNode* sec) {
    ListNode* fHead = first;
    ListNode* sHead = sec;
    int firstlen = 0;
    int seclen = 0;
    while (fHead) {
        firstlen++;
        fHead = fHead->next;
    }
    while (sHead) {
        seclen++;
        sHead = sHead->next;
    }

    int diff = abs(firstlen - seclen);

    if (firstlen > seclen) {
        while(diff) {
            first = first->next;
            diff--;
        }
    } else {
        while(diff) {
            sec = sec->next;
            diff--;
        }
    }
    while(first && sec && first != sec) {
        first = first->next;
        sec = sec->next;
    }
    return first;
}
