// 小红遇到了一名粉刷匠。这名粉刷匠有三种颜料，分别是红、黄、蓝。为了方便， 这三种颜料分别命名为 A，B，C。

//现在，粉刷匠正在粉刷一面长度为3n 的墙壁。粉刷完之后，三种颜料的数目都相同。由于小红一不小心踢到了颜料桶，使得这面墙的每个地方都被染上了三种颜料中的其中一种，这很让粉刷匠头疼。

//粉刷匠每次可以选择一段连续的墙壁进行粉刷，即全部粉刷上同一种颜色（A,B,C 三种中的其中一种）。粉刷匠想知道，他最少需要多少次粉刷才能使得三种颜料的数目都相同？
// 输入描述
// 第一行一个正整数 T ，表示有 T 组数据。
// 对于每一组数据，第一行输入一个正整数 n，表示墙壁的长度为 3n；第二行一个长度为 3n 的字符串，仅包含 ABC 三种字母，表示该墙壁的初始颜色。
// 1 ≤ n ≤ 5 · 104, 1 ≤ T ≤ 5。
// 输出描述
// 对于每一组数据，输出一个整数，表示答案。
// 样例输入
// 3
// 2
// ABACBC 
// 3
// AAABBBBAC 
// 3
// CAACBCBCC
// 样例输出
// 0
// 1
// 2
// 提示
// 对于第一组样例，A,B,C 的数目都是 2，故无需进行粉刷；
// 对于第二组样例，选择区间 [7, 9]  全部粉刷为 C，之后形成的墙壁为 AAABBBCCC；
// 对于第三组样例，先选择区间 [4, 4] 粉刷为 B 之后形成的墙壁为 CAABBCBCC， 再选择区间 [9, 9] 全部粉刷为 A 之后形成的墙壁为 CAABBCBCA。此时每种颜色都有 3 个。
#include<iostream>
#include<string>
#include<map>
#include<algorithm>
using namespace std;

int main(){
    int T;
    cin >> T;
    while(T--){
        int a = 0, b = 0
    }
    return 0;
}


        // int n;
        // string str;
        // cin >> n >> str;
        // map<char, int> cnt;
        // for(auto ch : str) cnt[ch]++;
        // auto it = cnt.begin(); it++;
        // int maxv = max(cnt['A'], max(cnt['B'], cnt['C']));
        // int minv = min(cnt['A'], min(cnt['B'], cnt['C']));
        // int mid = 3 * n - maxv - minv;
        // if(cnt['A'] == n && cnt['B'] == 0 && cnt['C'] == 0)
        //     {cout << 0 << endl; continue;}
        // else if(mid > n) //{cout << (++it)->second - 3 << endl;}
        //     {cout << 1 << endl; continue;}
        // else{
        //     cout << n - mid + n -minv << endl;
        // }