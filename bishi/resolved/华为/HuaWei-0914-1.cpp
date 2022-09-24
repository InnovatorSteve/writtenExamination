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

#include<iostream>
#include<set>
#include<vector>

using namespace std;

int main(){
    int M, N, K;
    cin >> M >> N >> K;
    set<int> loss;
    for(int i = 0; i < K; ++i){
        int a; cin >> a; loss.insert(a);
    }
    vector<vector<int>> dp(M + 1, vector<int>(N + 1, 0)); //初始化为0， 重要的是生命值为0时  不管几块木板都是0种达到方法。
    for(int i = 1; i <= M; ++i)
        dp[i][0] = 1;
    for(int i = 1; i <= M; ++i){
        for(int j = 1; j <= N; ++j){
            int a, b, c;
            if(loss.find(j) != loss.end()){  //说明当前跳进缺失中， 生命值-1
                // a = j >= 1 ? dp[i - 1][j - 1] : 0;
                a = dp[i - 1][j - 1];
                b = j >= 2 ? dp[i - 1][j - 2] : 0;
                c = j >= 3 ? dp[i - 1][j - 3] : 0;
            }else{
                // a = j >= 1 ? dp[i][j - 1] : 0;
                a = dp[i][j - 1];
                b = j >= 2 ? dp[i][j - 2] : 0;
                c = j >= 3 ? dp[i][j - 3] : 0;
            }
            dp[i][j] = a + b + c;
        }
    }
    int ans = 0;
    for(int j = N; j >= max(0, N - 2); --j)
        ans += dp[M][j];
    cout << ans << endl;
}
//优化版
int main(){
    int M, N, K;
    cin >> M >> N >> K;
    set<int> loss;
    while(K--){
        int temp; cin >> temp;
        loss.insert(temp);
    }
    vector<vector<int>> dp(M + 1, vector<int>(N + 2, 0));
    for(int i = 1; i <= M; ++i)
        dp[i][0] = 1;
    for(int i = 1; i <= M; ++i){
        for(int j = 1; j <= N + 1; ++j){
            if(loss.find(j) != loss.end()){  //缺失
                dp[i][j] = dp[i - 1][j - 1];
                dp[i][j] += j > 1 ? dp[i - 1][j - 2] : 0;
                dp[i][j] += j > 2 ? dp[i - 1][j - 3] : 0;
            }else{
                dp[i][j] = dp[i][j - 1];
                dp[i][j] += j > 1 ? dp[i][j - 2] : 0;
                dp[i][j] += j > 2 ? dp[i][j - 3] : 0;
            }
        }
    }
    cout << dp[M][N + 1] << endl;
}