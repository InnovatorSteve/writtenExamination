#include<iostream>
#include<vector>
#include<string>
#include<set>
using namespace std;

static int ans = 0;
static set<string> stringList;

void dfs(set<string>& strList, set<string>& strList1, int startIndex, int endIndex, string str1){
    if(stringList.size() == strList.size()){
        set<string> temp(stringList);
        if(temp == strList)
            ans++;
        return;
    }
    for(int i = endIndex; i <= str1.length(); ++i){
        string subStr = str1.substr(startIndex, endIndex);
        if(strList1.find(subStr) != strList1.end()){
            strList1.erase(subStr);
            stringList.insert(subStr);
            int temp1 = startIndex, temp2 = endIndex;
            startIndex = endIndex;
            endIndex++;
            dfs(strList, strList1, startIndex, endIndex, str1);
            vector<string> tempvec(stringList.begin(), stringList.end());
            tempvec.pop_back();
            set<string> tempset(tempvec.begin(), tempvec.end());
            stringList = tempset;
            strList1.insert(subStr);
            startIndex = temp1;
            endIndex = temp2 + 1;
        }else{
            endIndex++;
        }
    }
}

int main(){
    int n, m;
    cin >> n >> m;
    string str;
    cin >> str;
    vector<int> arrLength(m);
    for(int i = 0; i < m; ++i){
        cin >> arrLength[i];
    }
    set<string> strList;
    for(int i = 0; i < m; ++i){
        string tempstr;
        cin >> tempstr;
        strList.insert(tempstr);
    }
    set<string> strList1;
    dfs(strList, strList1, 0, 1, str);
    cout << ans;
    return 0;

}