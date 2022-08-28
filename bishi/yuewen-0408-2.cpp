#include<iostream>
#include<string>
using namespace std;

int main(){
    string str;
    cin >> str;
    pair<int, int> maxIndex;
    int cnt = 1;
    int curStrat = 0;
    for(int i = 1; i < str.size(); ++i){
        if(str[i] == str[i - 1])
            ++cnt;
        else{
            if(maxIndex.first < cnt){
                maxIndex.first = cnt;
                maxIndex.second = curStrat;
            }
            curStrat = i;
            cnt = 1;
        }
    }
    cout << str.substr(maxIndex.second, maxIndex.first);
    return 0;
}