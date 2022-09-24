//规划最短路由：1.TTL代表生存周期。2.TTL为固定值，输入给出。 3.每个路由之间距离不一，求在TTL内可走的最短距离线路。
//输入：路由器连接边个数N, 起点路由器ID，终点路由ID，起点IP报文的TTL。
//第二行-第N + 1行，路由器连接边信息，两个路由器ID以及之间的距离。
//输出：到达终点时的最短距离和到达终点时的TTL，如果有多个结果，输出达到终点时TTL最大的那组数据，无法到达种地按输出-1。
// 10 1 7 255                                
// 1 2 3
// 1 5 2
// 1 8 5
// 2 3 3
// 2 5 3 
// 3 4 3
// 4 7 3
// 5 6 2
// 6 7 2
// 8 7 6
//输出 6 252
// 10 1 7 255
// 1 2 3
// 1 8 4
// 2 8 4
// 2 3 6
// 2 5 3
// 3 8 4
// 3 4 4
// 4 5 3
// 4 7 3
// 3 7 4
//输出 12 252
#include<iostream>
#include<vector>
#include<map>
#include<list>
#include<algorithm>
using namespace std;
// int ans = INT_MAX;
// int rt = -1;
// int N = 510;
// map<int, list<int>> g;
// int n, st, ed, ttl;
// vector<bool> visit(N);
// vector<vector<int>> d(N, vector<int>(N));
// void dfs(int u, int p, int k, int s){//u 节点  p 父节点  k ttl  s距离
//     if(k < 0) return;
//     if(u == ed){
//         if(s < ans){
//             ans = s;
//             rt = k;
//         }else if(s == ans){
//             rt = max(k, rt);
//         }
//     }
//     visit[u] = true;
//     for(int v : g[u]){
//         if(v == p || visit[v]) continue;
//         dfs(v, u, k - 1, s + d[u][v]);
//     }
//     visit[u] = false;
// }

// int main(){
//     cin >> n >> st >> ed >> ttl;
//     for(int i = 0; i < n; ++i){
//         int a, b, c;
//         cin >> a >> b >> c;
//         g[a].push_back(b);
//         g[b].push_back(a);
//         d[a][b] = d[b][a] = c;
//     } 
//     dfs(st, -1, ttl, 0);
//     if(rt == -1)
//         cout << -1;
//     else
//         cout << ans << " " << rt;
// }
int ans = INT_MAX;
int lastTTL = -1;
vector<bool> used;
void backtracking(int curStart, int end, int ttl, int distance, vector<vector<int>>& matrix){
    if(ttl < 0 || (distance >= ans && ttl <= ttl)) return;
    if(curStart == end){
        if(distance <= ans){
            ans = distance;
            // lastTTL = ttl;
            lastTTL = max(lastTTL, ttl);
        }
        return;
    }
    for(int i = 1; i < matrix[0].size(); ++i){
        if(matrix[curStart][i] != 0 && used[i] == false){
            used[i] = true;
            backtracking(i, end, ttl - 1, distance + matrix[curStart][i], matrix);
            used[i] = false;
        }
    }
}

int main(){
    int N, start, end, ttl;
    cin >> N >> start >> end >> ttl;
    vector<vector<int>> matrix(N + 1, vector<int>(N + 1, 0));
    for(int i = 0; i < N; ++i){
        int left, right, weight; cin >> left >> right >> weight;
        matrix[left][right] = weight;
        matrix[right][left] = weight;
    }
    used.resize(N + 1, false);
    used[start] = true;
    backtracking(start, end, ttl, 0, matrix);
    cout << ans << " " << lastTTL << endl;
}