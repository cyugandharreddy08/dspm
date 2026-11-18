#include <iostream>
using namespace std;

// Structure for a BST node
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

// Function to insert a node into BST (Creation)
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

// Function to find the minimum value node in a subtree (Inorder Successor)
Node* findMin(Node* root) {
    while (root && root->left != nullptr) {
        root = root->left;
    }
    return root;
}

// Function to delete a node from BST handling all deletion cases:
// Case 1: Node has no children (Leaf node)
// Case 2: Node has one child (Left or Right)
// Case 3: Node has two children (Replace with Inorder Successor)
Node* deleteNode(Node* root, int key, bool& deleted) {
    if (root == nullptr) {
        return nullptr;
    }

    if (key < root->data) {
        root->left = deleteNode(root->left, key, deleted);
    } else if (key > root->data) {
        root->right = deleteNode(root->right, key, deleted);
    } else {
        // Node found
        deleted = true;

        // Case 1: Leaf node (no children)
        if (root->left == nullptr && root->right == nullptr) {
            delete root;
            return nullptr;
        }
        // Case 2a: Only right child exists
        else if (root->left == nullptr) {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        // Case 2b: Only left child exists
        else if (root->right == nullptr) {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        // Case 3: Two children exist
        else {
            // Find inorder successor (smallest in the right subtree)
            Node* temp = findMin(root->right);

            // Copy inorder successor's content to this node
            root->data = temp->data;

            // Delete the inorder successor from right subtree
            bool dummy = false;
            root->right = deleteNode(root->right, temp->data, dummy);
        }
    }
    return root;
}

// Inorder traversal to display BST elements in sorted order
void inorder(Node* root) {
    if (root != nullptr) {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

// Function to free all nodes of BST
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
