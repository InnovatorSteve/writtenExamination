#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <set>
#include <algorithm>
#include <numeric>
using namespace std;

struct K1
{
    char a[20];
};
struct K2
{
    char a[12];
};

int main()
{
    K1 *k1 = reinterpret_cast<struct K1 *>(0);   //k1 0x00
    K2 *k2 = reinterpret_cast<struct K2 *>(k1);   //k2 0x00
    k1 += 2;  //0x28
    k2 += 2;  //0x18
    char *p1 = reinterpret_cast<char *>(k1);  
    int *p2 = reinterpret_cast<int *>(k2);
    cout << "p1=" << reinterpret_cast<intptr_t>(p1)     //40
    << ", p2 = " << reinterpret_cast<intptr_t>(p2) << endl;   //24
    return 0;
}