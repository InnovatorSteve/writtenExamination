#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main(){
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<bool>> room(n, vector<bool>(m, false));
    getchar();
    string commmand;
    getline(cin, commmand);
    room[0][0] = true;
    int x = 0, y = 0, count = 1;
    for(int i = 0; i < commmand.size(); ++i){
        if(commmand[i] == 'S') ++x;
        if(commmand[i] == 'W') --x;
        if(commmand[i] == 'A') --y;
        if(commmand[i] == 'D') ++y;
        if(room[x][y] == false){
            room[x][y] = true;
            count++;
        }
        if(count == n * m){
            cout << "Yes" << endl << i + 1 << endl;
            return 0;
        }
    }
    cout << "No" << endl << n * m - count << endl;
}