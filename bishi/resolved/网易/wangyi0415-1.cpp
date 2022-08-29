#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int N;
    cin >> N;
    vector<int> jump(N);
    vector<bool> visit(N, false);
    for(int i = 0; i < N; ++i)  cin >> jump[i];
    int ans = 0, pos = 0;
    visit[0] = true;
    for(int i = 0; i < N;){
        if(pos - jump[i] <=0 || pos + jump[i] >= N || visit[i - 1]){
            pos = pos + jump[i];
            ans++;
        }else{
            int leftLength = jump[i];
            int curmax = 0, index = i;
            while(leftLength){
                if(curmax <= jump[i - leftLength])
                    curmax = jump[i - leftLength], index = i - leftLength;
                visit[i - leftLength--] = true;
            }
            if(curmax != 0)
                if(index + curmax > pos + jump[i] + jump[pos + jump[i]])
                    pos = index + curmax, ans++;
                else
                    pos = pos + jump[i];
            else
                pos = pos + jump[i];
                    
            ans++;
        }
        visit[pos] = true;
        ans++;
        i = pos;
    }
    cout << ans << endl;
    return 0;
}