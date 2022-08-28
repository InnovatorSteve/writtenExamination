#include<iostream>
using namespace std;

struct LinkNode{
    int val;
    LinkNode* next;
    LinkNode() : val(0), next(nullptr) {}
    LinkNode(int _val) : val(_val), next(nullptr) {}
    
};

LinkNode* delNode(LinkNode* head, LinkNode* target){
    LinkNode* dummyhead = new LinkNode(-1);
    dummyhead->next = head;
    LinkNode* cur = dummyhead;
    while(cur->next != nullptr){
        if(cur->next == target){
            cur->next = cur->next->next;
            delete target;
            target = nullptr;
            head = dummyhead->next;
            delete dummyhead;
            dummyhead = nullptr;
            return head;
        }
        cur = cur->next;
    }
     head = dummyhead->next;
    delete dummyhead;
    dummyhead = nullptr;
    return dummyhead->next;
}

int main(){
    LinkNode *head = new LinkNode();
    LinkNode* node = head;
    for(int i = 1; i < 10; ++i){
        node->next = new LinkNode(i);
        node = node->next;
    }

    head = delNode(head, head);    
    

    LinkNode* cur = head;
    while(cur != nullptr){
        cout << cur->val << " ";
        cur = cur->next;
    }

    return 0;

}