#include<bits/stdc++.h>

using namespace std;

class Node {
    public:
        int data;
        Node *next;
            Node *random;
        Node() : data(0), next(nullptr), random(nullptr){};
        Node(int x) : data(x), next(nullptr), random(nullptr) {}
        Node(int x, Node *next, Node *random) : data(x), next(next), random(random) {}
};

Node *cloneLL(Node *head){
	Node* tmp = head;
    while (tmp != NULL) {
        Node* copyNode = new Node(tmp->data);
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

    Node* nh = cloneLL(a);

    while (nh) {
        cout << "Data: " << nh->data << "\t";
        cout << "Random: " << nh->random->data << endl;
        nh = nh->next;
    }
    return 0;
}
