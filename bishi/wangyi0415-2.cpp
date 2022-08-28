#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct TreeNode{
    int value;
    TreeNode *right, *left;
    TreeNode(int _value) : value(_value), right(nullptr), left(nullptr) {}
};

TreeNode* buildTree(vector<int>& mid, int midBegin, int midEnd, vector<int>& back, int backBegin, int backEnd){
    if(backBegin == backEnd) return nullptr;
    int rootValue = back[backEnd - 1];
    TreeNode* root = new TreeNode(rootValue);
    if(backEnd - backBegin == 1) return root;
    int spiltMidIndex;
    for(spiltMidIndex = midBegin; spiltMidIndex < midEnd; ++spiltMidIndex){
        if(mid[spiltMidIndex] == rootValue) break;
    }
    int leftMidBegin = midBegin, leftMidEnd = spiltMidIndex;
    int rightMidBegin = spiltMidIndex + 1, rightMidEnd = midEnd;

    int leftBackBegin = backBegin, leftBackEnd = backBegin + spiltMidIndex - midBegin;
    int rightBackBegin = backBegin + (spiltMidIndex - midBegin), rightBackEnd = backEnd - 1;

    root->left = buildTree(mid, leftMidBegin, leftMidEnd, back, leftBackBegin, leftBackEnd);
    root->right = buildTree(mid, rightMidBegin, rightMidEnd, back, rightBackBegin, rightBackEnd);
    return root;
}

int maxDepth(TreeNode* root){
    if(root == nullptr) return 0;
    int depth = 0;
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()){
        int curLength = q.size();
        ++depth;
        for(int i = 0; i < curLength; ++i){
            TreeNode* node = q.front(); q.pop();
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }
    }
    return depth;
}

int main(){
    int N;
    cin >> N;
    vector<int> mid(N), back(N);
    for(int i = 0; i < N; ++i)
        cin >> mid[i];
    for(int i = 0; i < N; ++i)
        cin >> back[i];
    TreeNode* root = buildTree(mid, 0, N, back, 0, N);
    cout << maxDepth(root->left) + maxDepth(root->right) << endl;
    return 0; 
}

// TreeNode* buildTree(vector<int>& mid, int midBegin, int midNnd, vector<int>& back, int backBegin, int backEnd){
//     if(back.size() == 0) return nullptr;
//     int rootValue = back.back();
//     TreeNode* root = new TreeNode(rootValue);
//     if(back.size() == 1) return root;
//     int spiltMidIndex;
//     for(spiltMidIndex = 0; spiltMidIndex < mid.size(); ++spiltMidIndex){
//         if(mid[spiltMidIndex] == rootValue) break;
//     }
//     // vector<int> leftMid(mid.begin(), mid.begin() + spiltMidIndex);
//     // vector<int> rightMid(mid.begin() + spiltMidIndex + 1, mid.end());
//     int ledtMidBegin = midBegin, leftMidEnd = spiltMidIndex;
//     back.pop_back();
//     vector<int> leftBack(back.begin(), back.begin() + leftMid.size());
//     vector<int> rightBack(back.begin() + leftMid.size(), back.end());  //jiayi
//     root->left = buildTree(leftMid, leftBack);
//     root->right = buildTree(rightMid, rightBack);
//     return root;
// }