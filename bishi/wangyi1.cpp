/*
    小红在一个游戏里杀怪。这是个回合制游戏， 小红和两只怪物相遇了，第一只怪物有a血量，第二只怪物有b血量。
    小红有两个技能：
    第一个技能叫火球术，效果是对单体怪物造成x 伤害。 
    第二个技能叫烈焰风暴，效果是对每只怪物造成 y伤害。 
    小红想知道，自己最少使用多少次技能。 可以击杀这两只怪物？（当怪物血量小于等于0时，视为被击杀）输入描述：
    四个正整数a，b，c，y，用空格隔开。
    1≤a，b，x，y≤20输出描述：
    小红使用技能的最少次数。
*/

#include <bits/stdc++.h>
using namespace std;

int a, b, x, y;
int dp[25][25];

int dfs(int h1, int h2) {
    if (h1 == 0 && h2 == 0) return 0;
    if (dp[h1][h2]) return dp[h1][h2];

    int ans = INT_MAX;
    if (h1 > 0) {
        ans = min(ans, dfs(max(0, h1 - x), h2) + 1);
    }
    if (h2 > 0) {
        ans = min(ans, dfs(h1, max(0, h2 - x)) + 1);
    }
    ans = min(ans, dfs(max(0, h1 - y), max(0, h2 - y)) + 1);

    return dp[h1][h2] = ans;
}
//xiugai
int main() {
    scanf("%d%d%d%d", &a, &b, &x, &y);
    int ans = dfs(a, b);
    printf("%d\n", ans);
    return 0;
}

// #include<iostream>

// using namespace std;

// int main(){
//     int x, y, a, b;
//     cin >> a >> b >> x >> y;
//     if(x <= y * 2){ //如果单体攻击伤害小于 多体攻击得2倍 那么效率必然低于多体攻击 一直多体攻击即可
//         cout << max(a / y, b / y) << endl;
//     }else{
//         int cnt = 0;
//         if(a > x)
//             cnt += a / x, a %= x;
//         if(b > x)
//             cnt += b / x, b %= x;
//         cnt += max(a / y, b / y); 
//         cout << cnt << endl;
//     }
//     return 0;    
// }


//测试用例
// 6 1 5 1
// 2

// 5 2 3 1
// 3