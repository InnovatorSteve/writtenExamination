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