#include<iostream>
#include<vector>

using namespace std;

const int CANNOT_ACCESS = 1e9;

void Dijistra(vector<vector<int>>& MGraph, vector<bool>& vis, vector<int>& distance, vector<int>& pre, int srcNode, int dstNode){
    int nodeNum = MGraph.size();
    for(int i = 0; i < nodeNum; ++i){   //nodeNum次循环，每次找出一个最近下一个节点，并根据最近节点更新distance数组
        int minNode = CANNOT_ACCESS, minDistance = CANNOT_ACCESS;
        for(int j = 0; j < nodeNum; ++j){
            if(!vis[j] && distance[j] < minDistance){
                minDistance = distance[j];
                minNode = j;
            }
        }
        if(minNode == CANNOT_ACCESS) return;   //遍寻未访问过节点，如果不存在可到达节点，那么可联通的节点已经访问完毕，无需再进行循环
        vis[minNode] = true;
        for(int v = 0; v < nodeNum; ++v){
            if(!vis[v] && minDistance + MGraph[minNode][v] < distance[v]){   //以当前节点更新所有关联节点为最短路径
                distance[v] = minDistance + MGraph[minNode][v];
                pre[v] = minNode;
            }
        }
    }
}


void DFSPrint(int srcNode, int dstNode, vector<int>& pre){
    if(dstNode == srcNode){
        cout << dstNode << "->";
        return;
    }
    DFSPrint(srcNode, pre[dstNode], pre);
    cout << dstNode << "->";
}

int main(){
    int nodeNum; //节点数量
    int sideNum; //边数    
    cin >> nodeNum >> sideNum;
    vector<vector<int>> MGraph(nodeNum, vector<int>(nodeNum, CANNOT_ACCESS));
    for(int i = 0; i < sideNum; ++i){  //此处为无向图，有向图单项添加边权值 即可
        int x, y, value;   //两个顶点序号 以及权值
        cin >> x >> y >> value;
        MGraph[x][y] = value;
        MGraph[y][x] = value;
    }
    vector<bool> vis(nodeNum, false);    //是否访问过
    vector<int> distance(nodeNum, CANNOT_ACCESS);    //源节点到其他节点的最短距离
    int srcNode, dstNode;
    cin >> srcNode >> dstNode;
    distance[srcNode] = 0;   //永动机的起始，  指定了源节点为最短，从源节点出去去遍历查询。
    vector<int> pre(nodeNum, CANNOT_ACCESS);
    Dijistra(MGraph, vis, distance, pre, srcNode, dstNode);
    for(auto num : distance)
        cout << num << " ";
    cout << endl;
    DFSPrint(srcNode, dstNode, pre);
    return 0;
}



// #include<iostream>
// #include<vector>

// using namespace std;
// const int CANNOT_ACCESS = 1e9;
// void Dijkstra(vector<vector<int>>& adjacent_matrix, vector<int>& pre, int sourceNode, vector<int>& distance){
//     vector<bool> vis(adjacent_matrix.size(), false);
//     distance[sourceNode] = 0;
//     for(int i = 0; i < adjacent_matrix.size(); ++i)
//         pre[i] = i;
//     for(int i = 0; i < adjacent_matrix.size(); ++i){
//         int minDistance = CANNOT_ACCESS;
//         int minDistanceNode = -1;
//         for(int j = 0; j < adjacent_matrix.size(); ++j){
//             if(!vis[j] && (minDistance > distance[j])){
//                 minDistance = distance[j];
//                 minDistanceNode = j;
//             }  //== 另处理
//         }
//         if(minDistance == CANNOT_ACCESS) return;
//         vis[minDistanceNode] = true;
//         for(int node = 0; node < adjacent_matrix.size(); ++node){
//             if(!vis[node] && (distance[minDistanceNode] + adjacent_matrix[minDistanceNode][node] < distance[node])){
//                 distance[node] = distance[minDistanceNode] + adjacent_matrix[minDistanceNode][node];
//                 pre[node] = minDistanceNode;
//             }
//         }
//     }
// }

// void DFSPrint(int soureNode, int DstNode, vector<int>& pre){
//     if(DstNode == soureNode){
//         cout << soureNode << " ";
//         return;
//     }
//     DFSPrint(soureNode, pre[DstNode], pre);
//     cout << DstNode << " ";   //没有  空
// }

// int main(){
//     // vector<vector<int>> adjacent_matrix = {
//     //     {      0,       1, CANNOT_ACCESS,       4,       4, CANNOT_ACCESS},
//     //     {CANNOT_ACCESS,       0, CANNOT_ACCESS,       2, CANNOT_ACCESS, CANNOT_ACCESS},
//     //     {CANNOT_ACCESS, CANNOT_ACCESS,       0, CANNOT_ACCESS, CANNOT_ACCESS,       1},
//     //     {CANNOT_ACCESS, CANNOT_ACCESS,       2,       0,       3, CANNOT_ACCESS},
//     //     {CANNOT_ACCESS, CANNOT_ACCESS, CANNOT_ACCESS, CANNOT_ACCESS,       0,       3},
//     //     {CANNOT_ACCESS, CANNOT_ACCESS, CANNOT_ACCESS, CANNOT_ACCESS, CANNOT_ACCESS,       0}
//     // };
// //      the shortest path :0
// //  the shortest path :1
// //  the shortest path :5
// //  the shortest path :3
// //  the shortest path :4
// //  the shortest path :6
// // 0 1 3 2 cost = 5
//     vector<vector<int>> adjacent_matrix = {
//         {            0,             2,             6, CANNOT_ACCESS, CANNOT_ACCESS, CANNOT_ACCESS, CANNOT_ACCESS},
//         {            2,             0, CANNOT_ACCESS,             5, CANNOT_ACCESS, CANNOT_ACCESS, CANNOT_ACCESS},
//         {            6, CANNOT_ACCESS, CANNOT_ACCESS,             8, CANNOT_ACCESS, CANNOT_ACCESS, CANNOT_ACCESS},
//         {CANNOT_ACCESS,            5,            8,               0,            10,            15, CANNOT_ACCESS},
//         {CANNOT_ACCESS, CANNOT_ACCESS, CANNOT_ACCESS,            10,             0,             6,             2},
//         {CANNOT_ACCESS, CANNOT_ACCESS, CANNOT_ACCESS,            15,             6,             0,             6},
//         {CANNOT_ACCESS, CANNOT_ACCESS, CANNOT_ACCESS, CANNOT_ACCESS,             2,             6,             0}
//     };
//     vector<int> pre(adjacent_matrix.size(), -1);
//     vector<int> distance(adjacent_matrix.size(), CANNOT_ACCESS);
//     Dijkstra(adjacent_matrix, pre, 0, distance);
//     for(int i = 0; i < distance.size(); ++i){
//         cout << " the shortest path :" << distance[i] << endl;
//     }
//     DFSPrint(0, 2, pre);
//     cout << "cost = " << distance[2] << endl;
//     return 0;

// }