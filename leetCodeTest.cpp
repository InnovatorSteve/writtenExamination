#include<iostream>
#include<string>
#include<stack>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<algorithm>
#include<numeric>
#include<random>
#include<sys/time.h>
#include<ctime>

using namespace std;

#define BUCKETSIZE 10
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int minNum = *min_element(nums.begin(), nums.end());
        int maxNum = *max_element(nums.begin(), nums.end());
        int bucketCnt = (maxNum - minNum) / 10;
        vector<vector<int>> bucket(bucketCnt + 1);
        for(auto& num : nums){
            int index = (num - minNum) / 10;
            if(bucket[index].empty()) bucket[index].emplace_back(num);
            for(int i = 0; i < bucket[index].size(); ++i) {
                if(num > bucket[index][i]){
                    bucket[index].insert(bucket[index].begin() + i + 1, num);
                    break;
                }
            }
        }
        int index = 0;
        for(auto& line : bucket){
            for(auto& num : line)
                nums[index++] = num;
        }
        return nums;
    }
};

int main(){
    clock_t startTime = clock();
    vector<int> nums{5,1,1,2,0,0};
    Solution s;
    s.sortArray(nums);
    clock_t endTime = clock();
    cout << (double)(endTime - startTime) / CLOCKS_PER_SEC;
    return 0;
}