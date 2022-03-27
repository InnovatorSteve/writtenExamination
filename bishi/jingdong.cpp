#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int T;
    cin >> T;
    vector<int> line1(T), line2(T), line3(T);
    for(int i = 0; i < T; ++i)
        cin >> line1[i];
    for(int i = 0; i < T; ++i)
        cin >> line2[i];
    for(int i = 0; i < T; ++i)
        cin >> line3[i];
    for(int i = 0; i < T; ++i){
        int ans = 0;
        for(int j = line1[i]; j <= line2[i]; ++j)
            ans = max(ans, j % line3[i]);
        cout << ans << " ";
    }
}