#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int maxValue(vector<int>& weight, vector<int>& value, int bageWeight){
    int m = weight.size(), n = value.size();
    vector<vector<int>> dp(m, vector<int>(bageWeight + 1));
    for(int j = weight[0]; j < n; ++j)
        dp[0][j] = value[0];
    for(int i = 1; i < m; ++i){ //背包重量j   物品编号i
        for(int j = 1; j <= bageWeight; ++j){
            if(j < weight[i]) dp[i][j] = dp[i - 1][j];
            else dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight[i]] + value[i]);
        }
    }
    return dp[m-1][weight];
}

int main(){
    vector<int> weight = {1, 3, 4};
    vector<int> value  =  {15, 20, 30};
    int bageWeight = 4;
    cout << maxValue(weight, value, bageWeight); 
    return 0;
}