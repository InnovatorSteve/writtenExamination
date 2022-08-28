#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
vector<int> path;
vector<vector<int>> result;
    void backtracking(int k, int target, int start){
        if(target < 0) return;
        if(path.size() == k){
            if(target == 0)
                result.push_back(path);
            return;
        }
        for(int i = start; i <= 9 - (k - path.size()) + 1; ++i){
            target -= i;
            path.push_back(i);
            backtracking(k, target, i + 1);  //i + 1 而非start+1
            target += i;
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        backtracking(k, n, 1);
        return result;
    }
};

int main(){
    Solution s;
    s.combinationSum3(3, 7);
    return 0;
}