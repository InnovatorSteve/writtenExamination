/*
    題目描述:
    有一个长度为n的大布料S(仅包含小写英文字母的字符串),可以将布料在任意位置剪切，例如布料abcd可以被裁剪为a与bcd或ab与cd或abc与d。
    不过,裁剪完之后是不能拼接起来的，现在小团想知道能不能有一种裁剪方式能让他把布料恰好裁剪成客人要求的小布料。
    形式化地,有一个串S,问是否能将其划分成m个不相交的连续子串,使得这些连续子串可以与要求的连续子串一一对应,
    两个串相对应是指这两个用完全相等,例如"aab"="aab"但"aab"!='baa"
    输入描述：
    第一行两个空槽隔开的正整数n和m,分别表示大布料S长度和客人要求的小布料数量。
    整下来一行一个长度为n的仅包含小写英文字母的串S,表示大布料的组成。
    接下来一行m个空格隔开的数x1,x2,...,xm,依次表示所要求的小布料长度。
    成接下来开始m行,每行一个长度为Xi的仅包含小写英文字母的串Si,表示第i个小布料的组对
    于所有数握, 1 <= m <= 9, 1 <= n <= 20, 1 <= Xi <=n
    输出描述：
    如果存在这样的方案，输出方案总数。如果不存在任何方案，输出0。两个方案A、B不相同。当且仅当方案A中存在一个相对于原始长布料的裁剪位置i， 
    而方案B中并未在该位置i裁剪，例如aaaaaaa 裁剪方案aa|aaaa 与方案 aaa|aaa是相同的方案。 而方案aa|aaaa与方案aaaa|aa是不同的方案，
    虽然划分出的结果都是aa与aaaa， 但前者在第二个a处进行了裁剪，后者并没有在这里进行裁剪， 所以视为不同的裁剪方案。
    样例输入：
    6 2
    aaaaaa
    4 2
    aaaa
    aa
    样例输出：
    2
*/
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<set>
using namespace std;
// bool isValid(vector<string> str1, vector<string> str2){
//     sort(str1.begin(), str1.end());
//     sort(str2.begin(), str2.end());
//     return str1 == str2;
// }
// vector<string> path;
// vector<vector<string>> ans;
// void backtrace(string& str, vector<string>& path, int startIdx, vector<string>& bu_s, int m){
//     if(startIdx > str.length())
//         return;
//     if(path.size() == m && isValid(path, bu_s))
//         ans.emplace_back(path);
//     for(int i = startIdx; i < str.length(); ++i){
//         path.emplace_back(str.substr(startIdx, i + 1 - startIdx));   //遍历所有可能的裁剪方法，可以进一步剪枝降低复杂度
//         backtrace(str, path, i + 1, bu_s, m);
//         path.pop_back();
//     }
// }

// int main(){
//     int n, m;
//     string str;
//     cin >> n >> m >> str;
//     vector<int> arr_s(m);
//     vector<string> bu_s(m);
//     for(int i = 0; i < m; ++i)
//         cin >> arr_s[i];
//     for(int i = 0; i < m; ++i)
//         cin >> bu_s[i];
//     backtrace(str, path, 0, bu_s, m);
//     cout << ans.size();
// }
bool isVaild(string& str, vector<string>& path){
    string cmpStr;
    for(auto& s : path)
        cmpStr += s;
    return cmpStr == str;
}
vector<string> path;
vector<vector<string>> ans;  //以布料为最小单位去匹配，极大降低单字符匹配的复杂度。
void backtrace(string& str, vector<string>& bu_s, int m, vector<bool>& used){
    if(path.size() == m && isVaild(str, path)){
        ans.emplace_back(path);
    }
    for(int i = 0; i < bu_s.size(); ++i){
        if(used[i]) continue;
        used[i] = true;
        path.emplace_back(bu_s[i]);
        backtrace(str, bu_s, m, used);
        path.pop_back();
        used[i] = false;
    }
}

int main(){
    int n, m;
    string str;
    cin >> n >> m >> str;
    vector<int> arr_s(m);
    vector<string> bu_s(m);
    for(int i = 0; i < m; ++i)
        cin >> arr_s[i];
    for(int i = 0; i < m; ++i)
        cin >> bu_s[i];
    vector<bool> used(m, false);
    backtrace(str, bu_s, m, used);
    set<vector<string>> moveRepeate(ans.begin(), ans.end());
    cout << moveRepeate.size();
}
