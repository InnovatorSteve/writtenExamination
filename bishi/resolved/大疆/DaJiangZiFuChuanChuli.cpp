#include<iostream>
#include<string>
#include<regex>
#include<unordered_map>

using namespace std;

void dealStringWithSubtract(string& s){
    unordered_map<string, int> cGroup;
    unordered_map<string, int> uGroup;
    std::regex re("([a-zA-Z]+):([0-9]+)");
    std::smatch m;
    while(std::regex_search(s, m, re)){
        if(cGroup.find(string(m[1])) == cGroup.end()) {
            cGroup[string(m[1])] = stoi(m[2]);
        }else{
            uGroup[string(m[1])] = stoi(m[2]);
        }

        // cout << m[0] << " \t";
        // cout << string(m[1]) << " \t";
        // cout << stoi(m[2]) << endl;
        // cout << "s = " << s << endl;
        s = m.suffix();
    }
    if(uGroup.empty()){
        for(auto it : cGroup){
            cout << it.first << ":" << it.second << ",";
        }
        cout << "#" << endl;
    }else{
        for(auto it : cGroup){
            // if(uGroup.find(it.first) != uGroup.end()){
                cout << it.first << ":" << abs(it.second - uGroup[it.first]) << ",";
            // }
        }
    }

}

int main(){
    string s = "d:3,D:5,A:10,#d:2,A:1";
    dealStringWithSubtract(s);
}