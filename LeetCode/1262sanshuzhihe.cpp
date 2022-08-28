#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
         int N = nums.size();
        int remainder[3] = {0};
        for(int i = 0; i < N; i++){
            int a,b,c;
            a = remainder[0] + nums[i];
            b = remainder[1] + nums[i];
            c = remainder[2] + nums[i];
            remainder[a%3] = max(remainder[a%3], a);
            remainder[b%3] = max(remainder[b%3], b);
            remainder[c%3] = max(remainder[c%3], c);
        }
        return remainder[0];
    }
    int maxSumDiv(vector<int>& nums){
        int k = 3;
        vector<int> state(k); //状态机 保存余数[0, k-1]状态，加上一个新树 讲改变后的新状态继续保存到对应状态里  加到最后一个 stat[0]就是所求
        for(const auto num : nums){
            vector<int> temp(state);
            for(int j = 0; j < k; ++j)
                state[(temp[j] + num) % 3] = max(state[(temp[j] + num) % 3], temp[j] + num);
                //状态0~k-1 分别加上当前数字， 求余得到对应的状态i 进行判断组成旧状态i的数字之和大还是 由加上当前数字转移而来的状态i 组成的数字之和大
        }
        return state[0];
    }
};

int main(){
    vector<int> nums = {3,6,5,1,8};
    Solution s;
    cout <<  s.maxSumDiv(nums);
    return 0;
}