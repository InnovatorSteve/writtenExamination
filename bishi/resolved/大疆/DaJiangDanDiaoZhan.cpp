// 时间限制： 3000MS
// 内存限制： 589824KB
// 题目描述：
// 小C平时最喜欢玩数字游戏，最近他碰到一道有趣的数字题，他和他的好朋友打赌，一定能在10分钟内解出这道题，
// 成功完成，小C就可以得到好朋友送他的Switch游戏机啦，你能帮助小C赢得奖品吗？
// 题目是这样的：给定一个非负的、字符串形式的整形数字，例如“12353789”，字符串的长度也就是整形数字的位数
// 不超过10000位，并且字符串不会以0开头，小C需要挑选出其中K个数字（K小于字符串的长度）并删掉他们，使得剩
// 余字符组成新的整数是最小的。
// 输入描述
// 第一行输入一串纯数字形式的字符串，组成一个正整数
// 第二行输入一个正整数K (K < 字符串的长度)
// 输出描述
// 输出一个数字（字符串格式）

// 样例输入
// 71245323308
// 4
// 样例输出
// 1223308

// 提示
// 输入样例二:
// 1683212
// 3
// 输出样例二:
// 1212
// 输入样例三：
// 100
// 1
// 输出样例三:
// 0

#include<iostream>
#include<stack>
#include<string>
#include<algorithm>

using namespace std;

int main(){
    stack<char> stk;
    string s;
    cin >> s;
    int n;
    cin >> n;
    for(auto ch : s){
        if(stk.empty())
            stk.push(ch);
        else{
            while(n && !stk.empty() && ch < stk.top()){
                stk.pop();
                n--;
            }
            stk.push(ch);
        }
    }
    string ans;
    while(!stk.empty()){
        ans += stk.top();
        stk.pop();
    }
    reverse(ans.begin(), ans.end());
    ans = to_string(stoi(ans));
    cout << ans << endl;
}