    // 给定一个只包含小写字母字符串， 每次可以选择两个相同的字符删除， 并在字符串结尾新增任意一个小写字母。
    // 请问最少多少次操作后，所有的字母都不相同?
    // 示例1    输入输出示例仅供调试， 后台判题数据一般不包含示例.输入"abab"
    // 输出说明:第一次操作删除两个b生成一个a。第二次操作可以选择删除两个a，生成一个b， 字符串变成ab，满足条件，操作次数为2。
#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main(){
    string str;
    cin >> str;
    vector<int> arr(26);
    int opCnt = 0, remainCnt = 0;//opCnt 删除的操作次数，同时也是生成的字符个数，remainCnt代表原本存在删除字母后剩余的个数。
    for(int i = 0; i < str.size(); ++i){
        arr[str[i] - 'a']++;
        opCnt += arr[i] / 2;
        remainCnt += arr[i] % 2;
    }   
    if(opCnt + remainCnt <= 26)
        cout << opCnt;
    else
        cout << 2 * opCnt - (26 - remainCnt);//超过26个字母后，必然要重复，上一阶段删除多少个就生成多少个任意字母。同时此时各剩余字母个数为1
        //那么就是在删除opCnt次，同时减去26-remainCnt代表空着的位置，这部分不用删除。
    //这里要考虑的是 可能第二遍删除的时候，opCnt过大，第二遍仍然溢出需要再删除。
    //


    // if(opCnt + remainCnt <= 26)
    //     cout << opCnt;
    // else{
    //     int tempOpCnt = opCnt - (26 - remainCnt), tempRemainCnt = remainCnt;
    //     while(tempOpCnt > 26){
    //         opCnt += tempOpCnt;
    //         tempOpCnt = tempOpCnt - 26;
    //     }
    //     opCnt += tempOpCnt;
    //     cout << opCnt;
    // }
}