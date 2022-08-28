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