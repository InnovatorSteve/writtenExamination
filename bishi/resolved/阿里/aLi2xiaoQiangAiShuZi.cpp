#include<iostream>
#include<vector>
using namespace std;
const int m_mod = 1e9 + 7;
long long calculate(long long A, long long B, int n){
    vector<long long> f(n + 1);
    long long mod = 1e9 + 7;
    f[0] = 2, f[1] = A;
    for(int i = 2; i <= n; ++i){
        f[i] = (A * f[i - 1] % m_mod - B * f[i - 2] % m_mod + m_mod) % m_mod;
    }
    return f[n];
}
int main(){
    int T;
    cin >> T;
    while(T--){
        int A, B, n;
        cin >> A >> B >> n;
        cout << calculate(A, B, n) << endl;
    }
    system("pause");
    return 0;
}