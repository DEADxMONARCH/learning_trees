#include <iostream>
using namespace std;
// declaring trees
class node {
    public :
    int data ;
    node* left;
    node* right;
    node(int val){
        data = val;
        left = right = NULL;
    }
};
// Preorder traversal of a binary tree
void preorder (node* node){
    if (node == NULL) return;
    cout << node->data << " ";
    preorder(node->left);
    preorder(node->right);
}
// inorder raversal of a binary tree
void inorder (node* node){
    if (node == NULL) return;
    inorder(node->left);
    cout << node->data << " ";
    inorder(node->right);
}