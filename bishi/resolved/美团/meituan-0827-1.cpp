#include<iostream>
#include<string>

using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    getchar();
    string S1, S2;
    getline(cin, S1);
    getline(cin, S2);
    int ans = 0;
    for(int i = 0; i <= n - m; ++i){
        if(S1[i] == S2[0] || S2[0] == '*'){
            bool flag = true;
            for(int j = 0; j < m; ++j){
                if(S1[i + j] == S2[j] || S2[j] == '*')
                    continue;
                else{
                    flag = false;
                    break;
                } 
            }
            if(flag)
                ans++;
        }
    }
    cout << ans;
    return 0;
}