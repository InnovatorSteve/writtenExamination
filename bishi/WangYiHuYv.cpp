// #include<iostream>
// #include<vector>
// #include<unordered_map>
// using namespace std;

// void calculRequiredphysicalstrength(int x, int y, vector<vector<bool>>& checkerBoardFlag, vector<vector<char>>& checkerBoard, 
// vector<int>& curForces, int strength, vector<pair<int, int>> enemy){
//     if(x < 0 || x >= checkerBoard.size() || y < 0 || y >= checkerBoard[0].size()) return;
//     if(checkerBoard[x][y] == 'W' || !strength || checkerBoardFlag[x][y]) return;
//     if(checkerBoard[x][y] == 'E'){
//         curForces[]
//     }
//     if() return;
//     checkerBoardFlag[x][y] = true;
//     calculRequiredphysicalstrength(x + 1, y, checkerBoardFlag, checkerBoard, curForces);
// }
// int main(){
//     int T;
//     cin >> T;
//     while(T--){
//         int N, M, A, B;
//         cin >> N >> M >> A >> B;
//         vector<int> ability(A);
//         for(int i = 0; i < A; ++i)
//             cin >> ability[i];
//         vector<vector<char>> checkerBoard(N, vector<char>(M));
//         vector<pair<int, int>> friendlyForces(A);
//         vector<pair<int, int>> enemy;
//         for(int i = 0; i < N; ++i){
//             for(int j = 0; j< M; ++j){
//                 cin >> checkerBoard[i][j];
//                 if(checkerBoard[i][j] == 'E')
//                     enemy.emplace_back(i, j);
//                 else if(checkerBoard[i][j] >= '0' && checkerBoard[i][j] <= '9')
//                     friendlyForces[checkerBoard[i][j] - '0'] = {i, j};
//             }
//         }

//         vector<vector<int>> requiredPhysicalStrength(A, vector<int>(B));
//         vector<vector<bool>> checkerBoardFlag(N, vector<bool>(M, false));
//         int i = 0;
//         for(auto it : friendlyForces)
//             calculRequiredphysicalstrength(it.first, it.second, checkerBoardFlag, 
//             checkerBoard, requiredPhysicalStrength[i++], ability[i++], enemy);
//         cout << "!" << endl;
//     }
//     return 0;
// }

#include <bits/stdc++.h>
#define rep(i, l, r) for (int i = l; i <= r; ++i)
using namespace std;
const int N = 55;
char g[N][N];
int a[N];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
vector<pair<int, int>> E, F;
int flag, n, m, A, B;
int getDis(int x, int y, int xx, int yy) {  // bfs
    return abs(x - xx) + abs(y - yy);
}

void solve() {
    flag = 0;
    cin >> n >> m >> A >> B;
    rep(i, 0, A - 1) cin >> a[i];
    rep(i, 1, n) cin >> g[i] + 1;
    if (A < B) {
        cout << -1 << '\n';
        return;
    }

    rep(i, 1, n) rep(j, 1, m) {
        if (g[i][j] == 'E') {
            E.emplace_back(i, j);
        } else if (isdigit(g[i][j])) {
            F.emplace_back(i, j);
        }
    }
    vector<int> val;
    for (int i = 0; i < E.size(); ++i) val.push_back(INT_MAX);
    for (auto f : F)
        for (int i = 0; i < E.size(); ++i) {
            int x = getDis(f.first, f.second, E[i].first, E[i].second);
            val[i] = min(val[i], x);
        }
    long long ans = 0;
    for (int x : val) ans += x;
    if (ans > INT_MAX)
        cout << -1 << '\n';
    else
        cout << ans << '\n';
}
int main() {
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}
