#include<iostream>
#include<string>
using namespace std;

int main(){
    long long N, X;
    string str;
    cin >> N >> X >> str;
    long long ans = 0;
    long long current = X;
    for(int i = 0; i < N; ++i){
        char ch = str[i];
        if(ch == 'U')
            current /= 2;
        else if(ch == 'R')
            current = current * 2 + 1;
        else
            current *= 2;
    }
    cout << current << endl;
    return 0;
}