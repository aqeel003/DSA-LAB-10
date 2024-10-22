#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* createNode(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->left = newNode->right = nullptr;
    return newNode;
}

Node* insert(Node* root, int value) {
    if (root == nullptr) {
        return createNode(value);
    }
    if (value < root->data) {
        root->left = insert(root->left, value); 
    } else if (value > root->data) {
        root->right = insert(root->right, value);
    }
    return root;
}

bool search(Node* root, int value) { 
    if (root == nullptr) return false;
    if (root->data == value) return true;
    
    if (value < root->data) {
        return search(root->left, value); 
    } else {
        return search(root->right, value); 
    }
}

void postOrderTraversal(Node* root) {
    if (root == nullptr) return;
    
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout << root->data << " "; 
}

int main() {
    Node* root = nullptr; 
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);

    int key = 80;
    if (search(root, key)) { 
        cout << key << " Found in the BST.\n";
    } else {
        cout << key << " Not found in the BST.\n";
    }
    cout << "Post-Order traversal of the BST: ";
    postOrderTraversal(root); 
    cout << endl; 
}

