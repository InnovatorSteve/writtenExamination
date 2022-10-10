#include<iostream>
#include<string>
#include<stack>
#include<unordered_map>

using namespace std;

class Solution {
public:
    stack<char> opt;
    stack<int> nums;
    unordered_map<char, int> optPri = {{'+', 1}, {'-', 1}, {'*', 2}, {'/', 2}};
    int calculate(string s) {
        for(int i = 0; i < s.size(); ++i){
            if(s[i] == ' ') continue;
            if(isdigit(s[i])){
                int num = 0;
                while(isdigit(s[i])) num = num * 10 + s[i++] - '0';
                nums.push(num); --i;
            }else if(s[i] == '(') opt.push(s[i]);
            else if(s[i] == ')'){
                while(!opt.empty() && opt.top() != '(') eval();
                opt.pop();
            }else{
                while(!opt.empty() && optPri[opt.top()] > optPri[s[i]]) eval();
                opt.push(s[i]);
            }
        }
        while(!opt.empty()) eval();
        return nums.top();
    }
    void eval(){
        int num1 = nums.top(); nums.pop();
        int num2 = nums.top(); nums.pop();
        if(opt.top() == '+') nums.push(num2 + num1);
        else if(opt.top() == '-') nums.push(num2 - num1);
        if(opt.top() == '*') nums.push(num2 * num1);
        if(opt.top() == '/') nums.push(num2 / num1);
        opt.pop();
    }
};

int main(){
    Solution s;
    cout << s.optPri['('] << endl;
    string str = "1*2-3/4+5*6-7*8+9/10";
    int ans = s.calculate(str);
    cout << ans;
}