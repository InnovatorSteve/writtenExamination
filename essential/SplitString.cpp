#include<iostream>
#include<string>
#include<vector>
using namespace std;

void split(string&s ,vector<string>& result, string separator){
    int pos1 = 0, pos2 = s.find(separator);
    while(pos2 != string::npos){
        result.emplace_back(s.substr(pos1, pos2 - pos1));

        pos1 = pos2 + separator.size();
        pos2 = s.find(separator, pos1);
    }
    if(pos1 < s.size())
        result.emplace_back(s.substr(pos1));
}

int main(){
    string s= "12,:dsadsa,:1545,:u8*)(9_-9,:dsad+_+)((";
    vector<string> ans;
    split(s, ans, ",:");
    for(auto str : ans){
        cout << str << "\t";
    }
}