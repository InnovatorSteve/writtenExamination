#include<iostream>
#include<string>
#include<vector>
using namespace std;

c

void test(){
    string str1 = "hello";
    string str2;
    str2 = move(str1);
    cout << "str1=" << str1 << "&" << &str1 << endl;
    cout << "str2=" << str2 << "&" << &str2 << endl;

}

void heike(string& str){
    int pos = str.find(":") + 1;
    while(str[pos] == '\\' || str[pos] == '/') pos++;
    string ans = str.substr(0, str.find(":") + 1) + "//" +  str.substr(pos);
    cout << ans;
}
int main(){
    string str;
    getline(cin, str);
    //heike(str);
    // vector<string> words;
    // words = move(split(str, " "));
    // printf("%d\n", &words);

    // for(auto word : words) cout << word << " ";
    test();
    return 0;
}

//nihao wo lai zi ni de guo jia hai z zs z  z? ? ?