#include<iostream>
#include<unordered_map>
#include<list>
using namespace std;
struct LinkNode{
    int key, value;
    LinkNode* pre, * next;
    LinkNode(int _key, int _value, LinkNode* _pre, LinkNode* _next) : key(_key), value(_value), pre(_pre), next(_next) {}
};

// class LRUCache {
// public:
//     LRUCache(int capacity) : _capacity(capacity) {
//         cacheHead = new LinkNode(0, 0, nullptr, nullptr);
//         cacheTail = new LinkNode(0, 0, nullptr, nullptr);
//         cacheHead->next = cacheTail;
//         cacheTail->pre = cacheHead;
//     }
    
//     int get(int key) {
//         if(cacheMap.find(key) == cacheMap.end())
//             return -1;
//         update(cacheMap[key]);
//         return cacheMap[key]->value;
//     }
    
//     void put(int key, int value) {
//         if(cacheMap.find(key) == cacheMap.end()){
//             if(cacheMap.size() == _capacity){
//                 LinkNode* node = cacheTail->pre;
//                 cacheMap.erase(node->key);
//                 remove(node);
//                 delete node;
//             }
//         }else{
//             remove(cacheMap[key]);
//             delete cacheMap[key];
//         }
//         LinkNode* node = new LinkNode(key, value, nullptr, nullptr);
//         addToHead(node);
//         cacheMap[key] = node;
//         node = nullptr;
//     }

//     void update(LinkNode* node){
//         remove(node);
//         addToHead(node);
//     }
//     void addToHead(LinkNode* node){
//         node->next = cacheHead->next;
//         cacheHead->next->pre = node;
//         cacheHead->next = node;
//         node->pre = cacheHead;

//     }
//     void remove(LinkNode* node){
//         node->pre->next = node->next;
//         node->next->pre = node->pre;
//     }   
// private:
//     unordered_map<int, LinkNode*> cacheMap;
//     LinkNode* cacheHead, * cacheTail;
//     int _capacity;
// };

class LRUCache {   //STL实现
public:
    LRUCache(int capacity) : _capacity(capacity){
    }
    
    int get(int key) {
        if(_hashMap.find(key) == _hashMap.end()) return -1;
        auto it = *_hashMap[key];
        _cache.erase(_hashMap[key]);
        _cache.push_front(it);
        _hashMap[key] = _cache.begin();
        return it.second;
    }
    
    void put(int key, int value) {
        if(_hashMap.find(key) == _hashMap.end()){
            if(_cache.size() == _capacity)
                _hashMap.erase(_cache.back().first), _cache.pop_back();
        }else
            _cache.erase(_hashMap[key]);
        _cache.push_front({key, value});
        _hashMap[key] = _cache.begin();
    }
private:
    list<pair<int, int>> _cache;
    unordered_map<int, list<pair<int, int>>::iterator> _hashMap;
    int _capacity;
};

int main(){
    LRUCache* lRUCache = new LRUCache(2);
    lRUCache->put(1, 1); // 缓存是 {1=1}
    lRUCache->put(2, 2); // 缓存是 {1=1, 2=2}
    cout << lRUCache->get(1) << endl;    // 返回 1
    lRUCache->put(3, 3); // 该操作会使得关键字 2 作废，缓存是 {1=1, 3=3}
    cout << lRUCache->get(2) << endl;    // 返回 -1 (未找到)
    lRUCache->put(4, 4); // 该操作会使得关键字 1 作废，缓存是 {4=4, 3=3}
    cout << lRUCache->get(1) << endl;    // 返回 -1 (未找到)
    cout << lRUCache->get(3) << endl;    // 返回 3
    cout << lRUCache->get(4) << endl;    // 返回 4
}