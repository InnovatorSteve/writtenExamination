// 题目描述：
// 给一个长度为n的序列a[1], a[2], …, a[n]，请问有多少个三元组(i,j,k)满足i<j<k且a[i]-a[j]=2a[j]-a[k]？输出符合要求的三元组的数量。

// 输入描述
// 第一行是一个整数n，表示序列长度为n。
// 接下来一行n个用空格隔开的整数，a[i]表示序列的第i个数。
// 1<=n<=4000, 0<=a[i]<=1000000

// 输出描述
// 一行一个整数，表示符合要求的三元组数量。
// 样例输入
// 4
// 4 2 2 2
// 样例输出
// 3
// 样例解释1
// 3个三元组分别是(1, 2, 3) (1, 2, 4)和(1, 3, 4)

#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; ++i){
        cin >> arr[i];
    }
    unordered_map<int, int> record;
    record[arr[n - 1]] = 1;
    int count = 0;
    for(int i = n - 2; i >= 1; --i){
        for(int j = i - 1; j >= 0; --j){ 
            count += record[3 * arr[i] - arr[j]];
        }
        record[arr[i]] += 1;
    }
    cout << count;
}