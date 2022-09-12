    // 已知一个二叉树的先序遍历序列和中序遍历序列， 但其中一些节点的值可能相同。请你返回所有满足条件的二叉树。 二叉树在数组中的顺序是任意的。
    // 输入[1,1,2],[1,2,1]  输出[{1,1,#,#,2},{1,#,1,2}]
#include<iostream>
#include<vector>
#include<string>
using namespace std;

struct TreeNode{
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
    TreeNode(int _val) : val(_val), left(nullptr), right(nullptr) {}
};

vector<TreeNode*> buildTree(vector<int>& preOrder, int preStart, int preEnd, vector<int>& inOrder, int inStart, int inEnd){
    vector<TreeNode*> list;
    if(preStart > preEnd) {list.push_back(nullptr); return list;}
    int num = preOrder[preStart];
    int index;
    for(int i = inStart; i <= inEnd; ++i){
        if(inOrder[i] == num){
            index = i;
            vector<TreeNode*> left = buildTree(preOrder, preStart + 1, preStart + index - inStart, inOrder, inStart, index - 1);
            vector<TreeNode*> right = buildTree(preOrder, preStart + index - inStart + 1, preEnd, inOrder, index + 1, inEnd);
            for(auto l : left){
                for(auto r : right){
                    TreeNode* root = new TreeNode(num);
                    root->left = l;
                    root->right = r;
                    list.push_back(root);
                }
            }
        }
    }
    return list;
}

int main(){
    //建立初始树
    TreeNode* root;
    vector<int> preOrder = {1, 1, 2}, inOrder = {1, 2, 1};
    vector<TreeNode*> ans;
    ans = buildTree(preOrder, 0, preOrder.size() - 1, inOrder, 0, inOrder.size() - 1);    
    for(auto node : ans)
        cout << node->val << " ";
}