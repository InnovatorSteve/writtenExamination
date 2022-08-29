#include<iostream>
#include<math.h>
using namespace std;

int main(){
    long long a, b, k;
    cin >> a >> b >> k;
    long long c;
    if(k <= 2) return k == 1 ? a : b;
    static constexpr long long MOD = 1000000007;
    for(int i = 3; i <= k; ++i){
        c = pow((a * b), 2);
//             cout <<  a << " "  << b  << " " << c << endl;
        a = b;
        b = c;
    }
    cout << c % MOD;
    return 0;
}