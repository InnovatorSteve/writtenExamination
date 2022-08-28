// #include<iostream>
// #include<vector>
// #include<string>
// #include<set>
// using namespace std;

// static int ans = 0;
// bool isContain(string& str, int startIndex, set<string>& strList){
//     set<string> temp;
//     for(auto str : strList){
//         temp.insert(str);
//     }
//     string str1 = str.substr(0, startIndex + 1);
//     string str2 = str.substr(startIndex + 1);
//     if(strList.find(str1) != strList.end())
//         temp.erase(str1);
//     if(strList.find(str2) != strList.end())
//         temp.erase(str2);
//     if(temp.empty())
//         return true;
//     return false;
    
// }
// void dfs(string str, int startIndex, set<string>& strList){
//     if(startIndex >= str.length())
//         return;
//     for(int i = startIndex; i < str.length(); ++i){
//         if(isContain(str, i, strList)){
//             ans++;
//         }else{
//             continue;
//         }
//     }
// }

// int main(){
//     int n, m;
//     cin >> n >> m;
//     string str;
//     cin >> str;
//     vector<int> arrLength(m);
//     for(int i = 0; i < m; ++i){
//         cin >> arrLength[i];
//     }
//     set<string> strList;
//     for(int i = 0; i < m; ++i){
//         string tempstr;
//         cin >> tempstr;
//         strList.insert(tempstr);
//     }
//     dfs(str, 0, strList);
//     cout << ans;
//     return 0;

// }