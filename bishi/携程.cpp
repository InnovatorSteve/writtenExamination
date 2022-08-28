#include <iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
//buzhidao
void solution1(int n){
    for(int i = 1; i <= n; ++i){
        int x = i;
        int flag = 0;
        long long num = x;
        string numS;
        while(num){
            numS += num % 10 + '0';
            num /= 10;
        }
        reverse(numS.begin(), numS.end());
        string number = "0123456789";
        for(int i = 0; i <= numS.size() && !flag; ++i){
            for(int j = 0; j < 10 && !flag; ++j){
                string new_num = numS;
                new_num.insert(i, number, j, 1);
                long long num = 0;
                for(auto ch : new_num){
                    num = num * 10 + ch - '0';
                }
                if(num != x && num % 7 == 0){
                    cout << "原数：" << x << "  添加后" << num << endl;
                    flag = 1;
                    //return 0;
                }
            }
        }
    }
    
}
void solution2(int n){
    for(int i = 1; i <= n; ++i){
        int flag  = 0;
        for(int j = 0; j < 10; ++j){
            int num = i * 10 + j;
            if(num % 7 == 0){
                // cout << "i : " << i << "  num = "<< num << endl; 
                flag = 1;
            }
        }
        if(!flag)
            cout << "n!!!" << i << endl;
    }
}
void test(){
    std::string str="to be question";
    std::string str2="the ";
    std::string str3="or not to be";
    std::string::iterator it;

    for(int i = 0; i <= str.size(); ++i){
        string s = str;
        s.insert(i, "!");
        cout << s << endl;
    }
    // used in the same order as described above:
    // str.insert(6,str2);                 // to be (the )question
    // str.insert(6,str3,3,4);             // to be (not )the question
    // str.insert(10,"that is cool",8);    // to be not (that is )the question
    // str.insert(10,"to be ");            // to be not (to be )that is the question
    // str.insert(15,1,':');               // to be not to be(:) that is the question
    // it = str.insert(str.begin()+5,','); // to be(,) not to be: that is the question
    // str.insert (str.end(),3,'.');       // to be, not to be: that is the question(...)
    // str.insert (it+2,str3.begin(),str3.begin()+3); // (or )

    // std::cout << str << '\n';

}
int main() {
    // solution2(1000);
    test();
    return 0;
}