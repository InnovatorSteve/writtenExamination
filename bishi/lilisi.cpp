#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void minabs(vector<int>& nums){
    vector<int> temp(nums);
    temp.insert(temp.end(), nums.begin(), nums.end());
    int sum = 0;
    for(auto num : nums) sum += num;    
    int ans = INT_MAX;
    for(int i = 0; i < nums.size(); ++i){
        int cur_sum = 0;
        for(int j = i; j < i + nums.size() - 1; ++j){
            cur_sum += temp[j];
            ans = min(ans, abs(cur_sum - (sum - cur_sum)));
        }
    }
    cout << ans << endl;
}

int main(){
    vector<int> nums = {7, 5, 3, 6, 4, 2, 1};
    minabs(nums); 
    return 0;
}