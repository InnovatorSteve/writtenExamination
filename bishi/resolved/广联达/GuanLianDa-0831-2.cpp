//根据IP地址确定子网掩码
#include<iostream>
#include<queue>
#include<vector>
#include<string>
#include<sstream>
#include<iomanip>
#include<stdio.h>
using namespace std;

void addZero(string& s){
    int n = s.size();

}

int get(vector<string>& ips){
    vector<vector<int>> vec(ips.size(), vector<int>(4));
    for(int i = 0; i < ips.size(); ++i){
        size_t pos = 0;
        int j = 0;
        while(ips[i].size()){
            vec[i][j++] = stoi(ips[i], &pos);
            if(pos + 1 < ips[i].size())
                ips[i] = ips[i].substr(pos + 1);
            else break;
        }
    }
    vector<vector<string>> str(ips.size(), vector<string>(4));
    for(int i = 0; i < ips.size(); ++i){
        for(int j = 0; j < 4; ++j){
            stringstream ss;
            char temp[4];
            itoa(vec[i][j], temp, 2);
            ss << setw(8) << setfill('0') << temp;  // << left 左对齐  << right 右对齐  C++不会截短数据
            ss >> str[i][j];
        }
    }
    ios_base::fmtflags old = cout.flags();  //保存修改前输出格式
    int ans = 0;
    for(int j = 0; j < 4; ++j){
        for(int k = 0; k < 8; ++k){
            char temp = str[0][j][k];
            bool flag = true;
            for(int i = 1; i < ips.size(); ++i){
                if(str[i][j][k] != temp){
                    flag = false;
                    break;
                }
            }
            if(flag) ++ans;
            else {
                // printf("%d\n", ans);
                // cout.fill('*'); cout.width(0);
                return ans;
            }
        }
    }
    // cout.setf(old); //恢复
    // cout << ans;
    return 0;
}

int main(){
    vector<string> ips = {"192.168.129.7", "192.168.206.155"};
    int ans = get(ips);
    cout << ans;
}

// int main(){
//     vector<int> arr = {1, 2, 3, 4,  33,  5};
//     priority_queue<int, vector<int>, less<int>> pri_que(arr.begin(), arr.end());
//     int n = arr.size(), cnt = 0;
//     int target_n = n * 3 / 10 - 1; //向下
//     while(cnt < target_n ){
//         pri_que.pop();
//         cnt++;
//     }
//     cout << pri_que.top();
// }


// #include <iostream>
// #include <vector>
// #include <string>
// #include <algorithm>
// #include <stdio.h>
// #include <string.h>
// using namespace std;
// class A
// {
// public:
//     virtual ~A() { print(); }
//     virtual void print() { std::cout << "a"; };
// };
// class B : public A
// {
// public:
//     B() { print(); }
//     virtual ~B() { print(); }
//     void print() override { std::cout << "b"; }
// };
// int main()
// {
//     A *a = new B();
//     a->print();
//     delete a;
//     return 0; 
// }