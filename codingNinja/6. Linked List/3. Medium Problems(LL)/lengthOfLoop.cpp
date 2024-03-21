#include<bits/stdc++.h>

using namespace std;


class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
    Node(int data, Node* next)
    {
        this->data = data;
        this->next = next;
    }
};

// Hashmap method
// int lengthOfLoop(Node *head){
//     map<Node *, int> mpp;
//     Node* curr = head;
//     int n = 0;
//     while(curr != NULL && curr->next != NULL) {
//         if (mpp.find(curr) != mpp.end()) {
//             int d = distance(mpp.begin(), mpp.find(curr));
//             return n - d;
//         }
//         n++;
//         mpp[curr] = 1;
//         curr = curr->next;
//     }
//     return 0;
// }

// Totoise-Hare method
int lengthOfLoop(Node *head) {
    Node *slow = head;
    Node *fast = head;
    int c = 0;
    while(fast && fast->next) {
        slow = slow->next; 
        fast = fast->next->next;
        if (slow == fast) {
            fast = fast->next;
            while (slow != fast) {
                c++;
                fast = fast->next;
            }
            return c;
        } 
    }
    return 0;
}

int main() {
    cout << "Starting Program" << endl;
    vector<int> v1 = {};
    
    return 0;
}