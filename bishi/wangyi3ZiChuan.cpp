#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;

int main(){
    string str;
    cin >> str;
    unordered_map<char, int> countMap;
    int ans = 0;    
    for(int i = 0; i < str.size(); ++i){
        if(str[i] == 'r' || str[i] == 'e' || str[i] == 'd'){
            countMap.clear();
            countMap[str[i]]++;
            for(int j = i + 1; j < str.size(); ++j){
                if(str[j] == 'r' || str[j] == 'e' || str[j] == 'd'){
                   countMap[str[j]]++;
                   if(countMap['r'] == countMap['e'] && countMap['d'] == countMap['e'])
                       ans++;
                }                
            }
        }
    }
    cout << ans;
}
