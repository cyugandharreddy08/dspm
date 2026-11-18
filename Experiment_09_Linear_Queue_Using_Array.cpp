#include <iostream>
using namespace std;

const int MAX = 100;

class LinearQueue {
private:
    int arr[MAX];
    int front;
    int rear;

public:
    LinearQueue() {
        front = -1;
        rear = -1;
    }

    bool isFull() {
        return rear == MAX - 1;
    }

    bool isEmpty() {
        return front == -1 || front > rear;
    }

    // Insertion operation (Enqueue)
    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue Overflow! Cannot insert " << value << ".\n";
            return;
        }

        if (front == -1) {
            front = 0;
        }

        rear++;
        arr[rear] = value;
        cout << "Element " << value << " inserted into queue successfully.\n";
    }

    // Deletion operation (Dequeue)
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow! Queue is empty.\n";
            return;
        }

        int deletedValue = arr[front];
        front++;

        cout << "Element " << deletedValue << " deleted from queue successfully.\n";

        // Reset queue pointers if all elements are dequeued
        if (front > rear) {
            front = -1;
            rear = -1;
        }
    }

    // Queue length operation
    int queueLength() {
        if (isEmpty()) {
            return 0;
        }
        return rear - front + 1;
    }

    // Display elements of queue
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty!\n";
            return;
        }

        cout << "Queue elements: ";
        for (int i = front; i <= rear; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }

    // Peek front element
    void peek() {
        if (isEmpty()) {
            cout << "Queue is empty!\n";
            return;
        }
        cout << "Front element: " << arr[front] << "\n";
    }
};

int main() {
    LinearQueue q;
    int choice, value;

    do {
        cout << "\n==============================\n";
        cout << "      LINEAR QUEUE MENU\n";
        cout << "==============================\n";
        cout << "1. Enqueue (Insert)\n";
        cout << "2. Dequeue (Delete)\n";
        cout << "3. Queue Length\n";
        cout << "4. Peek (Front Element)\n";
        cout << "5. Display Queue\n";
        cout << "6. Exit\n";
        cout << "------------------------------\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                q.enqueue(value);
                break;

            case 2:
                q.dequeue();
                break;

            case 3:
                cout << "Current Queue Length: " << q.queueLength() << "\n";
                break;

            case 4:
                q.peek();
                break;

            case 5:
                q.display();
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
