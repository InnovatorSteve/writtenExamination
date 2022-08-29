/*
    现在有一个数组，想把这个数组变成"长城" 即对于长城中每一个元素左右两边的元素相等，并且与它不相等。 
    例如{2, 1, 2, 1, 2}, {1, 9, 1, 9}是长城，{2,1,3,2,4},{1,1,4,5,1,4}则不是长城,你每次可以将一个元素变成另一个元素，请问量少需要几次操作?
    输入描述:
    第一行输入一个整数n(1 <= n <= 4x1e5)代表数组的长度。
    第二行输入 n 个正整数 ai(1 <= ai <= 1e9)表示数组的每一个元素。
    输出描述:
    输出一个整数表示最少的操作次数。
    示例1输入输出示例仅供调试，后台判题数据一般不包含示例.
    输入
    6 1 1 4 5 1 4
    输出
    3
    说明:得到的长城为(1,5,1,5,1,5},可以证明，
    没有操作更少的方法。
*/
#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> num(n);
    map<int, int> mapOdd, mapEven;
    vector<int> oddNum(2), oddCount(2), evenNum(2), evenCount(2);
    for(int i = 0; i < n; ++i){
        cin >> num[i];
        if(i % 2 == 0){
            mapEven[num[i]]++;
            int tempNum = mapEven[num[i]];
            if(num[i] == evenNum[0]){
                evenCount[0] = max(tempNum, evenCount[0]);
            }else if(tempNum > evenCount[1]){
                evenCount[1] = tempNum;
                evenNum[1] = num[i];
            }
            if(evenCount[1] > evenCount[0] && evenNum[1] != evenNum[0]){
                swap(evenCount[0], evenCount[1]);
                swap(evenNum[0], evenNum[1]);
            }
        }else{
            mapOdd[num[i]]++;
            int tempNum = mapOdd[num[i]];
            if(num[i] == oddNum[0]){
                oddCount[0] = max(tempNum, oddCount[0]);
            }else if(tempNum > oddCount[1]){
                oddCount[1] = tempNum;
                oddNum[1] = num[i];
            }
            if(oddCount[1] > oddCount[0] && oddNum[1] != oddNum[0]){
                swap(oddCount[0], oddCount[1]);
                swap(oddNum[0], oddNum[1]);
            }
        }
    }
    int sum = 0;
    if(oddNum[0] == evenNum[0]){
        sum = n - max(oddCount[0] + evenCount[1], oddCount[1] + evenCount[0]);
    }else{
        sum = n - (oddCount[0] + evenCount[0]);
    }
    cout << sum;
}