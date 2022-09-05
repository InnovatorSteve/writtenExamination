//题目描述： 小昱家的桃园丰收了！小昱采摘下来n个桃子，并对这些桃子称重，其中第i个桃子的重量为ai。 
//小昱想选择一些桃子装成一箱后送给朋友，但是小昱不希望一箱桃子中有一些太大的桃子而影响整体美观。
// 于是他给装箱工人提出了一个要求：一箱桃子中最重的桃子重量不能超过平均重量的k倍。装箱工人想知道在满足小昱要求的情况下，一箱最多能装多少个桃子。 
//输入描述 第一行输入两个正整数 n, k，表示桃子个数、倍数系数。
// 接下来一行输入n个正整数a1, a2,...... an，其中ai表示第 i 个桃子的重量。 1 ≤ n, k ≤ 100000, 1≤ ai ≤ 109
// 输出描述 输出一个整数，表示一箱最多能装桃子数量。 样例输入 5 2 3 10 5 4 2 样例输出 4

#include<iostream>
#include<vector>
#include<list>
#include<algorithm>
using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    for(int i = 0; i < n; ++i)
        cin >> nums[i];
    sort(nums.begin(), nums.end(), greater<int>());
    list<int> path;
    int sum = 0;
    int ans = 0;
    for(int i = 0; i < n; ++i){
        sum += nums[i];
        path.push_back(nums[i]);
        while(!path.empty() && sum / (double)path.size() * k < path.front()){
            sum -= path.front(); path.pop_front(); 
        }
        ans = max(ans, (int)path.size());
    }
    cout << ans;
}