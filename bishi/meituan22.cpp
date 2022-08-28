#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> arr(m);
    for(int i = 0; i < m; ++i)
        cin >> arr[i];
    int j = 0;
    unordered_map<int, bool> record;
    vector<int> ans(n);
    for(int i = m - 1; i >= 0; --i){
        if(j < n && record.find(arr[i]) == record.end()){
            ans[j] = arr[i];
            ++j;
        }
        record[arr[i]] = true;
    }
    for(int i = 1; i <= n; ++i){
        if(j < n && record.find(i) == record.end()){
            ans[j] = i;
            ++j;
        }
    }
    for(int i = 0; i < n - 1; ++i){
        cout << ans[i] << " ";
    }
    cout << ans[n - 1];
    return 0;
}