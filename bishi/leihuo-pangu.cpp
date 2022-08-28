#include<iostream>
#include<unordered_map>
#include<string>
#include<vector>
#include<stack>
#include<algorithm>
#include<unordered_set>
using namespace std;

unordered_map<char, string> record = {
    {'R', "FF0000"}, {'G', "00C932"}, {'B', "0000FF"}, {'K', "000000"}, {'Y', "FFFF00"}, {'W', "FFFFFF"}, {'P', "FF88FF"}
};
vector<pair<string, string>> ans;
stack<string> stk;
int recordClor(string& str, int i){
    if(i + 1 < str.size() && record.find(str[i + 1]) != record.end()){
        // ans.push_back({"", record[str[i + 1]]});
        stk.push(record[str[i + 1]]);
        return i + 2;
    }else if(i + 1 < str.size() && str[i + 1] == 'C'){
        int j = i + 2;
        for(; j < str.size() && j <= i + 7; ++j){
            if(str[j] >= 'A' && str[j] <= 'F' || (str[j] >= '0' && str[j] <= '9')){
            }else{
                break;
            }
        }
        if(j == i + 8){
            // ans.push_back({"", str.substr(i + 2, 6)});
            stk.push(str.substr(i + 2, 6));
            return j;
        }
    }else if(i + 1 < str.size() && str[i + 1] == 'n'){
        if(!stk.empty()) {
            stk.pop();
            return i + 2;
        }
    }    
    return i;
}

int recordStr(string& str, int i){  //记录当前栈内所有颜色赋予文字
    int j = i;
    for(; j < str.size(); ++j){
        auto temp = str[j];
        if(stk.empty()) return j;
        if(str[j]!= '#'){
            ans.push_back({"", stk.top()});
            while(j < str.size()){
                if(str[j] != '#')
                    ans.back().first += str[j++];
                else{
                    int k = recordClor(str, j);
                    if(k == j)
                        ans.back().first += str[j++];
                    else{
                        j = k - 1;
                        break;
                    }
                }
            }
        }
    }
    return j;
}


void func(string& str){
    for(int i = 0; i < str.size(); ++i){
        if(str[i] == '#'){
            int j = recordClor(str, i);
            if(j == i)
                continue;
            if(j < str.size() && str[j] != '#')
                j = recordStr(str, j), i = j;
            else i = --j;
        }else if(!stk.empty()){
            int j = recordStr(str, i); 
            i = j;
        }
    }
    cout << endl;
    // for(auto& rec : ans){
    //     if(rec.first == "") cout << "empty" << endl;
    //     else cout << rec.first << " " << rec.second << endl;
    // }
    if(ans.empty()){
        cout << "empty" << endl;
    }else{
        for(auto& rec : ans){
            cout << rec.first << " " << rec.second << endl;
        }
    }
}

int main(){
    int M;
    cin >> M;
    getchar();
    vector<string> Si(M);
    for(int i = 0; i < M; ++i){
        getline(cin, Si[i]);
    }

    for(auto& str : Si){
        ans.clear();
        while(!stk.empty()) stk.pop();
        func(str);
    }
    return 0;
}


// 2
// #C6789xuvW #nlergfdgb #W
// #Ppan gu#n you fu, kai tian pi di, li jie er wang.#C52BE80#CE74C3Cqing qi#n sheng, wei tian;#C2E86C1zhuo qi#n jiang, wei di#1n;yuan qi yan sheng chu wan wu, cui fa sheng ji;mo qi yan sheng chu si wang duo luo,mi luan hui mei.yu zhou wan wu,you zheng, ze bi you you fan.