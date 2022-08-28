#include<iostream>
#include<vector>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; ++i)
        cin >> arr[i];
    int candti = arr[0], candtiCnt = 1;
    for(int i = 2; i < n; i += 2){
        if(candti == arr[i])
            candtiCnt++;
        else{
            candtiCnt--;
            if(candtiCnt == 0)
                candti = arr[i], candtiCnt++;
            
        }
    }

    int candti2 = INT_MIN, candtiCnt2 = 1;
    for(int i = 1; i < n; i += 2){
        if(arr[i] == candti) continue;
        if(candti2 == arr[i])
            candtiCnt2++;
        else{
            candtiCnt2--;
            if(candtiCnt2 == 0)
                candti2 = arr[i], candtiCnt2++;
        }
    }
    int cand1Num = 0;
    for(int i = 0; i < n; i+=2)
        if(arr[i] == candti)
            cand1Num++;
    int cand2Num = 0;
    for(int i = 1; i < n; i+=2)
        if(arr[i] == candti2)
            cand2Num++;
    cout << n - cand1Num - cand2Num;

}