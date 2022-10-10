#include<iostream>
#include<sstream>
#include<string>
#include<algorithm>
#include<stack>
#include<map>
#include<unordered_map>
using namespace std;

stack<char> opt;
stack<int> nums;
unordered_map<char, int> priOpt = {{'+', 1}, {'-', 1}, {'*', 2}, {'/', 2}};//未定义(  获取时返回0  复合逻辑上计算到(停止

void calHouZhui(){
    int num1 = nums.top(); nums.pop();
    int num2 = nums.top(); nums.pop();
    char curOpt = opt.top(); opt.pop();
    if(curOpt == '+') nums.push(num2 + num1);
    else if(curOpt == '-') nums.push(num2 - num1);
    else if(curOpt == '*') nums.push(num2 * num1);
    else if(curOpt == '/') nums.push(num2 / num1);
}

int calStr(string& str){
    while(!nums.empty()) nums.pop();
    for(int i = 0; i < str.size(); ++i){
        if(str[i] == ' ') continue;
        if(isdigit(str[i])){
            int num = 0;
            while(isdigit(str[i])) num = num * 10 + str[i++] - '0';
            --i;
            nums.push(num);
        }else if(str[i] == '(') opt.push(str[i]);
        else if(str[i] == ')'){
            while(!opt.empty() && opt.top() != '(') calHouZhui();
            if(!opt.empty()) opt.pop();//弹出  '('
        }else{
            while(!opt.empty() && priOpt[opt.top()] >= priOpt[str[i]]) calHouZhui();
            opt.push(str[i]);//压入当前操作符
        }
    }
    while(!opt.empty())
        calHouZhui();
    return nums.top();
}

// #include<iostream>
// #include<sstream>
// #include<string>
// #include<algorithm>
// #include<stack>
// #include<map>
// using namespace std;
// const string split = " ";
// map<char, int> priority = { {'+', 1}, {'-', 1}, {'*', 2}, {'/', 2}, {'(', 0}, {')', 0}};
// string getPostExpre(string& s){
//     string postExpre;
//     stack<char> symbol;
//     for(int i = 0; i < s.size(); ++i){
//         if(isdigit(s[i])){
//             postExpre += s[i];
//             while(i + 1 < s.size() && isdigit(s[i + 1])) postExpre += s[++i];  //不断后移
//             postExpre += split;
//         }else if(symbol.empty() || s[i] == '(' || priority[s[i]] >= priority[symbol.top()]){
//             symbol.push(s[i]);
//         }else if(s[i] == ')'){
//             while(!symbol.empty() && symbol.top() != '(') postExpre += symbol.top() + split, symbol.pop();
//             if(!symbol.empty()) symbol.pop(); //弹出到( （也要记得弹出
//         }else if(priority[s[i]] < priority[symbol.top()]){  //大于等于当前优先级 出栈 再压栈当前操作符
//             while(!symbol.empty() && priority[s[i]] <= priority[symbol.top()]) postExpre += symbol.top() + split, symbol.pop();
//             symbol.push(s[i]);
//         }
//     }
//     while(!symbol.empty()) postExpre += symbol.top() + split, symbol.pop();
//     return postExpre;
// }

// int cal(string& s){
//     stringstream ss(s);
//     string curstr;
//     stack<int> calSt;
//     int ans = 0;
//     while(ss >> curstr){
//         if(isdigit(curstr[0]))
//             calSt.push(stoi(curstr));
//         else{
//             int num1 = calSt.top(); calSt.pop();
//             int num2 = calSt.top(); calSt.pop();
//             switch (curstr[0])
//             {
//             case '+': ans = num2 + num1; break;
//             case '-': ans = num2 - num1; break;
//             case '*': ans = num2 * num1; break;
//             case '/': ans = num2 / num1; break;
//             default:  break;
//             }
//             calSt.push(ans); //把当前计算结果压入栈
//         }
//     }
//     return calSt.top();
// }
// int main(){
//     string s = "2 +20- 2 * 6 +5 *7 * (80 / 10)";//"9+(3-1)*3+10/2";//"1 +3 + 2 *4 *( 5 -2 ) * 3 + 2 ";//
//     s.erase(remove(s.begin(), s.end(), ' '), s.end()); //处理空格
//     string postExpre;
//     postExpre = getPostExpre(s);
//     cout << cal(postExpre) << endl;
//     return 0;
// }
