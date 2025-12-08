#include <iostream>
#include <algorithm>   // <-- added for std::max
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

    int diameterofbinary(node* root) {
        int diameter = 0;
        height(root, diameter);
        return diameter;
    }

private:
    int height(node* root, int &diameter) {
        if (root == NULL) {      // base case
            return 0;
        }

        int lh = height(root->left, diameter);   // left height
        int rh = height(root->right, diameter);  // right height

        // update diameter: longest path through this node
        diameter = max(diameter, lh + rh + 1);

        // return height of this subtree
        return 1 + max(lh, rh);
    }
};
