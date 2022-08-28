#include<iostream>
#include<math.h>
using namespace std;
const static unsigned long long MOD = 1e9 + 7;
long long func(long long num){
    long long ans = 1;
    for(long long i = num; i > 0; --i){
        ans *= i;
 
    }
    return ans;
}

int main(){
    long long n;
    cin >> n;
    long long ans = 0;
    if(n < 6){
        cout << 0;
        return 0;
    }else{
        long long other = n - 6;
        long long res = 0;
        long long c1, c2 = 1;
        c1 = pow(26, other);
        c2 = func(2 + other) / (2*func(other));

        long long ans = c1 * c2;
        cout << ans % MOD;
    }
}