//最大匹配
#include<iostream>
#include<map>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;
struct Mycmp{
    bool operator()(const pair<int, int>& a, const pair<int, int>& b){
        return a.second < b.second;
    }
};
int main(){
    int n;
    cin >> n;
    vector<int> staffs(n - 1);
    map<int, int> cntFre;
    map<int, vector<int>> relation;
    for(int i = 0; i < n - 1; ++i){
        cin >> staffs[i];
        cntFre[staffs[i]]++;
        relation[staffs[i]].emplace_back(i + 2);
    }
    cntFre[1]--;
    int ans = 0;
    vector<pair<int, int>> map_to_vec(cntFre.begin(), cntFre.end());
    sort(map_to_vec.begin(), map_to_vec.end(), Mycmp());
    set<int> visted;
    for(int i = 0; i < map_to_vec.size(); ++i){
        if(visted.find(map_to_vec[i].first) == visted.end()){
            bool flag = false;
            for(int j = 0; j < relation[map_to_vec[i].first].size(); ++j){
                if(visted.find(relation[map_to_vec[i].first][j]) == visted.end()){
                    visted.insert(map_to_vec[i].first);
                    visted.insert(relation[map_to_vec[i].first][j]);
                    flag = true;
                }
            }
            if(flag) ++ans;
        }
    }
    cout << ans;
    return 0;
}