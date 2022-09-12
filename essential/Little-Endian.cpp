#include<iostream>
using namespace std;

union uniA{
    int a;
    short b;
};
int main(){
    union uniA A;
    A.a = 0x1234;
    if(A.b == 0x12){
        cout << "大端";
    }else{
        cout << "小端";
    }
}