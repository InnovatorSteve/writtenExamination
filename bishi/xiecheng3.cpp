#include<iostream>
#include<string>
#include<algorithm>
#include<map>
using namespace std;

int main(){
    string s;
    int n, k;
    cin >> n >> k >>s;
    int left = 0, count = 0, maxx = 0;
    map<char, int> mapp;
    for(int i = 0; i < s.size(); ++i){
        // if(!mapp.count(s[i]) || mapp[s[i]] == 0){
        //     mapp[s[i]] = 1;
        //     ++count;
        // }
        if(mapp[s[i]]){
            mapp[s[i]] ++;
        }else{
            mapp[s[i]] = 1;
            ++count;
        }
        while(count > k){
            char Lchar = s[left++];
            if(mapp[Lchar] == 1){
                count--;
                mapp[Lchar] = 0;
            }else{
                mapp[Lchar]--;
            }
        }
        maxx = max(i - left + 1, maxx);
    }    
    cout << maxx;
}