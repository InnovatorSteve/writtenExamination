#include<iostream>
#include<string>
#include<regex>
#include<unordered_map>

using namespace std;

int main(){
    long long num;
    cin >> num;
    vector<long long> recoder;
    while(num){
        recoder.emplace_back(num % 10);
        num = num / 10;
    }
    long long ans = 0;
    for(int i = 0; i < recoder.size(); ++i){
        ans = ans * 10 + recoder[i];
    }
    cout << ans << endl;
}