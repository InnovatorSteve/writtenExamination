#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> arr(n + 1);
    for(int i = 1; i <= n; ++i)
        cin >> arr[i];
    queue<int> que;
    que.push(1);
    int ans = 0;
    while(!que.empty()){
        int curNode = que.front();
        que.pop();
        if(curNode * 2 <= n){
            arr[curNode * 2] += arr[curNode];
            que.push(curNode * 2);
        }
        if(curNode * 2 + 1<= n){
            arr[curNode * 2 + 1] += arr[curNode];
            que.push(curNode * 2 + 1);
        }
    }
    ans = *max_element(arr.begin(), arr.end());
    cout << ans << endl;
    return 0;
}