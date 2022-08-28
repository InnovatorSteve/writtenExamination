#include<iostream>
#include<vector>
#include<stack>
#include<unordered_map>

using namespace std;

int countMangeCost(unordered_multimap<int, int>& cinRecoder, int num, string hobby){
    int ans = 0;
    unordered_multimap<int, int> memberRelation;
    int curLeader = 1;
    while(!cinRecoder.empty()){
        auto relation = cinRecoder.equal_range(curLeader);
        for(auto it = relation.first; it != relation.second; ++it){
            memberRelation.insert({curLeader, it->second});
        }
        cinRecoder.erase(curLeader);
    }
    stack<int> stk;
    stk.push(1);
    while(!stk.empty()){
        auto relation = memberRelation
    }
}

int main(){
    int num;
    cin >> num;
    string hobby;
    cin >> hobby;
    unordered_multimap<int, int> cinRecoder;

    for(int i = 0; i < num; ++i){
        int a, b;
        cin >> a >> b;
        cinRecoder.insert({{a, b}, {b, a}});
    }
    cout << countMangeCost(cinRecoder, num, hobby) << endl; 
    return 0;
}