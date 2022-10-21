    // 小Q有一个序列 a1,a2.....an， 小Q可以执行k次操作， 每次操作可将ai变为其二进制1的个数，具体每次操作步骤如下：
    // 1.小Q选择一个p（1<=p<=n）2。将序列a中第p个元素写成二进制形式，并且数出'1'的个数为cnt 3.将ap变成cnt
    // 小Q想知道k次操作后序列之和的最小值为多少？
    // （注：你可以对某个p（1<=p<=n）进行多次操作）
// 2 2
// 2 15
// 3

// 2 1
// 8 7
// 8

// 3 2
// 8 7 1024
// 9

#include<iostream>
#include<vector>
#include<queue>
#include<numeric>

using namespace std;

inline int calOne(int num){
    int cnt = 0;
    while(num) {++cnt; num &= num - 1;}
    return cnt;
}

int main(){
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    for(auto& e : nums) cin >> e;
    priority_queue<pair<int, int>> priQue;
    int cnt;
    for(auto& e : nums){
        cnt = calOne(e);
        priQue.emplace(make_pair(e - cnt, cnt));
    }    
    int ans = accumulate(nums.begin(), nums.end(), 0);
    for(int i = 0; i < k; ++i){
        auto curTop = priQue.top(); priQue.pop();
        ans -=  curTop.first;
        cnt = calOne(curTop.second);
        priQue.emplace(make_pair(curTop.second - cnt, cnt));
    }
    cout << ans;
}



