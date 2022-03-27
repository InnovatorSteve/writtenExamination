#include<iostream>
#include<vector>
using namespace std;
vector<int> BrianKernighan(int num){
    vector<int> ans(num + 1);
    for(int i = 0; i <= num; ++i){
        int temp = i;
        int cnt = 0;
        while(temp){
            temp &= temp - 1;
            ++cnt;
        }
        ans[i] = cnt;
    }
    return ans;
}
//最高有效位
vector<int> HightestValidBit(int num){
    vector<int> ans(num + 1);
    int Highbits = 0;
    for(int i = 1; i <= num; ++i){
        if((i & (i - 1)) == 0)
            Highbits = i;        
        ans[i] = ans[i - Highbits] + 1;
    }
    return ans;
}
//最低有效位
vector<int> LowestVaildBit(int num){
    vector<int> ans(num + 1);
    for(int i = 0; i <= num; ++i){
        ans[i] = ans[i / 2] + i % 2;
    }
    return ans;
}
//最低设置位
vector<int> LowestSetBit(int num){
    vector<int> ans(num + 1);
    for(int i = 1; i <= num; ++i)
        ans[i] = ans[i & (i - 1)] + 1;
    return ans;
}
int main(){
    int num;
    cin >> num;
    vector<int> ans;
    // ans = BrianKernighan(num);
    // ans = HightestValidBit(num);
    // ans = LowestVaildBit(num);
    ans = LowestSetBit(num);
    for(auto n : ans) cout << n << " ";
    cout << endl;
    system("pause");
    return 0;
}