#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

Node* createNode(int value)
{
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = nullptr;
    return newNode;
}

void insertAtBeginning(Node*& head, int value)
{
    Node* newNode = createNode(value);
    newNode->next = head;
    head = newNode;
    cout << "Node inserted at the beginning successfully.\n";
}

void insertAtEnd(Node*& head, int value)
{
    Node* newNode = createNode(value);

    if (head == nullptr)
    {
        head = newNode;
        cout << "Node inserted at the end successfully.\n";
        return;
    }

    Node* temp = head;

    while (temp->next != nullptr)
    {
        temp = temp->next;
    }

    temp->next = newNode;

    cout << "Node inserted at the end successfully.\n";
}

void insertAtPosition(Node*& head, int value, int position)
{
    if (position < 1)
    {
        cout << "Invalid position.\n";
        return;
    }

    if (position == 1)
    {
        insertAtBeginning(head, value);
        return;
    }

    Node* temp = head;

    for (int i = 1; i < position - 1 && temp != nullptr; i++)
    {
        temp = temp->next;
    }

    if (temp == nullptr)
    {
        cout << "Invalid position.\n";
        return;
    }

    Node* newNode = createNode(value);
    newNode->next = temp->next;
    temp->next = newNode;

    cout << "Node inserted at position " << position << " successfully.\n";
}

void deleteFromBeginning(Node*& head)
{
    if (head == nullptr)
    {
        cout << "List is empty.\n";
        return;
    }

    Node* temp = head;
    head = head->next;
    delete temp;

    cout << "Node deleted from the beginning successfully.\n";
}

void deleteFromEnd(Node*& head)
{
    if (head == nullptr)
    {
        cout << "List is empty.\n";
        return;
    }

    if (head->next == nullptr)
    {
        delete head;
        head = nullptr;
        cout << "Node deleted from the end successfully.\n";
        return;
    }

    Node* temp = head;

    while (temp->next->next != nullptr)
    {
        temp = temp->next;
    }

    delete temp->next;
    temp->next = nullptr;

    cout << "Node deleted from the end successfully.\n";
}

void deleteFromPosition(Node*& head, int position)
{
    if (head == nullptr)
    {
        cout << "List is empty.\n";
        return;
    }

    if (position < 1)
    {
        cout << "Invalid position.\n";
        return;
    }

    if (position == 1)
    {
        deleteFromBeginning(head);
        return;
    }

    Node* temp = head;

    for (int i = 1; i < position - 1 && temp != nullptr; i++)
    {
        temp = temp->next;
    }

    if (temp == nullptr || temp->next == nullptr)
    {
        cout << "Invalid position.\n";
        return;
    }

    Node* nodeToDelete = temp->next;
    temp->next = nodeToDelete->next;
    delete nodeToDelete;

    cout << "Node deleted from position " << position << " successfully.\n";
}

void createList(Node*& head)
{
    int n, value;

    while (head != nullptr)
    {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    cout << "Enter the number of nodes: ";
    cin >> n;

    if (n <= 0)
    {
        cout << "Invalid number of nodes.\n";
        return;
    }

    for (int i = 1; i <= n; i++)
    {
        cout << "Enter data for node " << i << ": ";
        cin >> value;
        insertAtEnd(head, value);
    }

    cout << "Linked List created successfully.\n";
}

void displayList(Node* head)
{
    if (head == nullptr)
    {
        cout << "List is empty.\n";
        return;
    }

    Node* temp = head;
    cout << "Linked List: ";

    while (temp != nullptr)
    {
        cout << temp->data;
        if (temp->next != nullptr)
        {
            cout << " -> ";
        }
        temp = temp->next;
    }

    cout << " -> NULL\n";
}

void freeList(Node*& head)
{
    Node* temp;
    while (head != nullptr)
    {
        temp = head;
        head = head->next;
        delete temp;
    }
}

int main()
{
    Node* head = nullptr;
    int choice;
    int value;
    int position;

    do
    {
        cout << "\n============================\n";
        cout << "       SINGLY LINKED LIST MENU\n";
        cout << "==============================\n";
        cout << "1.  Create Linked List\n";
        cout << "2.  Insert at Beginning\n";
        cout << "3.  Insert at Any Position\n";
        cout << "4.  Insert at End\n";
        cout << "5.  Delete from Beginning\n";
        cout << "6.  Delete from Any Position\n";
        cout << "7.  Delete from End\n";
        cout << "8.  Display Linked List\n";
        cout << "9.  Exit\n";
        cout << "----------------------------------------\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                createList(head);
                break;

            case 2:
                cout << "Enter value to insert: ";
                cin >> value;
                insertAtBeginning(head, value);
                break;

            case 3:
                cout << "Enter value to insert: ";
                cin >> value;
                cout << "Enter position: ";
                cin >> position;
                insertAtPosition(head, value, position);
                break;

            case 4:
                cout << "Enter value to insert: ";
                cin >> value;
                insertAtEnd(head, value);
                break;

            case 5:
                deleteFromBeginning(head);
                break;

            case 6:
                cout << "Enter position to delete: ";
                cin >> position;
                deleteFromPosition(head, position);
                break;

            case 7:
                deleteFromEnd(head);
                break;

            case 8:
                displayList(head);
                break;

            case 9:
                freeList(head);
                cout << "Program terminated successfully.\n";
                break;

            default:
                cout << "Invalid choice! Please try again.\n";
        }

    } while (choice != 9);

    return 0;
}
