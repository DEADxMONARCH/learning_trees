#include<iostream>
#include<queue>
#include<stack>
using namespace std;
class node{
    public:
    int data ;
    node* left;
    node* right;
    node(int val){
        data = val;
        left = right = NULL;
    }
};
class solution{
    public:
    vector<vector<int>> levelorder(node* root){
        vector<vector<int>>ans;
        if(root == NULL) return ans;
        queue<node*> q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            vector<int> level;
            for(int i = 0; i < size; i++){
                node* curr = q.front();
                q.pop();
                level.push_back(curr->data);
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
            ans.push_back(level);
        }
        return ans;
    }
};
