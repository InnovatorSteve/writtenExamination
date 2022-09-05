//给定目标个数和伪装便是精度，初始值任意，不计入次数。第二行给出目标值，需要依次伪装(变换一次的值大小不限)，需要最少变换多少次？
//5 4
//4 9 6 7 8
//输出0      小绿将初始伪装度设置为6，由于4,9,6,7,8与6的绝对值都不超过4，因此小绿可以成功入侵这些主机。 综上，小绿最少需要变化0次伪装度。
#include<iostream>
#include<vector>

using namespace std;

int main(){
    int n, x;
    cin >> n >> x;
    vector<int> nums(n);
    vector<vector<int>> arr(n, vector<int>(2));
    for(int i = 0; i < n; ++i){
        cin >> nums[i];
        arr[i][0] = nums[i] - x; //下行区间
        arr[i][1] = nums[i] + x;
    }    
    int ans = 0;
    int minNum = INT_MIN, maxNum = INT_MAX;
    for(int i = 0; i < n; ++i){
        minNum = max(arr[i][0], minNum);
        maxNum = min(maxNum, arr[i][1]);
        if(minNum > maxNum){
            ++ans;
            minNum =INT_MIN; maxNum = INT_MAX;
        }
    }
    cout << ans;
}