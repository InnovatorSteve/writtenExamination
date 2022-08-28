#include<iostream>
#include<algorithm>
#include<unordered_set>
#include<vector>

using namespace std;
int main(){
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    for(int i = 0; i < n; ++i)
        cin >> nums[i];
    int maxElement = *max_element(nums.begin(), nums.end());
    int bitLength = 0;
    while(maxElement){
        maxElement >>= 1;
        ++bitLength;
    }
    vector<vector<bool>> toBinaryNums(n, vector<bool>(bitLength, false));
    for(int i = 0; i < n; ++i){
        int tempNum = nums[i];
        int idx = bitLength - 1;
        while(tempNum){
            if(tempNum & 1)
                toBinaryNums[i][idx] = 1;
            tempNum >>= 1;
            --idx;
        }
    }
    unordered_set<int> excludeNum;
    string ansStr;
    for(int j = 0; j < bitLength; ++j){
        int cmpK = 0;
        unordered_set<int> tempset;
        for(int i = 0; i < n; ++i){
            if(excludeNum.find(i) != excludeNum.end())
                continue;
            if(toBinaryNums[i][j])
                ++cmpK;
            else
                tempset.insert(i);
        }
        if(cmpK >= k){
            ansStr += '1';
            excludeNum.insert(tempset.begin(), tempset.end());
        }else
            ansStr += '0';
    }
    size_t pos; //pos记录首个为转换字符的下标  第三个参数 base是值字符串中保存的是几进制 目标是是十进制
    int ans = stoi(ansStr, &pos, 2);
    cout << ans << endl;
    return 0;
}