#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

// Insert node in BST
Node* insert(Node* root, int key) {
    if (!root) return new Node(key);
    if (key < root->data) root->left = insert(root->left, key);
    else if (key > root->data) root->right = insert(root->right, key);
    return root;
}

// Find minimum node in a subtree
Node* findMin(Node* root) {
    while (root && root->left) root = root->left;
    return root;
}

// Find maximum node in a subtree
Node* findMax(Node* root) {
    while (root && root->right) root = root->right;
    return root;
}

// Search for a node by value
Node* search(Node* root, int key) {
    if (!root) return nullptr;
    if (root->data == key) return root;
    if (key < root->data) return search(root->left, key);
    return search(root->right, key);
}

// Inorder successor
Node* inorderSuccessor(Node* root, int key) {
    Node* target = search(root, key);
    if (!target) return nullptr;

    if (target->right) return findMin(target->right);

    Node* succ = nullptr;
    Node* curr = root;
    while (curr) {
        if (key < curr->data) {
            succ = curr;
            curr = curr->left;
        } else if (key > curr->data) {
            curr = curr->right;
        } else break;
    }
    return succ;
}

// Inorder predecessor
Node* inorderPredecessor(Node* root, int key) {
    Node* target = search(root, key);
    if (!target) return nullptr;

    if (target->left) return findMax(target->left);

    Node* pred = nullptr;
    Node* curr = root;
    while (curr) {
        if (key > curr->data) {
            pred = curr;
            curr = curr->right;
        } else if (key < curr->data) {
            curr = curr->left;
        } else break;
    }
    return pred;
}

int main() {
    Node* root = nullptr;
    root = insert(root, 20);
    root = insert(root, 8);
    root = insert(root, 22);
    root = insert(root, 4);
    root = insert(root, 12);
    root = insert(root, 10);
    root = insert(root, 14);

    int value;
    cout << "Enter node value: ";
    cin >> value;

    Node* succ = inorderSuccessor(root, value);
    Node* pred = inorderPredecessor(root, value);

    if (succ) cout << "Successor of " << value << " is " << succ->data << endl;
    else cout << "No successor\n";

    if (pred) cout << "Predecessor of " << value << " is " << pred->data << endl;
    else cout << "No predecessor\n";

    return 0;
}
