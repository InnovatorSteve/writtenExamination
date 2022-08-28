#include<bits/stdc++.h>
using namespace std;
long long op[101010],ed[202020];
int main(){
    int n,i;
    string s;
    cin>>n>>s;
    long long sum=0;
    for(i=1;i<=n;i++){
        op[i]=sum+=i*(s[i-1]=='0');
    }
    sum=0;
    for(i=n;i>=0;i--){
        ed[i]=sum+=i*(s[i-1]=='1');
    }
    long long res=1e15;
    for(i=1;i<=n+1;i++){
        res=min(res,abs(op[i-1]-ed[i]));
    }
    cout<<res;
}