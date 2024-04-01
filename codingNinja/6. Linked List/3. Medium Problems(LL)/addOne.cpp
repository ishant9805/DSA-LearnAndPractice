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
Node* constructLL(vector<int>& arr);
void PrintLL(Node* head);
// Naive
// Node* addOne(Node* head) {
//     Node *tmp = head;
//     bool notNineF = false;
//     Node* notNine;
//     while (tmp->next) {
//         if (tmp->data != 9) {
//             notNineF = true;
//             notNine = tmp;
//         }
//         tmp = tmp->next;
//     }
//     if (tmp->data != 9) {
//         tmp->data++;
//         return head;
//     }
//     if (notNineF) {
//         notNine->data++;
//         notNine = notNine->next;
//         while(notNine) {
//             notNine->data = 0;
//             notNine = notNine->next;
//         }
//         return head;
//     }
//     Node* newHead = new Node(1, head);
//     while(head) {
//         head->data = 0;
//         head = head->next;
//     }
//     return newHead;
// }

// Using recursion
int carry(Node* head) {
    if (head == NULL) {
        return 1;
    }
    int x = carry(head->next);
    int y = head->data;
    y += x;
    if (y >= 10) {
        head->data = y % 10;
        return y / 10;
    }
    head->data = y;
    return 0;
}

Node* addOne(Node* head) {
    int car = carry(head);
    if (car == 1) {
        Node* nH = new Node(1, head);
        return nH;
    }
    return head;
}

int main() {
    cout << "Starting Program" << endl;
    vector<int> v1 = {1, 5, 5, 0, 9, 0, 7, 5, 1, 9, 6, 0, 5, 0, 1, 2, 8, 5, 6, 1, 7, 8};
    Node* head = constructLL(v1);
    PrintLL(head);
    head = addOne(head);
    PrintLL(head);
    v1 = {1,2,3,9,4,3,9,9,9};
    head = constructLL(v1);
    PrintLL(head);
    head = addOne(head);
    PrintLL(head);
    return 0;
}

Node* constructLL(vector<int>& arr) {
    int len = arr.size();
    Node* prev = new Node(arr[0], nullptr);
    Node* head = prev;
    for (int i = 1; i < len; i++) {
        Node *temp = new Node(arr[i]);
        prev -> next = temp;
        prev = temp;
    }
    return head;
}

void PrintLL(Node* head) {
    if (head == nullptr) {
        cout << "There is nothing in LL to print🙂" << endl;
    } else {
        cout << "[";
        while(head->next != nullptr) {
            cout << head->data << ", ";
            head = head->next;
        }
        cout << head->data << "]" << endl;
    }
}
