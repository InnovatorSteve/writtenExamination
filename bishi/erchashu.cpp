#include<iostream>
#include<queue>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int value) : val(value), left(nullptr), right(nullptr) {}
    
};

void cnegxv(TreeNode* root){
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()){
        int curlen = q.size();
        // for(int i = 0; i < curlen; ++i){
            TreeNode* node =  q.front(); q.pop();
            cout << node->val << " ";
            if(node->left){
                q.push(node->left);
            }
            if(node->right){
                q.push(node->right);
            }
        // }

    }
}

int main(){
    TreeNode* root = new TreeNode();
    root->left = new TreeNode(1);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(5);
    root->right->right = new TreeNode(6);
    cnegxv(root);
    return 0;
}