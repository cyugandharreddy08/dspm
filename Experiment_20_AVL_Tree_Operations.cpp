#include <iostream>
#include <algorithm>
using namespace std;

struct Node {
    int key;
    Node* left;
    Node* right;
    int height;

    Node(int val) {
        key = val;
        left = nullptr;
        right = nullptr;
        height = 1;
    }
};

int getHeight(Node* node) {
    if (node == nullptr)
        return 0;
    return node->height;
}

int getBalanceFactor(Node* node) {
    if (node == nullptr)
        return 0;
    return getHeight(node->left) - getHeight(node->right);
}

Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

    return x;
}

Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

    return y;
}

Node* insertAVL(Node* node, int key) {

    if (node == nullptr)
        return new Node(key);

    if (key < node->key)
        node->left = insertAVL(node->left, key);
    else if (key > node->key)
        node->right = insertAVL(node->right, key);
    else {
        cout << "Duplicate key " << key << " is not allowed in AVL Tree.\n";
        return node;
    }

    node->height = 1 + max(getHeight(node->left), getHeight(node->right));

    int balance = getBalanceFactor(node);

    if (balance > 1 && key < node->left->key) {
        cout << "Unbalance detected at node " << node->key << " (Balance Factor: " << balance << "). Performing LL (Right) Rotation.\n";
        return rightRotate(node);
    }

    if (balance < -1 && key > node->right->key) {
        cout << "Unbalance detected at node " << node->key << " (Balance Factor: " << balance << "). Performing RR (Left) Rotation.\n";
        return leftRotate(node);
    }

    if (balance > 1 && key > node->left->key) {
        cout << "Unbalance detected at node " << node->key << " (Balance Factor: " << balance << "). Performing LR (Left-Right) Rotation.\n";
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    if (balance < -1 && key < node->right->key) {
        cout << "Unbalance detected at node " << node->key << " (Balance Factor: " << balance << "). Performing RL (Right-Left) Rotation.\n";
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

void inorder(Node* root) {
    if (root != nullptr) {
        inorder(root->left);
        cout << root->key << "(BF: " << getBalanceFactor(root) << ") ";
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
    int choice, key;

    do {
        cout << "\n============================================\n";
        cout << "            AVL TREE OPERATIONS\n";
        cout << "============================================\n";
        cout << "1. Insert Key (With Automatic LL/RR/LR/RL Rotations)\n";
        cout << "2. Inorder Traversal (Sorted Keys & Balance Factors)\n";
        cout << "3. Calculate Tree Height\n";
        cout << "4. Exit\n";
        cout << "--------------------------------------------\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter integer key to insert: ";
                cin >> key;
                root = insertAVL(root, key);
                cout << "Key " << key << " inserted successfully.\n";
                break;

            case 2:
                if (root == nullptr) {
                    cout << "AVL Tree is empty!\n";
                } else {
                    cout << "Inorder Traversal: ";
                    inorder(root);
                    cout << "\n";
                }
                break;

            case 3:
                cout << "Height of AVL Tree: " << getHeight(root) << "\n";
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
