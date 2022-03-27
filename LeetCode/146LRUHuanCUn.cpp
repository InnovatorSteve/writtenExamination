#include<iostream>
#include<string>
#include<unordered_map>
#include<vector>
using namespace std;

struct ListNode{
    int key;
    int val;
    ListNode* next;
    ListNode* pre;
    ListNode() :key(0), val(0), next(nullptr), pre(nullptr) {}
    ListNode(int _key, int _val) : key(_key), val(_val), next(nullptr), pre(nullptr) {}
};
class LRU{
    public:
    LRU(int _capacity) : capacity(_capacity), size(0){
        head = new ListNode();
        tail = new ListNode();
        head->next = tail;
    }
    int get(int key){
        if(cache.find(key) == cache.end())
            return -1;
        MoveToHead(cache[key]);
        return cache[key]->val;
    }
    void put(int key, int val){
        if(cache.find(key) != cache.end()){
            cache[key]->val = val;
            MoveToHead(cache[key]);
        }
        else{
            ListNode* node = new ListNode(key, val);
            AddToHead(node);
            cache[key] = node;
            size++;
            if(size > capacity){
                ListNode* node = tail->pre;
                RemoveNode(node);
                --size;
                cache.erase(node->key);
                delete node;
                node = nullptr;
            }
        }
    }
    void MoveToHead(ListNode* node){
        RemoveNode(node);
        AddToHead(node);
    }
    void RemoveNode(ListNode* node){
        node->pre->next = node->next;
        node->next->pre = node->pre;
    }
    void AddToHead(ListNode* node){
        head->next->pre = node;
        node->next = head->next;
        head->next = node;
        node->pre = head;
    }
private:
    int capacity;
    int size;
    unordered_map<int, ListNode*> cache;
    ListNode* head;
    ListNode* tail;
};

int main(){
    LRU LRUcache(2);
    LRUcache.put(1, 3);
    LRUcache.put(2, 2);
    cout << LRUcache.get(1) << endl;
    
    LRUcache.put(3, 3);
    cout << LRUcache.get(2) << endl;
    LRUcache.put(4, 4);
    cout << LRUcache.get(1) << endl;
    cout << LRUcache.get(3) << endl;
    cout << LRUcache.get(4) << endl;
    return 0;

}
// int main(){
//     vector<string> input({"LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"});
//     LRU LRUCache = 
//     for(int i = 1; i < input.size(); ++i){
//         if(i == 0)
//             LRU 
//     }
// }
// int main(){
//     //手动输入操作
//     vector<string> input;
//     while(true){
//         string temp;
//         getline(cin, temp);
//         if(temp == "!")
//             break;
//         input.emplace_back(temp);
//     }
//     for(auto s : input)
//     cout << s << " ";
//     return 0;
// }