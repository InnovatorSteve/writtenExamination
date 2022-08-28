#include<iostream>
#include<string>
#include<vector>
using namespace std;


int main(){
    int a, b;
    string num1 = to_string(a);
    string num2 = to_string(b);
    int n = num1.size(), m = num2.size();
    int a[n], b[m];
    int i, j;
    for(i = 0, j = n - 1; i < n; ++i, --j)  
        a[i] = num1[j] - '0';
    for(i = 0, j = m - 1; i < m; ++i, --j)  
        b[i] = num1[j] - '0';
    int c[2000] = {0};
    for(i = 0; i < n; ++i){
        for(j = 0; j < m; ++j)
            c[i + j] += a[i]*b[j];
    }
    for(i = 0; i < n + m; ++i){
        if(a[i] >= 10){
            c[i + 1] += c[i] / 10;
            c[i] %= 10;
        }
    }
    
}