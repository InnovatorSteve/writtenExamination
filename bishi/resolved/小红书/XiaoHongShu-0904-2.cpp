//给定int数组 每次操作可以对一个元素 +1 or -1, 现要将整个数组乘积变为7，求最少操作次数。
// 输入
// 5
// -6 0 2 -2 3
// 输出
// 6
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> nums(n);
    bool zeroFlag = false, negaFlag = false;
    int operaCnt = 0, maxNum = 0;
    for(int i = 0; i < n; ++i){
        cin >> nums[i];
        if(nums[i] == 0)
            zeroFlag = true;
        else if(nums[i] < 0){
            negaFlag != negaFlag; nums[i] = -nums[i];
        }
        operaCnt += abs(nums[i] - 1);
        maxNum = max(maxNum, nums[i]);
    }
    operaCnt = operaCnt - (maxNum - 1)  + abs(maxNum - 7);
    operaCnt +=  (!zeroFlag && negaFlag)? 2 : 0;
    cout << operaCnt;    
}