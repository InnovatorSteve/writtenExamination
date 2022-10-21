// #include<iostream>
// #include<stack>
// #include<vector>
// #include<string>
// #include<sstream>
// #include<map>
// using namespace std;

// const string split = " ";
// map<char, int> priority = { {'+', 1}, {'-', 1}, {'*', 2}, {'/', 2}, {'(', 0}, {')', 0}};
// string getPostExpre(string s){
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
//             while(!symbol.empty() && symbol.top() != '(') 
//                 postExpre += symbol.top() + split, symbol.pop();
//             if(!symbol.empty()) symbol.pop(); 
//         }else if(priority[s[i]] < priority[symbol.top()]){
//             while(!symbol.empty() && priority[s[i]] <= priority[symbol.top()]) 
//                 postExpre += symbol.top() + split, symbol.pop();
//             symbol.push(s[i]);
//         }
//     }
//     while(!symbol.empty()) 
//         postExpre += symbol.top() + split, symbol.pop();
//     return postExpre;
// }

// int calNum(string& s){
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
//             switch (curstr[0]){
//                 case '+': ans = num2 + num1; break;
//                 case '-': ans = num2 - num1; break;
//                 case '*': ans = num2 * num1; break;
//                 case '/': ans = num2 / num1; break;
//                 default:  break;
//             }
//                 calSt.push(ans);         
//         }
//     }
//     return calSt.top();
// }
// bool ansFlag = false;
// vector<string> strVec = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9"};
// void bianLi(string str, int target){
//     for(size_t i = 0; i <= str.size(); ++i){
//         if((isdigit(str[i]) || i  + 1 < str.size() && isdigit(str[i + 1])) || (i - 1 >= 0 && isdigit(str[i - 1])))
//             for(char j = 0; j <= 9; ++j){
//                 str.insert(i, strVec[j]);
//                 string PostExpre = getPostExpre(str);
//                 int num = calNum(PostExpre);
//                 if(num == target)
//                     ansFlag = true;
//                 str.erase(i, 1);
//                 if(num > target) break;
//             }
//     }
    
// }

// bool func(string& str){
//     // str.erase(remove(str.begin(), str.end(), ' '), str.end());
//     size_t Equalpos = str.find('=');
//     string postExpre = getPostExpre(str.substr(0, Equalpos));
//     int leftNum = calNum(postExpre);
//     postExpre = getPostExpre(str.substr(Equalpos + 1));
//     int rightNum = calNum(postExpre);
//     if(leftNum == rightNum)
//         return true;
//     if(leftNum < rightNum){
//         bianLi(str.substr(0, Equalpos), rightNum);
//     }else{
//         bianLi(str.substr(Equalpos + 1), leftNum);
//     }
//     return ansFlag;
// }

// int main(){
//     int n;
//     cin >> n;
//     string str;
//     for(int i = 0; i < n; ++i){
//         cin >> str;
//         if(func(str)) cout << "Yes" << endl, ansFlag = false;
//         else cout << "No" << endl;
//     }
//     return 0;
// }
// 6
// 16=1+2*3
//  7*8*9=54
//  1+1=1+22 
// 4*6=22+2 
// 15+7=1+2 
// 11+1=1+5
//给定个数
//方程 是否可以通过在某位添加0-9 使得等式成立 成立输出Yes 否则输出No

#include<iostream>
#include<unordered_map>
#include<string>
#include<stack>

using namespace std;

stack<char> opt;
stack<int> nums;
unordered_map<char, int> priOpt = {{'+', 1}, {'-', 1}, {'*', 2}, {'/', 2}};//未定义(  获取时返回0  符合逻辑上计算到(停止

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

bool bianLi(string& str, int target){
    for(int i = 0; i <= str.size(); ++i){
        if(isdigit(str[i]) || isdigit(str[i - 1])){
            for(char j = '0'; j <= '9'; ++j){
                str.insert(i, 1, j);
                int num = calStr(str);
                str.erase(i, 1);
                if(num == target) return true;
                if(num > target) break;
            }
        } 
    }
    return false;
}

bool isVaild(string& str){
    size_t equalPos = str.find("=");
    string leftStr = str.substr(0, equalPos), rightStr = str.substr(equalPos + 1);
    int leftNum = calStr(leftStr);
    int rightNum = calStr(rightStr);
    if(leftNum == rightNum) return true;
    else if(leftNum < rightNum) return bianLi(leftStr, rightNum);
    else return bianLi(rightStr, leftNum);
}

int main(){
    int n;
    cin >> n;
    string str;
    for(int i = 0; i < n; ++i){
        cin >> str;
        if(isVaild(str)) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
}