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

bool isPalindrome(Node *head) {
    vector<int> v;
    Node *s = head;
    while(s != NULL) {
        v.push_back(s->data);
        s = s->next;
    }
    int vSz = v.size();
    for(int i = 0; i < vSz / 2; i++) {
        cout << v[i] << "and" << v[vSz - (i + 1)] << endl;
        if (v[i]  != v[vSz - i - 1]) {
            return false;
        }
    }
    return true;
}

int main() {
    cout << "Starting Program" << endl;
    Node* h = new Node(1);
    h->next = new Node(2);
    h->next->next = new Node(2);
    h->next->next->next = new Node(1);
    cout << isPalindrome(h) << endl;
    return 0;
}