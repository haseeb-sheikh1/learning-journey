#include <iostream>
#include<iomanip>
using namespace std;

// Defining the Tree Node Structure
struct Node {
    int data;       // Data stored in the node
    Node* left;     // Pointer to the left child
    Node* right;    // Pointer to the right child
};

// Function to create a new node
Node* createNode(int value) {
    Node* newNode = new Node(); // Allocating memory in heap
    if (!newNode) {
        cout << "Memory error\n";
        return NULL;
    }
    newNode->data = value;      // Assigning data
    newNode->left = NULL;       // Initializing left child to NULL
    newNode->right = NULL;      // Initializing right child to NULL
    return newNode;
}

// Inorder Traversal: Left -> Root -> Right
void inorder(Node* root) {
    if (root == NULL)
        return;
    inorder(root->left);            // Visiting Left
    cout << root->data << " ";      // Visiting Root
    inorder(root->right);           // Visiting Right
}

// Preorder Traversal: Root -> Left -> Right
void preorder(Node* root) {
    if (root == NULL)
        return;
    cout << root->data << " ";      // Visiting Root
    preorder(root->left);           // Visiting Left
    preorder(root->right);          // Visiting Right
}

// Postorder Traversal: Left -> Right -> Root
void postorder(Node* root) {
    if (root == NULL)
        return;
    postorder(root->left);          // Visiting Left
    postorder(root->right);         // Visiting Right
    cout << root->data << " ";      // Visiting Root
}

int main() {
    
    cout << setfill(' ')<< setw(29)<< "Creating Tree" << endl;
    Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);

    // Displaying Traversals
    cout << "\nTree Traversals Results:" << endl;

    cout << "Inorder Traversal (Left-Root-Right):  ";
    inorder(root);
    cout << endl;

    cout << "Preorder Traversal (Root-Left-Right): ";
    preorder(root);
    cout << endl;

    cout << "Postorder Traversal (Left-Right-Root): ";
    postorder(root);
    cout << endl;
    return 0;
}



