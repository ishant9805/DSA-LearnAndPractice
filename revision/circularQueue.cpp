
class CircularQueue{
    private:
    int *arr;
    int size, front;
    int capacity;
    public:
    // Initialize your data structure.
    CircularQueue(int n){
        // Write your code here.
        arr = new int[n];
        size = 0;
        front = 0;
        capacity = n;
    }

    // Enqueues 'X' into the queue. Returns true if it gets pushed into the stack, and false otherwise.
    bool enqueue(int value){
        // Write your code here.
        if (size == capacity) {
            return false;
        }
        int pos = (front + size) % capacity;
        arr[pos] = value;
        size++;
        return true;
    }

    // Dequeues top element from queue. Returns -1 if the stack is empty, otherwise returns the popped element.
    int dequeue(){
        // Write your code here.
        if (size == 0) {
            return -1;
        }
        int val = arr[front];
        front = (front + 1) % capacity;
        size--;
        return val;
    }
};