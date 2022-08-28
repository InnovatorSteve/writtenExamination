#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main(){
    string input;
    getline(cin, input);
    vector<vector<int>> cox;
    size_t pos = 0;
    int i = 0;
    while(input.size()){
        int num1 = stoi(input, &pos);
        if(pos < input.size())
            input = input.substr(pos + 1);
        else break;
        int num2 = stoi(input, &pos);
        if(pos < input.size())
            input = input.substr(pos + 1);
        vector<int> temp = {num1, num2};
        cox.emplace_back(temp);
    }
    int ans = cox.size();
    if(ans <= 1) return ans;
    for(int i = 0; i < cox.size() - 1; ++i){
        for(int j = i + 1; j < cox.size(); ++j){
            if(cox[i][0] >= cox[j][0] && cox[i][1] <= cox[j][1]){
                --ans;
                break;
            }
            if(cox[j][0] >= cox[i][0] && cox[j][1] <= cox[i][1]){
                --ans;
                swap(cox[i], cox[j]);
                break;
            }
        }
    }
    cout << ans;
    return 0;
}