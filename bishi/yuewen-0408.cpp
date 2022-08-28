#include<iostream>
#include<string>
using namespace std;

void vec_reverse(string& str, int i){
    int n = str.size();
    str += str.substr(0, i);
    str.erase(str.begin(), str.begin() + i);
}
int main(){
    string str;
    int i;
    cin >> str >> i;
    vec_reverse(str, i);
    cout << str;
    return 0;
}