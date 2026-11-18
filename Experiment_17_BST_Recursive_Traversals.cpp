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

// Function to insert a node into BST
Node* insertNode(Node* root, int value) {
    if (root == nullptr) {
        return new Node(value);
    }

    if (value < root->data) {
        root->left = insertNode(root->left, value);
    } else if (value > root->data) {
        root->right = insertNode(root->right, value);
    }

    return root;
}

// Recursive Inorder Traversal: Left -> Root -> Right
void recursiveInorder(Node* root) {
    if (root != nullptr) {
        recursiveInorder(root->left);
        cout << root->data << " ";
        recursiveInorder(root->right);
    }
}

// Recursive Preorder Traversal: Root -> Left -> Right
void recursivePreorder(Node* root) {
    if (root != nullptr) {
        cout << root->data << " ";
        recursivePreorder(root->left);
        recursivePreorder(root->right);
    }
}

// Recursive Postorder Traversal: Left -> Right -> Root
void recursivePostorder(Node* root) {
    if (root != nullptr) {
        recursivePostorder(root->left);
        recursivePostorder(root->right);
        cout << root->data << " ";
    }
}

// Function to free allocated memory
void freeTree(Node* root) {
    if (root != nullptr) {
        freeTree(root->left);
        freeTree(root->right);
        delete root;
    }
}

int main() {
    Node* root = nullptr;
    int n, value;

    cout << "========================================================\n";
    cout << "    RECURSIVE BST TRAVERSALS (INORDER, PREORDER, POSTORDER)\n";
    cout << "========================================================\n";

    cout << "Enter the number of nodes to insert into the BST: ";
    cin >> n;

    if (n <= 0) {
        cout << "Invalid number of nodes.\n";
        return 1;
    }

    cout << "Enter " << n << " integers for BST creation:\n";
    for (int i = 0; i < n; i++) {
        cin >> value;
        root = insertNode(root, value);
    }

    cout << "\n--------------------------------------------------------\n";
    cout << "1. Recursive Inorder Traversal   (Left, Root, Right) :\n   ";
    recursiveInorder(root);
    cout << "\n\n2. Recursive Preorder Traversal  (Root, Left, Right) :\n   ";
    recursivePreorder(root);
    cout << "\n\n3. Recursive Postorder Traversal (Left, Right, Root) :\n   ";
    recursivePostorder(root);
    cout << "\n--------------------------------------------------------\n";

    freeTree(root);
    return 0;
}
