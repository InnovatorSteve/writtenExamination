#include<bits/stdc++.h>
using namespace std;
long long dp[2020][2020],a[2222];
int main(){
    int n,m,i,j;
    cin>>n>>m;
    for(i=0;i<=n+1;i++)for(j=0;j<=n+1;j++)dp[i][j]=-1e16;
    dp[0][0]=m;
    for(i=1;i<=n;i++)cin>>a[i];
    for(i=1;i<=n;i++){
        for(j=0;j<=n;j++){
            dp[i][j]=dp[i-1][j];
            if(j&&dp[i-1][j-1]>=a[i])dp[i][j]=max(dp[i][j],dp[i-1][j-1]-a[i]);
            dp[i][j]=max(dp[i][j],dp[i-1][j+1]+a[i]);
        }
    }
    long long res=0;
    for(i=0;i<=n;i++)res=max(res,dp[n][i]+i*a[n]);
    cout<<res;
}