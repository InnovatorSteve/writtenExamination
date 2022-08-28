/*小红想构造一个总共n个节点完全二叉树， 该二叉树满足以下两个性质
    1. 所有节点的权值值为1~n的一个排列。
    2. 除了根节点以外,每个节点的权值和它父亲的权值的乘积为偶数。 
    请你帮小红构造出这个二叉树,并按层序遍历的方式打印所有节点。 
    输入描述：
    一个正整数n，代表二叉树的节点数量，2≤n≤10^5
    输出描述：
    输出一行n个正整数,代表小红构造的二叉树的层序遍历的序列。*/

#include<iostream>

using namespace std;

int main(){
    int n;
    cin >> n;
    int oddNumber, evenNumber;
    evenNumber = oddNumber = n / 2;
    if(n % 2)
        oddNumber++;
    for(int i = 1; i <= evenNumber; ++i)
        cout << i * 2 << " ";
    for(int i = 1; i <= oddNumber; ++i)
        cout << i * 2 - 1 << " ";
}

// 4
// 2 4 1 3