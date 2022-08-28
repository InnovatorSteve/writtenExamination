#include<iostream>
#include<deque>
#include<vector>

using namespace std;

int main(){
    int n;
    cin >> n;
    deque<int> input;
    deque<int> output;
    while(n--){
        int m;
        cin >> m;
        input.push_back(m);
    }
    
    while(!input.empty()){
        output.push_front(input.back());
        input.pop_back();

        int curPuKu = output.back();
        output.pop_back();
        output.push_front(curPuKu);

        curPuKu = output.back();
        output.pop_back();
        output.push_front(curPuKu);
    }
    while(!output.empty()){
        cout << output.front();
        output.pop_front();
    }
    return 0;
}