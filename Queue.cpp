#include <iostream>
using namespace std;
// IMPLEMENTING LINEAR QUEUE
class LinearQueue {
    int arr[100];      // Fixed storage buffer
    int front, rear;   // Index trackers for head and tail

public:
    // Initializing pointers to indicate empty state
    LinearQueue() {
        front = rear = -1;
    }

    // Checking if queue is empty (underflow condition)
    bool isEmpty() {
        return (front == -1 || front > rear); 
    }

    // Checking if queue is full (overflow condition)
    bool isFull() {
        return (rear == 99); 
    }

    void enqueue(int value) {
        if (isFull()) return;           // To Prevent overflow
        if (front == -1) front = 0;     // Initializing front on first insertion
        arr[++rear] = value;            // Incrementing rear and store data
    }

    void dequeue() {
        if (isEmpty()) return;          // Preventing underflow 
        front++;                        // Shifting front forward to remove item 
    }

    // Retrieving front element without removing
    int peek() {
        if (isEmpty()) return -1;
        return arr[front];
    }
};

int main() {
    LinearQueue q;
    
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    cout << "Front element: " << q.peek() << endl; // Output: 10

    q.dequeue();
    cout << "Front after dequeue: " << q.peek() << endl; // Output: 20

    return 0;
}

//                                                                           IMPLEMENTING CIRCULAR QUEUE
#include <iostream>
using namespace std;

class CircularQueue {
    int arr[100];           // Fixed storage buffer 
    int front, rear, size;  // Pointers

public:
    CircularQueue() {
        front = rear = -1;
        size = 100;         
    }

    // Checking if next position wraps around to front
    bool isFull() {
        return ((rear + 1) % size == front); 
    }

    // Checking if queue contains no elements
    bool isEmpty() {
        return (front == -1); 
    }

    // Inserting element with circular wrap-around
    void enqueue(int value) {
        if (isFull()) return;               // Preventing overflow 
        if (front == -1) front = 0;         // Initializing front if queue was empty 
        rear = (rear + 1) % size;           // Moving rear circularly 
        arr[rear] = value;                  // Storing value 
    }

    void dequeue() {
        if (isEmpty()) return;              // Preventing underflow 
        if (front == rear) {
            front = rear = -1;              // Resetting queue if it becomes empty 
        } else {
            front = (front + 1) % size;     // Moving front circularly 
        }
    }

    // Retrievingfront element safely
    int peek() {
        if (isEmpty()) return -1;
        return arr[front];
    }
};

int main() {
    CircularQueue cq;

    cq.enqueue(5);
    cq.enqueue(15);
    cq.enqueue(25);

    cout << "Circular Front: " << cq.peek() << endl; // Output: 5

    cq.dequeue();
    cout << "Circular Front after dequeue: " << cq.peek() << endl; // Output: 15

    return 0;
}
//                                                                               QUEUE USING LINKED LIST

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
}; 

class LinkedQueue {
    Node *front, *rear; // Pointers to head and tail nodes 

public:
    LinkedQueue() {
        front = rear = nullptr; 
    }

    // Inserting new node at the rear
    void enqueue(int value) {
        Node* temp = new Node();        // Allocating new memory
        temp->data = value;
        temp->next = nullptr;           

        if (rear == nullptr) {
            front = rear = temp;        // Setting both pointers if list is empty
        } else {
            rear->next = temp;          // Linking current rear to new node 
            rear = temp;                // Updating rear pointer 
        }
    }

    // Removing node from the front
    void dequeue() {
        if (front == nullptr) return;   // Preventing underflow 
        
        Node* temp = front;             // Storing node to be deleted 
        front = front->next;            // Advancing front pointer 

        if (front == nullptr) {
            rear = nullptr;             // Updating rear if list becomes empty 
        }
        delete temp;                    // Deallocating memory 
    }

    // Retrieving front element data
    int peek() {
        if (front == nullptr) return -1;
        return front->data;
    }
};

int main() {
    LinkedQueue lq;

    lq.enqueue(100);
    lq.enqueue(200);

    cout << "Linked Queue Front: " << lq.peek() << endl; // Output: 100

    lq.dequeue();
    cout << "Linked Queue Front after dequeue: " << lq.peek() << endl; // Output: 200

    return 0;
}
