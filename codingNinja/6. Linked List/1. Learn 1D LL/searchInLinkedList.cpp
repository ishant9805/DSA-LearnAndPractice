#include<bits/stdc++.h>

using namespace std;

template <typename T>
class Node
{
public:
    T data;
    Node<T> *next;
    Node()
    {
        this->data = 0;
        this->next = NULL;
    }
    Node(T data)
    {
        this->data = data;
        this->next = NULL;
    }
    Node(T data, T* next)
    {
        this->data = data;
        this->next = next;
    }
};

int searchInLinkedList(Node<int> *head, int k) {
    Node<int> *temp = head;
    while (true)
    {
        if (temp->data == k) {
            return 1;
        }
        if (temp->next == NULL) {
            return 0;
        }
        temp = temp->next;
    }
    return 0;
}

int main() {
    cout << "Starting Program" << endl;
    
    return 0;
}