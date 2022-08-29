#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main(){
    string str;
    int lineNum;
    cin >> str >> lineNum;
    if(lineNum <= 0) {cout << ""; return 0;}
    vector<vector<char>> record(lineNum, vector<char>(str.size(), ' '));
    int idx = 0;
    int j = 0;
    while(idx < str.size()){
        for(int i = 0; idx < str.size() && i < lineNum; ++i){
            record[i][j] = str[idx++];
        }
        j++;
        for(int i = lineNum - 2; idx < str.size() && i > 0; --i){
            record[i][j++] = str[idx++];
        }
    }
    string ans;
    for(int i = 0; i < record.size(); ++i){
        for(int j = 0; j < record[i].size(); ++j){
            if(record[i][j] != ' ')
                ans += record[i][j];
        }
    }
    cout << ans;
    return 0;

}