#include <iostream>
#include<string>
#include<algorithm>
using namespace std;

int main(){
    string s;
    cin >> s;
    string s2 = s;
    int len = s.size();
    long long ans = 0;
    for(int i = 1; i < len; ++i){
        if(s[i] == s[i - 1]){
           s[i] = !(s[i - 1] - '0') + '0';
           ans += i + 1; 
        }
    }
    long long ans2 = 1;
    s2[0] = !(s2[0] - '0') + '0';
    for(int i = 1; i < len; ++i){
        if(s2[i] == s2[i - 1]){
           s2[i] = !(s2[i - 1] - '0') + '0';
           ans2 += i + 1; 
        }
    }
    ans = min(ans, ans2);
    cout << ans;
}

// int main() {
//     long long x;
//     cin >> x;
//     long long num = x;
//     string numS;
//     while(num){
//         numS += num % 10 + '0';
//         num /= 10;
//     }
//     reverse(numS.begin(), numS.end());
//     string number = "0123456789";
//     for(int i = 0; i <= numS.size(); ++i){
//         for(int j = 0; j < 10; ++j){
//             string new_num = numS;
//             new_num.insert(i, number, j, 1);
//             long long num = 0;
//             for(auto ch : new_num){
//                 num = num * 10 + ch - '0';
//             }
//             if(num % 7 == 0){
//                 cout << num;
//                 return 0;
//             }
//         }
//     }
//     return 0;

// }