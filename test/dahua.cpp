#include<iostream>
#include<vector>
#include<list>
using namespace std;
// void solution(vector<int>& nums){
//     list<int> ans;
//     ans.push_back(nums[0]);
//     for(int i = 1; i < nums.size(); ++i){
//         if(nums[i] >= ans.back())
//             ans.push_back(nums[i]);
//         else{
//             while(ans.back() > nums[i])
//                 ans.pop_back();
//         }
//     }
//     while(!ans.empty()){
//         cout << ans.front() << " ";
//         ans.pop_front();
//     }
// }

// int main(){
//     int N;
//     cin >> N;
//     vector<int> nums(N);
//     for(int i = 0; i < N; ++i)
//         cin >> nums[i];
//     solution(nums);
//     return 0;
// }

//已经提交了

int main(){
    // int a[10]={0,1,2,3,4,5,6,7,8,9},*p=&a[3],b; 
    // p++; 
    // b = p[4]; 
    // p[4]--;
    // std::cout << b;
    char matrix[][2] = {'a','b','c','d','e','f'}; 
    char (*p)[2] = matrix; 
    *p++; 
    printf("%c\n",**p); return 0;
    
}