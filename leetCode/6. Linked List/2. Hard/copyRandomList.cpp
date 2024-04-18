#include<bits/stdc++.h>

using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

Node *copyRandomList(Node *head){
	Node* tmp = head;
    while (tmp != NULL) {
        Node* copyNode = new Node(tmp->val);
        copyNode->next = tmp->next;
        tmp->next = copyNode;
        tmp = tmp->next->next;
    }
    tmp = head;
    while (tmp != NULL) {
        if (tmp->random) {
            tmp->next->random = tmp->random->next;
        }
        tmp = tmp->next->next;
    }
    Node* dummy = new Node(-1);
    Node* temp = dummy;
    tmp = head;
    while (tmp != NULL) {
        temp->next = tmp->next;
        temp = temp->next;
        tmp->next = temp->next;
        tmp = tmp->next;
    }
    return dummy->next;
}

int main() {
    Node* a = new Node(1);
    Node* b = new Node(2);
    Node* c = new Node(3);
    Node* d = new Node(4);
    Node* e = new Node(5);
    a->next = b;
    a->random = c;
    b->next = c;
    b->random = a;
    c->next = d;
    c->random = e;
    d->next = e;
    d->random = e;
    e->next = nullptr;
    e->random = b;

    Node* nh = copyRandomList(a);

    while (nh) {
        cout << "Data: " << nh->val << "\t";
        cout << "Random: " << nh->random->val << endl;
        nh = nh->next;
    }
    return 0;
}
