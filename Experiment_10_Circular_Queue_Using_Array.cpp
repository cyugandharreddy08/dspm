#include <iostream>
using namespace std;

const int MAX = 5; // Fixed capacity to clearly demonstrate circular wrap-around

class CircularQueue {
private:
    int arr[MAX];
    int front;
    int rear;

public:
    CircularQueue() {
        front = -1;
        rear = -1;
    }

    bool isFull() {
        return (rear + 1) % MAX == front;
    }

    bool isEmpty() {
        return front == -1;
    }

    // Insertion operation (Enqueue)
    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue Overflow! Circular Queue is full. Cannot insert " << value << ".\n";
            return;
        }

        if (isEmpty()) {
            front = 0;
            rear = 0;
        } else {
            rear = (rear + 1) % MAX;
        }

        arr[rear] = value;
        cout << "Element " << value << " inserted at index " << rear << " successfully.\n";
    }

    // Deletion operation (Dequeue)
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow! Circular Queue is empty.\n";
            return;
        }

        int deletedValue = arr[front];
        cout << "Element " << deletedValue << " deleted from index " << front << " successfully.\n";

        if (front == rear) {
            // Queue had only one element, now becomes empty
            front = -1;
            rear = -1;
        } else {
            front = (front + 1) % MAX;
        }
    }

    // Queue length operation
    int queueLength() {
        if (isEmpty()) {
            return 0;
        }
        return (rear - front + MAX) % MAX + 1;
    }

    // Peek front element
    void peek() {
        if (isEmpty()) {
            cout << "Queue is empty!\n";
            return;
        }
        cout << "Front element: " << arr[front] << " at index " << front << "\n";
    }

    // Display elements of circular queue
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty!\n";
            return;
        }

        cout << "Circular Queue elements: ";
        int i = front;
        while (true) {
            cout << arr[i] << " ";
            if (i == rear)
                break;
            i = (i + 1) % MAX;
        }
        cout << "\n";
        cout << "(Front index: " << front << ", Rear index: " << rear << ", Total elements: " << queueLength() << ")\n";
    }
};

int main() {
    CircularQueue cq;
    int choice, value;

    do {
        cout << "\n==================================\n";
        cout << "      CIRCULAR QUEUE MENU\n";
        cout << "==================================\n";
        cout << "1. Enqueue (Insert)\n";
        cout << "2. Dequeue (Delete)\n";
        cout << "3. Queue Length\n";
        cout << "4. Peek (Front Element)\n";
        cout << "5. Display Queue\n";
        cout << "6. Exit\n";
        cout << "----------------------------------\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                cq.enqueue(value);
                break;

            case 2:
                cq.dequeue();
                break;

            case 3:
                cout << "Current Queue Length: " << cq.queueLength() << "\n";
                break;

            case 4:
                cq.peek();
                break;

            case 5:
                cq.display();
                break;

            case 6:
                cout << "Program terminated successfully.\n";
                break;

            default:
                cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 6);

    return 0;
}
