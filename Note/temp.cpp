#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
vector<vector<int>> ans;
vector<int> path;

void backtrace(vector<int>& bu_s, int m, int startIdx){
    if(path.size() == m){
        ans.emplace_back(path);
        return;
    }
    for(int i = startIdx; i < bu_s.size(); ++i){
        path.emplace_back(bu_s[i]);
        backtrace(bu_s, m, i + 1);
        path.pop_back();
    }
}

int main(){
    vector<int> bu_s = {1, 2, 3};
    backtrace(bu_s, 3, 0);
    cout << ans.size();
}