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
    pair<ListNode*, ListNode*> reverseGroup(ListNode* head, ListNode* tail){
        ListNode* pre = nullptr, *cur = head;
        while(pre != tail){
            ListNode* next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        return {tail, head};
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* hair = new ListNode(-1);
        hair->next = head;
        ListNode* pre = hair;
        while(pre->next){
            ListNode* tail = pre;
            for(int i = 0; i < k; ++i){
                tail = tail->next;
                if(!tail)
                    return hair->next;
            }
            ListNode* next = tail->next;
            pair<ListNode*, ListNode*> it = reverseGroup(head, tail);
            head = it.first; tail = it.second;
            pre->next = head;
            tail->next = next;
            pre = tail;
            head = tail->next;
        }
        return hair->next;
    }
};

int main(){
    ListNode *head = new ListNode(1);
    ListNode *cur = head;
    for(int i = 2; i < 6; ++i){
        cur->next = new ListNode(i);
        cur = cur->next;
    }
    Solution s;
    head = s.reverseKGroup(head, 2);
    return 0;
}