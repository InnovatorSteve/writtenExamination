#include<iostream>
#include<list>
#include<string>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;
//超级玛丽 需要通过一个吊桥，吊桥上有木板存在缺失，一旦踩到生命值会-1，并在原地复活(不受缺失木板的影响)。超级玛丽从起点S开始，
//可以走到下一个木板(计1)，也可以跨过一个(计2)或两个木板(计3)。最终必须刚好走到终点E。 (S, mu, mu, mu que, mu, mu, E);
//现在给定生命值M, 吊桥长度N, 缺失木板数K, 已经缺失标号数组L, 计算出有多少种方法可以通过。
//输入： 2  2  1
    //  2
//输出： 4
//解释：4种走法，3, 1 - 2, 2 - 1, 1 - 1(复活) - 1
//输入：1 3 2
//      1 3
//输出： 1      //解释： 2 - 2
vector<bool> visted;
int ansDistance = INT_MAX, lastTTL = -1;
void backtracking(int curStart, int end, int distance, int ttl, vector<vector<int>>& matrix){
    if(ttl < 0 || (distance >= ansDistance && ttl <= lastTTL)) return;
    if(curStart == end){
        if(distance <= ansDistance){
            ansDistance = distance;
            lastTTL = max(lastTTL, ttl);
        }
        return;
    }
    for(int i = 1; i < matrix[0].size(); ++i){
        if(matrix[curStart][i] != 0 && visted[i] == false){
            visted[i] = true;
            backtracking(i, end, distance + matrix[curStart][i], ttl - 1, matrix);
            visted[i] = false;
        }
    }
}
int main(){
    int N, start, end, ttl;
    cin >> N >> start >> end >> ttl;
    vector<vector<int>> matrix(N + 1, vector<int>(N + 1, 0));
    visted.resize(N + 1, false);
    visted[start] = true;    
    while(N--){
        int left, right, weight;
        cin >> left >> right >> weight;
        matrix[left][right] = weight;
        matrix[right][left] = weight;
    }
    backtracking(start, end, 0, 255, matrix);
    cout << ansDistance << " " << lastTTL;
}
