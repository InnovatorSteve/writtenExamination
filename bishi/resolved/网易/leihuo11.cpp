#include<iostream>
#include<string>
#include<vector>
using namespace std;


string func(int n, vector<int>& nums){
    bool flag = false;
    int spaceNum = 0;
    for(auto& num : nums){
        if(num < 32){
            return "0";
        }
        if(num < 65){
            flag = true;
            spaceNum = num;
        }
    }
    if(flag){
        int magic = spaceNum - 32;
        string str;
        for(int i = 0; i < nums.size(); ++i){
            nums[i] -= magic;
            if(nums[i] < 65 && nums[i] != 32){
                return "0";
            }
            str += (char)nums[i] ;
        }
        return str;
    }else{
        int count = 0;
        for(int i = 0; i <= 999; ++i){
            for(auto num : nums){
                num -= i;
                if(num < 65 && num != 32){
                    return to_string(count);
                }
            }
            count++;
        }
        return to_string(count);
    }
}

int main(){
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; ++i){
        cin >> nums[i];
    }
    string ans = func(n, nums);
    cout << ans;
    return 0;
}