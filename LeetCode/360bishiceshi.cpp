#include<iostream>
#include<math.h>

using namespace std;

int main(){
    double n, m;
    cin >> n >> m;
    double ans = n;
    for(double i = 0; i < m - 1; ++i){
        ans += sqrt((double)n);
        n = sqrt(n);
    }
    printf("%.2f", ans);
    return 0;
}

//¿ìËÙ²¹È«