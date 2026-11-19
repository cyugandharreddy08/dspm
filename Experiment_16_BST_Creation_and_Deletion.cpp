#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

Node* insertNode(Node* root, int value) {
    if (root == nullptr) {
        return new Node(value);
    }

    if (value < root->data) {
        root->left = insertNode(root->left, value);
    } else if (value > root->data) {
        root->right = insertNode(root->right, value);
    } else {
        cout << "Duplicate value " << value << " ignored in BST.\n";
    }

    return root;
}

Node* findMin(Node* root) {
    while (root && root->left != nullptr) {
        root = root->left;
    }
    return root;
}

Node* deleteNode(Node* root, int key, bool& deleted) {
    if (root == nullptr) {
        return nullptr;
    }

    if (key < root->data) {
        root->left = deleteNode(root->left, key, deleted);
    } else if (key > root->data) {
        root->right = deleteNode(root->right, key, deleted);
    } else {

        deleted = true;

        if (root->left == nullptr && root->right == nullptr) {
            delete root;
            return nullptr;
        }

        else if (root->left == nullptr) {
            Node* temp = root->right;
            delete root;
            return temp;
        }

        else if (root->right == nullptr) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        else {

            Node* temp = findMin(root->right);

            root->data = temp->data;

            bool dummy = false;
            root->right = deleteNode(root->right, temp->data, dummy);
        }
    }
    return root;
}

void inorder(Node* root) {
    if (root != nullptr) {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

void freeTree(Node* root) {
    if (root != nullptr) {
        freeTree(root->left);
        freeTree(root->right);
        delete root;
    }
}

int main() {
    Node* root = nullptr;
    int choice, val;

    do {
        cout << "\n============================================\n";
        cout << "      BINARY SEARCH TREE (BST) MENU\n";
        cout << "============================================\n";
        cout << "1. Insert Node (Creation)\n";
        cout << "2. Delete Node (All 3 Deletion Cases)\n";
        cout << "3. Inorder Traversal (Sorted Display)\n";
        cout << "4. Exit\n";
        cout << "--------------------------------------------\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> val;
                root = insertNode(root, val);
                cout << "Node " << val << " inserted successfully.\n";
                break;

            case 2:
                if (root == nullptr) {
                    cout << "Tree is empty! Cannot delete.\n";
                } else {
                    cout << "Enter value to delete: ";
                    cin >> val;
                    bool deleted = false;
                    root = deleteNode(root, val, deleted);
                    if (deleted) {
                        cout << "Node " << val << " deleted successfully.\n";
                    } else {
                        cout << "Node " << val << " not found in BST.\n";
                    }
                }
                break;

            case 3:
                if (root == nullptr) {
                    cout << "Tree is empty!\n";
                } else {
                    cout << "BST Inorder Traversal: ";
                    inorder(root);
                    cout << "\n";
                }
                break;

            case 4:
                freeTree(root);
                root = nullptr;
                cout << "Program terminated successfully.\n";
                break;

            default:
                cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}
