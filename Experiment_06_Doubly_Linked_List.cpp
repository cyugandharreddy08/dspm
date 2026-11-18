#include <iostream> 
using namespace std; 
 
struct Node { 
    int data; 
    Node* prev; 
    Node* next; 
}; 
 
Node* head = nullptr; 
Node* tail = nullptr; 
 
// Insert at the beginning 
void insertBeginning(int value) { 
    Node* newNode = new Node{value, nullptr, head}; 
 
    if (head == nullptr) { 
        head = tail = newNode; 
    } else { 
        head->prev = newNode; 
        head = newNode; 
    } 
} 
 
// Insert at the end 
void insertEnd(int value) { 
    Node* newNode = new Node{value, tail, nullptr}; 
 
    if (tail == nullptr) { 
        head = tail = newNode; 
    } else { 
        tail->next = newNode; 
        tail = newNode; 
    } 
} 
 
// Insert at a specific position (1-based) 
void insertPosition(int value, int position) { 
    if (position < 1) { 
        cout << "Invalid position!\n"; 
        return; 
    } 
 
    if (position == 1) { 
        insertBeginning(value); 
        return; 
    } 
 
    Node* current = head; 
 
    for (int i = 1; current != nullptr && i < position - 1; i++) { 
        current = current->next; 
    } 
 
    if (current == nullptr) { 
        cout << "Invalid position!\n"; 
        return; 
    } 
 
    Node* newNode = new Node{value, current, current->next}; 
 
    if (current->next != nullptr) { 
        current->next->prev = newNode; 
    } else { 
        tail = newNode; 
    } 
 
    current->next = newNode; 
} 
 
// Delete from the beginning 
void deleteBeginning() { 
    if (head == nullptr) { 
        cout << "List is empty!\n"; 
        return; 
    } 
 
    Node* temp = head; 
    head = head->next; 
 
    if (head != nullptr) { 
        head->prev = nullptr; 
    } else { 
        tail = nullptr; 
    } 
 
    delete temp; 
    cout << "First node deleted.\n"; 
} 
 
// Delete from the end 
void deleteEnd() { 
    if (tail == nullptr) { 
        cout << "List is empty!\n"; 
        return; 
    } 
 
    Node* temp = tail; 
    tail = tail->prev; 
 
    if (tail != nullptr) { 
        tail->next = nullptr; 
    } else { 
        head = nullptr; 
    } 
 
    delete temp; 
    cout << "Last node deleted.\n"; 
} 
 
// Delete from a specific position (1-based) 
void deletePosition(int position) { 
    if (position < 1 || head == nullptr) { 
        cout << "Invalid position or empty list!\n"; 
        return; 
    } 
 
    if (position == 1) { 
        deleteBeginning(); 
        return; 
    } 
 
    Node* current = head; 
 
    for (int i = 1; current != nullptr && i < position; i++) { 
        current = current->next; 
    } 
 
    if (current == nullptr) { 
        cout << "Invalid position!\n"; 
        return; 
    } 
 
    if (current->prev != nullptr) { 
        current->prev->next = current->next; 
    } 
 
    if (current->next != nullptr) { 
        current->next->prev = current->prev; 
    } else { 
        tail = current->prev; 
    } 
 
    delete current; 
    cout << "Node deleted.\n"; 
} 
 
// Forward traversal 
void displayForward() { 
    if (head == nullptr) { 
        cout << "List is empty!\n"; 
        return; 
    } 
 
    Node* current = head; 
    cout << "Forward: "; 
 
    while (current != nullptr) { 
        cout << current->data << " "; 
        current = current->next; 
    } 
    cout << endl; 
} 
 
// Reverse traversal 
void displayReverse() { 
    if (tail == nullptr) { 
        cout << "List is empty!\n"; 
        return; 
    } 
 
    Node* current = tail; 
    cout << "Reverse: "; 
 
    while (current != nullptr) { 
        cout << current->data << " "; 
        current = current->prev; 
    } 
    cout << endl; 
} 
 
// Release allocated memory 
void clearList() { 
    while (head != nullptr) { 
        Node* temp = head; 
        head = head->next; 
        delete temp; 
    } 
    tail = nullptr; 
} 
 
int main() { 
    int choice, value, position; 
 
    do { 
        cout << "\n--- Doubly Linked List Menu ---\n"; 
        cout << "1. Insert at Beginning\n"; 
        cout << "2. Insert at a Position\n"; 
        cout << "3. Insert at End\n"; 
        cout << "4. Delete from Beginning\n"; 
        cout << "5. Delete from a Position\n"; 
        cout << "6. Delete from End\n"; 
        cout << "7. Display Forward\n"; 
        cout << "8. Display Reverse\n"; 
        cout << "9. Exit\n"; 
        cout << "Enter your choice: "; 
        cin >> choice; 
 
        switch (choice) { 
            case 1: 
                cout << "Enter value: "; 
                cin >> value; 
                insertBeginning(value); 
                break; 
 
            case 2: 
                cout << "Enter value and position: "; 
                cin >> value >> position; 
                insertPosition(value, position); 
                break; 
 
            case 3: 
                cout << "Enter value: "; 
                cin >> value; 
                insertEnd(value); 
                break; 
 
            case 4: 
                deleteBeginning(); 
                break; 
 
            case 5: 
                cout << "Enter position: "; 
                cin >> position; 
                deletePosition(position); 
                break; 
 
            case 6: 
                deleteEnd(); 
                break; 
 
            case 7: 
                displayForward(); 
                break; 
 
            case 8: 
                displayReverse(); 
                break; 
 
            case 9: 
                clearList(); 
                cout << "Program terminated.\n"; 
                break; 
 
            default: 
                cout << "Invalid choice!\n"; 
        } 
    } while (choice != 9); 
 
    return 0; 
}
