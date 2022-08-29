#include<iostream>
#include<vector>
using namespace std;


int main(){
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; ++i){
        cin >> nums[i];
    }
    int ans = 0;
    for(int cnt = 0; cnt <= n; ++cnt){
        for(int i = 0; i < n; ++i){
            int sum = 0;
            for(int j = i; j < n; ++j){
                sum += nums[j];
                if(sum%7 == 0)
                    ans = max(ans, sum);
            }
        }
    }

    cout << ans << endl;
    return 0;
    
}