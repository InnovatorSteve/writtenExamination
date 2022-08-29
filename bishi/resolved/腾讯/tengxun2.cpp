#include<iostream>
#include<vector>
using namespace std;

int getNumber(vector<int>& a){
    while(a.size() > 1){
        int n = a.size();
        vector<bool> flag(n + 1);
        vector<int> prime;
        int cnt = 0;
        flag[1] = true;
        for(int i = 1; i <= n; ++i){
            if(!flag[i]){
                prime.emplace_back(a[i-1]);
                for(int j = i; i * j <= n; ++j)
                    flag[i * j] = true;
            }
        }
        a = prime;
    }
    return a[0];
}

int main(){
    vector<int> a = {3,1,1,4,5,6};
    cout << getNumber(a);
    return 0;
}



int flag = INT_MIN;
bool judge(int n){
    for(int i = 2; i * i <= n; ++i){
        if(n % 2 == 0)
            return false;
    }
    return true;
}


class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     * 
     * @param a int整型vector 
     * @return int整型
     */
    int ok[201010];
    vector<int> f(vector<int>a){
        vector<int>res;
        for(int i=2;i<=a.size();i++){
            if(!ok[i])res.push_back(a[i-1]);
        }
        return res;
    }
    int getNumber(vector<int>& a) {
        // write code here
        int i,j;
        for(i=2;i<=2e5;i++){
            if(!ok[i])
            for(j=i*2;j<=2e5;j+=i)ok[j]=1;
        }
        while(a.size()>1)a=f(a);
        return a[0];
    }
};

// void notes(vector<int>& a){
//     int n = a.size();
//     if(n < 2 ) return;
//     a[0] = flag;
//     for(int i = 3; i <= n; ++i){
//         if(!judge(i))
//             a[i - 1] = flag;
//     }
//     for(int i = 0; i < a.size(); ++i){
//         if(a[i] == flag)
//             a.erase(a.begin() + i);
//     }
// }
// int getNumber(vector<int>& a) {
//     // write code here
//     while(a.size() > 1){
//         notes(a);
//     }
//     return a[0];
// }