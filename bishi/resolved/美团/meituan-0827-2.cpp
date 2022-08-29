/* 小美有一个精致的珠宝链子。初始这个链子上有个宝石，从左到右分别编号为1~n（宝石上的编号不会因为交换位置而改变编号)。
接着，小美为了美观对这个顶链进行微调，有m次操作,每次选择一个编号X,将编号X的宝石放到最左边(不改变其他宝石的相对位置)。
小美想知道，所有操作完成后最终链子从左到右宝石编号是多少.
    输入描述：
    第一行两个正整数n和m,分别表示链子上的宝石数和操作次数。
    接下来一行m个数x1,X2,...,Xm,依次表示每次操作选择的编号x值。数字间两两有空格隔开。对于所有数据，1≤m,n≤50000,1≤X≤n
    输出描述：
    输出一行n个整数，表示答案。
样例
输入:   5 3 
        2 3 4
输出:   4 3 2 1 5
提示：
    第一次微调完，链子为2 1 3 4 5
    第二次微调完，链子为3 2 1 4 5
    第三次微调完，链子为4 3 2 1 5
*/
#include<iostream>
#include<stack>
#include<vector>
#include<set>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    stack<int> opt;
    for(int i = 0; i < m; ++i){
        int temp; 
        cin >> temp;
        opt.push(temp);
    }
    vector<int> ans;
    while(!opt.empty()){
        ans.emplace_back(opt.top());
        opt.pop();
    }
    set<int> opted(ans.begin(), ans.end());
    for(int i = 1; i <= n; ++i)
        if(opted.find(i) == opted.end())
            ans.emplace_back(i);
    for(int i = 0; i < n - 1; ++i)
        cout << ans[i] << " ";
    cout << ans[n - 1];
}

// #include<iostream>
// #include<vector>
// #include<unordered_map>

// using namespace std;

// int main(){
//     int n, m;
//     cin >> n >> m;
//     vector<int> arr(m);
//     for(int i = 0; i < m; ++i)
//         cin >> arr[i];
//     int j = 0;
//     unordered_map<int, bool> record;
//     vector<int> ans(n);
//     for(int i = m - 1; i >= 0; --i){
//         if(j < n && record.find(arr[i]) == record.end()){
//             ans[j] = arr[i];
//             ++j;
//         }
//         record[arr[i]] = true;
//     }
//     for(int i = 1; i <= n; ++i){
//         if(j < n && record.find(i) == record.end()){
//             ans[j] = i;
//             ++j;
//         }
//     }
//     for(int i = 0; i < n - 1; ++i){
//         cout << ans[i] << " ";
//     }
//     cout << ans[n - 1];
//     return 0;
// }