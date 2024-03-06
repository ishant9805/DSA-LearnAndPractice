#include<bits/stdc++.h>

using namespace std;

class Node
{
    public:
        int data;
        Node* next;

    public:
        Node(int data1, Node* next1) {
            data = data1;
            next = next1;
        }
    public:
        Node(int data1) {
            data = data1;
            next = nullptr;
        }
};

int length(Node *head)
{
    int cnt = 0;
    Node *init = head;
    while (true)
    {
        cnt++;
        if (init->next == NULL) {
            break;
        }
    }
    init = init->next;
    return cnt;
}

int main() {
    cout << "Starting Program" << endl;
    
    return 0;
}