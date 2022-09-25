//给定n 代表n次查询 每次查询一个仅有0 1 组成的字符串， 可以进行任意次变换操作，每次变换可以把相邻的两个字符取反。 
//是否可以经过有限次变换 变为全部相同的字符
//101  Yes
//1001 Yes
//1011 No
#include<iostream>
#include<unordered_set>
#include<string>

using namespace std;

int main(){
    int n;
    cin >> n;
    while(n--){
        string str;
        cin >> str;
        unordered_set<char> strSet(str.begin(), str.end());
        int zeroCnt = strSet.count('0');
        int oneCnt = strSet.count('1');
        if(oneCnt % 2 == 0 || zeroCnt % 2 == 0)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
}