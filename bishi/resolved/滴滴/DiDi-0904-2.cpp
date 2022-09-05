//题目描述： 老张教授开了一堂美数课！ 老张认为每个非负整数x都有一个美丽值b(x)。 一个非负整数的美丽值定义为这个数十进制下每个数位的异或和。
//即，对于123来说，美丽值为1^2^3=0，对于654815424美丽值为6^5^4^8^1^5^4^2^4=9 （在C/C++中^运算符表示异或） 现在老张想考考同学，
//对于[L,R]这个闭区间内的所有整数，美丽值恰好为t的数有多少个。 
//输入描述 第一行一个正整数，表示有n次询问。  接下来有三行： 
// 第一行n个非负整数 L1,L2,...,Li,...,LT(1≤i≤T)  
// 第二行n个非负整数 R1,R2,...,Ri,...,RT(1≤i≤T)  
// 第三行个非负整数 t1,t2,...,ti,...,tT(1≤i≤T)  
// 每个询问是对于 [Li, Ri] (Li≤Ri)这个闭区间内的所有整数，美丽值恰好为的数有多少个。 
//输出描述 每个询问输出T个整数，每两个数之间用空格隔开，表示答案。  
//样例输入 
//2 
//0 1
//0 10
//0 1
//样例输出 1 2
#include<iostream>
#include<vector>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> arrL(n), arrR(n), arrT(n);
    int maxNum = 0;
    for(int i = 0; i < n; ++i)
        cin >> arrL[i];
    for(int i = 0; i < n; ++i)
        cin >> arrR[i], maxNum = max(maxNum, arrR[i]);
    for(int i = 0; i < n; ++i)
        cin >> arrT[i];
    vector<vector<int>> cnt(70001, vector<int>(16));
    cnt[0][0] = 1;
    for(int i = 1; i < 70001; ++i){
        int temp = i, value = temp % 10;
        temp /= 10;
        while(temp){
            value ^= temp % 10;
            temp /= 10;
        }
        for(int j = 0; j < 16; ++j)
            cnt[i][j] = cnt[i - 1][j] + (j == value); 
    }
    for(int i = 0; i < n; ++i){
        if(arrT[i] >= 16)
            cout << 0 << " ";
        else
            cout << cnt[arrR[i]][arrT[i]] - (arrL[i] ? cnt[arrL[i] - 1][arrT[i]] : 0) << " ";
    }
    return 0;
}