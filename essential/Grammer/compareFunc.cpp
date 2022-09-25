#include<iostream>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<algorithm>
#include<functional>

using namespace std;

class Node{
private:
    int _x, _y;
public:
    Node(int x, int y) : _x(x), _y(y) {}
    //1.重载 < 运算符 (写在类内)  第一个const，即const Node a表示的是node_a必须为const；
    //第二个const，即函数声明之后的那个const，表示的是运算符<可以被const类型的node_b调用
    // bool operator<(const Node& a)const {
    //     if(_x == a._x) return _y > a._y;
    //     return _x > a._x;
    // }

    //2. 重写仿函数  (写在类内)  
    // bool operator()(Node&a, Node& b)const {
    //     if(a._x == b._x) return a._y > b._y;
    //     return a._x > b._x;
    // }
    int get_x() {return _x;}
    int get_y() {return _y;}
    void print()const {cout << _x << " " << _y << endl;}
};
// 1.重载 < 运算符 (写在类外)
bool operator<(Node& a, Node& b){
    if(a.get_x() == b.get_x()) return a.get_y() > b.get_y();
    return a.get_x() > b.get_x();
}
//2.重写仿函数  (写在类外)
struct cmp{
    bool operator()(Node&a, Node& b){
        if(a.get_x() == b.get_x()) return a.get_y() > b.get_y();
        return a.get_x() > b.get_x();
    }
};
//3.函数指针
bool cmp1(Node& a, Node& b){
    if(a.get_x() == b.get_x()) return a.get_y() > b.get_y();
    return a.get_x() > b.get_x();
}
//4.lambda表达式
auto cmp2 = [](Node& a, Node& b){ if(a.get_x() == b.get_x()) return a.get_y() > b.get_y(); return a.get_x() > b.get_x(); };

int main(){
    // vector<Node> vec{Node(10, 20), Node(20, 10), Node(10, 10)};
    // bool (*func) (Node& a, Node& b);
    // func = cmp1;
    // int mode = 6;
    // switch (mode)
    // {
    // case 1: sort(vec.begin(), vec.end()); break;  //1.重载 < 运算符 (写在类内)
    // case 2: sort(vec.begin(), vec.end()); break;  //1.重载 < 运算符 (写在类外)
    // // case 3: sort(vec.begin(), vec.end(), Node(Node&, Node&)); break;  //2. 重写仿函数  (写在类内)  暂不可行
    // case 4: sort(vec.begin(), vec.end(), cmp()); break;  //2. 重写仿函数  (写在类外)
    // case 5: sort(vec.begin(), vec.end(), cmp1); break;  //3.函数指针  也可以用func
    // case 6: sort(vec.begin(), vec.end(), cmp2); break;  //4.lambda表达式
    // }
    // for(auto node : vec)  cout << node.get_x() << " " << node.get_y() << endl;


    //容器比较函数有些变动
    // priority_queue<Node> q;  //1.重载 < 运算符  (类内类外)
    // priority_queue<Node, vector<Node>, Node> q;  //2.重写仿函数  类内  暂不可行
    // priority_queue<Node, vector<Node>, function<bool (Node& a, Node& b)>> q(cmp1);  //3.函数指针   a > b  小根堆
    //lambda表达式（需要把lambda表达式作为优先队列参数进行初始化，并且指定priority_queue的模板实参：decltype(cmp2)）
    priority_queue<Node, vector<Node>, decltype(cmp2)> q(cmp2);
    q.push(Node(10, 20));
    q.push(Node(20, 10));
    q.push(Node(10, 10));
    while(!q.empty()){
        q.top().print();
        q.pop();
    }

    // priority_queue<Node, vector<Node>, decltype(cmp2)> q(cmp2);
    return 0;
}                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                               