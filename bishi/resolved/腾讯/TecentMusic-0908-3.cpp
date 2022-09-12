    // 给定一棵二叉树， 二叉树的每个结点只有0或2个孩子。 
    // 你需要对每个结点赋值一个正整数，使得每个结点的 左右子树权值和相等。 
    // 你需要返回所有结点的最小权值和对 10^9+7取模的结果。
    // 二叉树结点个数不超过10^5。
    // 输入{0,0,0}          输出3
    //解释 根节点 左右孩子均赋值为1

#include<iostream>
#include<math.h>
using namespace std;
struct TreeNode{
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
long setAndCount(TreeNode* tree){
    if(tree == nullptr) return 0;
    if(tree->left == nullptr) return 1;
    long lSum = setAndCount(tree->left);
    long rSum = setAndCount(tree->right);
    if(lSum == rSum)
        return lSum + rSum + 1;
    else
        return max(lSum, rSum) * 2 + 1;

}

int getTreeSum(TreeNode* tree){
    return (int)(setAndCount(tree) % ((long)pow(10, 9) + 7));
}
int main(){
    TreeNode* root = new TreeNode(0);
    root->left = new TreeNode(0);
    root->right = new TreeNode(0);
    int ans = 0;
    ans = getTreeSum(root);
    cout << ans << endl;
}