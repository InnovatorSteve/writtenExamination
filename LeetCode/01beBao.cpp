#include<iostream>
#include<vector>
using namespace std;

int maxObtainableValue(vector<int> weight, vector<int> value, int bagweight){
    vector<vector<int>> dp(weight.size(), vector<int>(bagweight + 1, 0));
    for(int j = 0; j < dp[0].size() && j < weight[0]; ++j){
        dp[0][j] = 0;
    }
    for(int j = weight[0]; j < dp[0].size(); ++j){
        dp[0][j] = value[0];
    }
    for(int i = 1; i < dp.size(); ++i){
        for(int j = 0; j < dp[i].size(); ++j){
            if(j < weight[i]){
                dp[i][j] = dp[i - 1][j];
            }else{
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight[i]] + value[i]);
            }
        }
    }
    return dp.back().back();
}

int maxObtainableValue1(vector<int>& weight, vector<int>& value, int bagweight){
    vector<int> dp(bagweight + 1, 0);
    for(int i = 0; i < weight.size(); ++i){
        for(int j = bagweight; j >= weight[i]; --j){
            dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
        }
    }
    return dp.back();
}

int main(){
    vector<int> weight = {1, 3, 4};
    vector<int> value = {15, 20, 30};
    int bagweight = 4;
    
    int ans = maxObtainableValue1(weight, value, bagweight);
    cout << ans << endl;
}