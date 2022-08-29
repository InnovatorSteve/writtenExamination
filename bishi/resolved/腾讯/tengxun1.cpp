#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<string> str(n);
    for(int i = 0; i < n; ++i)
        cin;
    int length = str[0].length();
    vector<int> ans(length);
    for(int i = 0; i < length; ++i){
        for(int j = 0; j < n; ++j){
            int currNumber = str[j][i] - '0';
            ans[i] = ans[i] * 10 + currNumber; 
        }
    }
    sort(ans.begin(), ans.end());
    for(int i = 0; i < length; ++i){
        cout << ans[i];
        if(i < length - 1)
            cout << " ";
    }
    return 0;
}