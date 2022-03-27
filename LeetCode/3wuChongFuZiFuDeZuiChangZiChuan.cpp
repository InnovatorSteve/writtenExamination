#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int lengthOfLongestSubstring(string s){
    string str;
    int Max = 0;
    for(int i = 0; i < s.size(); ++i){
        int pos = str.find(s[i]);
        if(pos != -1)
            str.erase(0, pos + 1);  //��str = str.substr(pos + 1)   ��Ϊerase  ���ٸ�ֵ  �������
        str += s[i];
        Max = max(Max, (int)str.size());
    }
    return Max;
}
int main(){
    string s = "abcabcbb";
    int ans = lengthOfLongestSubstring(s);
    cout << ans << endl;
    return 0;
}