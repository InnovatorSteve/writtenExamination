#include<iostream>
#include<unordered_map>
#include<string>
#include<string.h>
#include<vector>
#include<queue>
#include<set>
using namespace std;
typedef pair<string, int> p;
void SplitStr(const string& s, vector<string>& v, const string& c){
    string::size_type pos1, pos2;
    pos2 = s.find(c);
    pos1 = 0;
    while(string::npos != pos2){
        v.push_back(s.substr(pos1, pos2 - pos1));
        pos1 = pos2 + c.size();
        pos2 = s.find(c, pos1);
    }
    if(pos1 != s.length())
        v.push_back(s.substr(pos1));
}
int main(){
    int topN, M;
    cin >> topN >> M;
    vector<vector<string>> article(M, vector<string>(2));
    getchar();
    for(int i = 0; i < M; ++i){
        getline(cin, article[i][0]);
        getline(cin, article[i][1]);
    } 
    unordered_map<string, int> wordCnt;
    for(int i = 0; i < M; ++i){
        vector<string> words;
        SplitStr(article[i][0], words, " ");
        for(auto word: words) wordCnt[word] += 3;
        // title.
        words.clear();
        SplitStr(article[i][1], words, " ");
        for(auto word: words) wordCnt[word]++;
    }
    // auto cmp = [](const pair<string, int>& a, const pair<string, int>& b){
    //     return a.second == b.second ? a.first < b.first : a.second > b.second;
    // };

    struct comp{
        bool operator()(p& a, p& b){
            return a.second == b.second ? a.first < b.first : a.second < b.second;
        }
    };
    priority_queue<p, vector<p>, comp> que;
    // priority_queue<pair<string, int>, vector<pair<string, int>>, decltype(cmp)> que(cmp);
    for(auto& it : wordCnt){
        que.emplace(it);
    }
    // for(int i = 0; i < )
    for(int i = topN - 1; i >= 0; --i){
        cout << que.top().first << " ";
        que.pop();
    }
    return 0;
}
