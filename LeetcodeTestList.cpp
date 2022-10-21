#include<iostream>
#include<vector>

using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* merge(ListNode* l1, ListNode* l2){
        ListNode* dummyNode = new ListNode(0);
        ListNode* curNode = dummyNode;
        while(l1 && l2){
            if(l1->val < l2->val)
                curNode->next = l1, l1 = l1->next;
            else
                curNode->next = l2, l2 = l2->next;
            curNode = curNode->next;
        }
        curNode->next = l1 ? l1 : l2;
        return dummyNode->next;//删除dummyNode
    }
    ListNode* sortList(ListNode* head) {
        int n = 0;
        ListNode* dummyNode = new ListNode(0, head);
        ListNode* curNode = head;
        while(curNode) ++n, curNode = curNode->next;
        for(int step = 1; step < n; step += step){
            ListNode* preNode = dummyNode; curNode = dummyNode->next;
            while(curNode){
                ListNode* l1 = curNode;
                for(int i = 1; curNode->next && i < step; ++i) curNode = curNode->next;  //走到最后一个节点 或者步长
                ListNode* l2 = curNode->next;//保证了  curNode不为空
                curNode->next = nullptr;  //切断l1末尾  方便合并

                curNode = l2;  //l2可能为空
                ListNode* next = nullptr;
                if(curNode){
                    for(int i = 1; curNode->next && i < step; ++i) curNode = curNode->next;
                    next = curNode->next;
                    curNode->next = nullptr;
                }
                preNode->next = merge(l1, l2);
                while(preNode->next) preNode = preNode->next;
                curNode = next;
            }
        }
        return dummyNode->next;
    }
};
int main(){
    vector<int> nums1 = {4, 2, 1, 3};
    ListNode* head1 = new ListNode(nums1[0]);
    ListNode* cur = head1;
    for(int i = 1; i < nums1.size(); ++i){
        cur->next = new ListNode(nums1[i]);
        cur = cur->next;
    }
    // vector<int> nums2 = {1, 3};
    // ListNode* head2 = new ListNode(nums2[0]);
    // cur = head2;
    // for(int i = 1; i < nums2.size(); ++i){
    //     cur->next = new ListNode(nums2[i]);
    //     cur = cur->next;
    // }
    Solution s;
    // ListNode* newHead = s.merge(head1, head2);
    s.sortList(head1);
    return 0;
}