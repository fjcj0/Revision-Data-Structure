#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int data)
    {
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
    }
};
class BinaryTree {
public:
    Node* root;
    BinaryTree() { root = nullptr; }
    // Inorder Traversal (Left → Root → Right)
    void inorderTraversal(Node* node)
    {
        if (node != nullptr) {
            inorderTraversal(node->left);
            cout << node->data << " ";
            inorderTraversal(node->right);
        }
    }
    // Preorder Traversal (Root → Left → Right)
    void preorderTraversal(Node* node)
    {
        if (node != nullptr) {
            cout << node->data << " ";
            preorderTraversal(node->left);
            preorderTraversal(node->right);
        }
    }
    // Postorder Traversal (Left → Right → Root)
    void postorderTraversal(Node* node)
    {
        if (node != nullptr) {
            postorderTraversal(node->left);
            postorderTraversal(node->right);
            cout << node->data << " ";
        }
    }
};
int main()
{
    BinaryTree btree;
    btree.root = new Node(1);
    btree.root->left = new Node(2);
    btree.root->right = new Node(3);
    btree.root->left->left = new Node(4);
    btree.root->left->right = new Node(5);

    cout << "Inorder traversal: ";
    btree.inorderTraversal(btree.root);
    cout << endl;

    cout << "Preorder traversal: ";
    btree.preorderTraversal(btree.root);
    cout << endl;

    cout << "Postorder traversal: ";
    btree.postorderTraversal(btree.root);
    cout << endl;

    return 0;
}
