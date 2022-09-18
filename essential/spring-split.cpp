#include<iostream>
#include<string>
#include<vector>
using namespace std;

void split(string& s, vector<string>& words, string separator){
    size_t pos1 = 0, pos2 = s.find(separator);
    while(pos2 != string::npos){
        words.emplace_back(s.substr(pos1, pos2 - pos1));
        pos1 = pos2 + separator.size();
        pos2 = s.find(separator, pos1);
    }
    if(pos1 != s.size())
        words.emplace_back(s.substr(pos1));
}

int main(){
    string s;
    s = "num = [1,2,3]";
    s.erase(0, s.find('[') + 1);
    s.erase(s.size()-1, 1);
    vector<string> words;
    split(s, words, ",");
    for(auto& word : words) cout << word << endl;
    return 0;
}