//有n个通道，每个通道有对应的传输能力，  有m个包，有包大小和传输时间，   求传输完所有包，所需最短时间。  
//第二行输入 通道能力  三四行分别为包大小和传输所需时间
// 5 2   
// 3 5    
// 1 2 3 4 5 
// 5 3 4 2 3
#include<iostream>
#include<vector>
#include<algorithm>
//此方法存在问题 如
//5 2
//100 100
//7 6 4 3 2
//7 6 4 3 2   最优解应该为11，而不是12

// 5 2
// 5 3
// 1 4 5 2 3
// 1 6 10 3 4
// 输出 16

// 3 2
// 6 13
// 2 11 5
// 3 25 14
// 输出25
using namespace std;

struct cmp{  //struct重载运算符()   函数调用运算符
    bool operator()(vector<int>& a, vector<int>& b) {
        if(a[1] == b[1]) return a[0] < b[0];
        else return a[1] > b[1];
    }
};

void func(vector<vector<int>>& package, vector<vector<int>>& channels, int m, int n){
    sort(package.begin(), package.end(), cmp());  //贪心1. 按传输时长逆序   先处理传输时间长的
    for(auto d : package){
        int minIdleTime = INT_MAX;   //最小闲置时间
        int ch = 0;
        for(int i = 0; i < n; ++i){  // 贪心2. 优先选择最早空闲的通道
            if(channels[i][0] >= d[0]){
                if(channels[i][1] < minIdleTime){
                    ch = i;
                    minIdleTime = channels[i][1];
                }else if(channels[i][1] == minIdleTime && channels[i][0] < channels[ch][0]){
                    ch = i; //贪心3. 如果最早空闲时间也相同，就选取传输能力最小的，将能力大的留给后面的任务。
                }
            }
        }
        channels[ch][1] += d[1];
    }
    int ans = 0;
    for(int i = 0; i < n; ++i){
        ans = max(ans, channels[i][1]);
    }
    cout << ans; 
}

void func1(vector<vector<int>>& package, vector<vector<int>>& channels, int m, int n){
    sort(package.begin(), package.end(), 
    [](vector<int>& a, vector<int>& b){if(a[0] == b[0]) return a[1] > b[1]; return a[0] < b[0];});
    sort(channels.begin(), channels.end(), [](vector<int>& a, vector<int>& b) {return a[0] > b[0];});
    int minChannelsCapacity = channels.back()[0];
    while(!package.empty()){
        int curMinIdleTime = INT_MAX;
        int curChan = 0;
        for(int i = 0; package.back()[0] <= channels[i][0] && i < channels.size(); ++i){
            if(channels[i][1] < curMinIdleTime){
                curMinIdleTime = channels[i][1];
                curChan = i;
            }
        }
        channels[curChan][1] += package.back()[1];
        package.pop_back();
    }
    int ans = 0;
    for(int i = 0; i < channels.size(); ++i){
        ans = max(channels[i][1], ans);
    }
    cout << ans;
}

int main(){
    int m, n;
    cin >> m >> n;
    vector<vector<int>> package(m, vector<int>(2));
    vector<vector<int>> channels(n, vector<int>(2));   //通道能力  空闲时间
    for(int i = 0; i < n; ++i)
        cin >> channels[i][0];
    for(int j = 0; j <= 1; ++j)
        for(int i = 0; i < m; ++i)
            cin >> package[i][j];
    func(package, channels, m, n);
    return 0;

}


//简化问题
//给出一个顾客队列，每个元素为一个顾客，值为结账所需时间。  和收银台个数 N
//计算出所有顾客结账所需时间。  多个收银台对应一个队列，队列最前面的人会选择一个空闲收银台结账
//5,3,4 1  输出12     10,2,3,3 2   输出10    2,3,10 2 输出12
// #include<iostream>
// #include<vector>
// #include<algorithm>
// using namespace std;

// int main(){
//     int a;
//     vector<int> arr;
//     while(true){
//         cin >> a;
//         arr.push_back(a);    
//         if(cin.get() == '\n')
//             break;
//     }
//     int cnt;
//     cin >> cnt;
//     vector<int> cashierDesk(cnt);
//     for(int i = 0; i < arr.size(); ++i){
//         int minIdleTime = INT_MAX;
//         int curSelectCa = 0;
//         for(int i = 0; i < cnt; ++i){
//             if(cashierDesk[i] < minIdleTime){
//                 minIdleTime = cashierDesk[i];
//                 curSelectCa = i;
//             }
//         }
//         cashierDesk[curSelectCa] += arr[i];
//     }
//     cout << *max_element(cashierDesk.begin(), cashierDesk.end());
// }