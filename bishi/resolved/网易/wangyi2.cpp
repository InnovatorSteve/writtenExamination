/*
小红拿到了一个字符串，她可以做任意次以下操作：
标记这个字符串两个位置相邻的字母，并目这两个字母必须满足以下条件才可标记：两个字母相同或者两个字母在字母表中相邻。小红可以获得这两个字母的分数。
举个例子，a 和 b 在字母表相邻，t 和 s 在字母表相邻。
我们规定，已经被标记的字母无法被重复标记。
每个字符获得的分数是不同的，a 可以获得 1 分，b 可以获得 2 分，以此类推，z 可以获得 26 分。
小红想知道，自己最多可以获得多少分？n <= 200000。

样例输入
abdbb
样例输出
7*/
#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main(){
    string s;
    cin >> s;
    vector<int> dp(s.size() + 1);
    for (int i = 1; i < s.length(); i++)
    {
        dp[i + 1] = dp[i];  //dp[i+1]  代表前i个字符串最大得分   连续得字符串可能变大也可能变小
        if (abs(s[i] - s[i - 1]) <= 1)
        {
            dp[i + 1] = max(dp[i], dp[i - 1] + (s[i] - 'a' + 1) + (s[i - 1] - 'a' + 1));
        }
    }
    cout << dp[s.length()];
    return 0;
}

