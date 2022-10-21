    // 小Q有两个整数a和b， 这两个整数的二进制存储到了两个链表中 。
    // 整数a的二进制最高位存储在链表的头节点中 ，剩下的二进制位按顺序存储。 
    // 而整数b的二进制最高位储存在链表尾中， 剩下的二进制位向链表头方向按顺序存储。
    // 小Q想对这两个数做按位异或的操作得到整数 C，希望能够将c的二进制表示同样存储在链表中输出（ 最高位存储在头节点中且无前导零）。
    // 数据范围：给定表示两个数的二进制链表， 节点个数是正整数且都不超过100000。
    // 输入：{1, 0, 1, 1}, {0, 1}  输出： {1, 0, 0, 1}
    // {1, 1, 1}, {1, 0, 1}      {1, 0}

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int _val) : val(_val), next(nullptr) {}
};

ListNode* xorList(ListNode* a, ListNode* b){
    vector<int> nums;
    ListNode* cur = a;
    while(cur){
        nums.emplace_back(cur->val);
        cur = cur->next;
    }
    reverse(nums.begin(), nums.end());
    int i = 0; cur = b;
    while(i < nums.size() && cur){
        nums[i++] ^= cur->val;
        cur = cur->next;
    }
    while(cur){
        nums.emplace_back(cur->val);
        cur = cur->next;
    }
    while(nums.back() == 0)
        nums.pop_back();
    ListNode* dummyHead = new ListNode(-1);
    cur = dummyHead;
    for(auto it = nums.rbegin(); it != nums.rend(); ++it){
        cur->next = new ListNode(*it);
        cur = cur->next;
    }
    return dummyHead->next;
}
int main(){
    vector<int> a = {1, 0, 1, 1}, b = {1, 0, 0, 1};
    ListNode* heada = new ListNode(-1), *headb = new ListNode(-1);
    ListNode* cur = heada;
    for(auto& num : a){
        cur->next = new ListNode(num);
        cur = cur->next;
    }
    cur = headb;
    for(auto& num : b){
        cur->next = new ListNode(num);
        cur = cur->next;
    }
    ListNode* ans = xorList(heada->next, headb->next);
    cur = ans;
    while(cur){
        cout << cur->val << " ";
        cur = cur->next;
    }
    return 0;
}

