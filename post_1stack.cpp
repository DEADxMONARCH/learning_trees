#include <iostream>
#include <stack>
using namespace std;

class node {
public:
    int data;
    node* left;
    node* right;

    node(int val) {
        data = val;
        left = right = NULL;
    }
};

class solution {
public:
    void postorder(node* root) {
        if (root == NULL) return;

        node* curr = root;
        stack<node*> st;

        while (curr != NULL || !st.empty()) {
            if (curr != NULL) {
                // Go as left as possible
                st.push(curr);
                curr = curr->left;
            } else {
                node* temp = st.top()->right;

                if (temp == NULL) {
                    // Right child doesn't exist → process this node
                    temp = st.top();
                    st.pop();
                    cout << temp->data << " ";

                    // Check if this node was the right child of the new top
                    while (!st.empty() && temp == st.top()->right) {
                        temp = st.top();
                        st.pop();
                        cout << temp->data << " ";
                    }
                } else {
                    // Move to right subtree
                    curr = temp;
                }
            }
        }
    }
};

int main() {
    /*
            1
           / \
          2   3
         / \
        4   5
    */

    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);

    solution s;
    s.postorder(root);  // Expected: 4 5 2 3 1

    return 0;
}
