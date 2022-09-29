#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <set>
#include <algorithm>
#include <numeric>
#pragma pack(1)
struct S1{
 int x;
 char y;
};
struct S2{
 int x;
 int y;
};
using namespace std;

// struct K1
// {
//     char a[20];
// };
// struct K2
// {
//     char a[12];
// };

int main()
{
    // using namespace std;
    // K1 *k1 = reinterpret_cast<struct K1 *>(0);
    // K2 *k2 = reinterpret_cast<struct K2 *>(k1);
    // k1 += 2;
    // k2 += 2;
    // char *p1 = reinterpret_cast<char *>(k1);
    // int *p2 = reinterpret_cast<int *>(k2);
    // cout << "p1=" << reinterpret_cast<intptr_t>(p1) 
    // << ", p2 = " << reinterpret_cast<intptr_t>(p2) << endl;
    cout << sizeof(S1) - sizeof(S2);
    return 0;
}