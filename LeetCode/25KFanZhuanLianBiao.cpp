#include<iostream>
#include<vector>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int _val) : val(_val), next(nullptr) {}
};
pair<ListNode*, ListNode*> reverseGroup(ListNode* head, ListNode* tail){
    ListNode* pre = tail->next, *cur = head;
    while(pre != tail){
        ListNode* next = cur->next;
        cur->next = pre;
        pre = cur;
        cur = next;
    }
    return {tail, head};
}

ListNode* reverseKGroup(ListNode* head, int k){
    ListNode* hair = new ListNode(-1);
    hair->next = head;
    ListNode* pre = hair;
    while(head){
        ListNode* tail = pre;
        for(int i = 0; i < k; ++i){
            tail = tail->next;
            if(!tail)
                return hair->next;
        }
        ListNode* next = tail->next;
        pair<ListNode*, ListNode*> it = reverseGroup(head, tail);
        head = it.first, tail = it.second;
        pre->next = head;
        tail->next = next;
        pre = tail;
        head = tail->next;
    }
    return hair->next;
}

int main(){
    vector<int> nums({1, 2, 3, 4, 5});
    ListNode* dummyNode = new ListNode(-1);
    ListNode* cur = dummyNode;
    for(auto num : nums){
        cur->next = new ListNode(num);
        cur = cur->next;
    }
    ListNode* head = dummyNode->next;
    delete dummyNode;
    dummyNode = cur = nullptr;
    head = reverseKGroup(head, 2);
    cur = head;
    while(cur)
        cout << cur->val << " ", cur = cur->next;
    cout << endl;
    return 0;
}