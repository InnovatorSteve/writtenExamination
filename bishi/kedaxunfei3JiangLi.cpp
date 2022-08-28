

// /* 方形迷宫，二位数组来表示，其中0代表可以走的路，1为不可同行，8为奖品。迷宫有一到多个入口，求入口到奖励最短路径。
#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<queue>
using namespace std;
struct Point
{
    int x, y;
    Point(int _x, int _y) : x(_x), y(_y) {}
    Point(const Point& point) : x(point.x), y(point.y) {}
};
struct isEqual{  //仿函数  非重载
    bool operator()(const Point& a, const Point& b) const{
        return a.x == b.x && a.y == b.y;
    }
};
struct hashPoint{   //
    size_t operator()(const Point& a) const{
        return hash<int>()(a.x) ^ hash<int>()(a.y);
    }
};

void calTargetPoint(vector<vector<int>>& map, Point& targetPoint){
    for(int i = 0; i < map.size(); ++i){
        for(int j = 0; j < map[i].size(); ++j){
            if(map[i][j] == 8){
                targetPoint.x = i;
                targetPoint.y = j;
                return;
            }
        }
    }
}
vector<vector<int>> dir = {{1, 0}, {-1, 0}, {0, - 1}, {0, 1}};
vector<Point> winMapGift(vector<vector<int>>& map){
    unordered_map<Point, Point, hashPoint, isEqual> father;   //记录路径中当前点的上一点
    Point targetPoint(0, 0);
    queue<Point> curLayerPoint;
    unordered_set<Point, hashPoint,isEqual> visted;
    calTargetPoint(map, targetPoint);
    curLayerPoint.push(targetPoint);
    visted.insert(targetPoint);
    bool flag = true;
    vector<Point> ans;
    while(flag && !curLayerPoint.empty()){
        int n = curLayerPoint.size();
        for(int i = 0; i < n; ++i){
            Point curPoint = curLayerPoint.front();
            curLayerPoint.pop();
            if(0 == curPoint.x || map.size() - 1 == curPoint.x || 0 == curPoint.y || map[0].size() - 1 == curPoint.y){
                targetPoint.x = curPoint.x;
                targetPoint.y = curPoint.y;
                flag = false;
                break;
            }
            for(auto it : dir){
                Point nextPoint(curPoint);
                nextPoint.x += it[0];
                nextPoint.y += it[1];
                if(nextPoint.x < 0 || nextPoint.x >= map.size() || nextPoint.y < 0 || nextPoint.y >= map[0].size()){
                    targetPoint.x = curPoint.x;
                    targetPoint.y = curPoint.y;
                    flag = false;
                    break;
                }else if(nextPoint.x >= 0 && nextPoint.x < map.size() && nextPoint.y >= 0 && nextPoint.y < map[0].size() 
                        && map[nextPoint.x][nextPoint.y] == 0 && visted.find(nextPoint) == visted.end() ){
                    father.insert({nextPoint, curPoint});
                    visted.insert(nextPoint);
                    curLayerPoint.push(nextPoint);
                }
            }
        }

    }
    while(1 && !father.empty()){
        ans.emplace_back(targetPoint);
        if(map[targetPoint.x][targetPoint.y] == 8) break;
        targetPoint = father.find(targetPoint)->second;
    }
    return ans;
}


int main(){
    vector<vector<int>> map = {
        {0, 1, 1, 1}, {0, 0, 0, 1}, {1, 0, 8, 1}, {1, 0, 1, 1}
    };
    auto ans = move(winMapGift(map));
    for(auto it : ans){
        cout << it.x << " " << it.y << endl;
    }
    return 0;
    
}


// */
// #include<iostream>
// #include<vector>
// #include<deque>
// #include<set>
// #include<unordered_set>
// #include<unordered_map>
// using namespace std;

//  struct Point {
//  	int x;
//  	int y;
//  	Point(int xx, int yy) : x(xx), y(yy) {}
//     // bool operator==(const Point& a) { 
//     //     if (x == a.x && y == a.y) { 
//     //         return true; 
//     //     } 
//     //     return false; 
//     // }
//  };

// struct createhash{   //自定义数据类型的哈希函数
//     size_t operator()(const Point& a) const{
//         return hash<int>()(a.x) ^ hash<int>()(a.y);
//     }
//  };
 
//  struct isEqual{   //自定义数据类型 判断是否找到key的函数
//     bool operator()(const Point& a, const Point& b) const{ 
//         if (b.x == a.x && b.y == a.y) 
//             return true; 
//         else
//             return false;    
//     }
//  };

// class Solution {
// public:
//     vector<pair<int, int>> dis = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};  //遍历方向
//     vector<Point> winMazeGift(vector<vector<int> >& maze) {
//         int m = maze.size(), n = maze[0].size(); 
//         vector<Point> ans;
//         Point targetPoint(0, 0);    //目标点坐标
//         for(int i = 0; i < m; ++i){    //找到目标点坐标
//             for(int j = 0; j < n; ++j){
//                 if(maze[i][j] == 8){
//                     targetPoint.x = i;
//                     targetPoint.y = j;
//                 }
//             }
//         }
//         unordered_map<Point, Point, createhash, isEqual> father;  //建立路径对应关系
//         deque<Point> que;   //通过队列 先入先出   每次队列保存一层遍历  层序遍历  每加一层就是经历路径加一
//         que.push_back(targetPoint);  //从目标点开始层序遍历
//         bool flag = true;      //是否找到最短路径  
//         Point pathTarget(0, 0);    //最短路径 起始点
//         set<Point, isEqual> visted = {targetPoint};  //是否访问过
//         // unordered_set<Point, createhash, isEqual> visted = {targetPoint};
//         while(flag && !que.empty()){ //遍历到边界   或者没有出口
//             for(int i = 0; i < que.size(); ++i){  //当前层遍历
//                 Point curPoint = que.front();   
//                 que.pop_front();
//                 if(curPoint.x == 0 || curPoint.x == m - 1 || curPoint.y == 0 || curPoint.y == n - 1){  
//                     //到达边界，最先到达的极为最短路径 同时先判断是都在边界，包含了目标点一开始就在边界的情况。
//                     pathTarget.x = curPoint.x;
//                     pathTarget.y = curPoint.y;
//                     flag = false;
//                     break;
//                 }
//                 for(auto it : dis){
//                     Point nextPoint(0, 0);
//                     nextPoint.x = curPoint.x + it.first;
//                     nextPoint.y = curPoint.y + it.second;
//                     if(0 <= nextPoint.x && nextPoint.x < m && 0 <= nextPoint.y && nextPoint.y < n 
//                     && maze[nextPoint.x][nextPoint.y] == 0 && visted.find(nextPoint) != visted.end()){
//                         // father[nextPoint] = curPoint;  //自定义数据无法使用   需要重载
//                         father.insert({nextPoint, curPoint});
//                         que.push_back(nextPoint);
//                         visted.insert(nextPoint);
//                     }
//                 }
//             }
//         }
//         while(1){
//             ans.push_back(pathTarget);
//             if(maze[pathTarget.x][pathTarget.y] == 8)
//                 break;
//             auto it = father.find(pathTarget);
//             pathTarget = it->second;
//         }
//         return ans;
//     }
// };

// int main(){
//     Solution s;
//     vector<vector<int>> map = {
//         {0,1,1,1}, {0,0,0,1}, {1,0,8,1}, {1,0,1,1}
//     };
//     auto ans = s.winMazeGift(map);
//     for(auto it : ans){
//         cout << it.x << " " << it.y << endl;
//     }
//     //{{3, 1}, {2, 1}, {2, 2}};
// }

