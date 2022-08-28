#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
    int n, t;
    cin >> n >> t;
    vector<int> nums(n);
    for(int i = 0; i < n; ++i){
        cin >> nums[i];
    }
    sort(nums.begin(), nums.end());
    int ans = 0;
    int time = nums[0]/t;
    int runTime = time;
    for(int i = 0; i < n; ++i){
        if(runTime > 0){
            runTime--;
            continue;
        }else{
            if(nums[i] < (time + 1) * t){
                ans++;
                continue;
            }else{
                runTime = nums[i] / t - time;
                time = nums[i] / t;
            }
        }
    }
    cout << ans; 
}