#include<iostream>
#include<thread>
#include<vector>
#include<mutex>
#include<condition_variable>
#define threadNum 3
using namespace std;
mutex mtx;
condition_variable cond;
int num = 3;

void callBack(int id){//通过if判断过滤
    while(num < 100){
        unique_lock<mutex> lock(mtx);
        cond.wait(lock, [id]{return num % threadNum == id;});
        cout << static_cast<char>('A' + id % 3) << "打印了" << num++ << endl;
        cond.notify_all();
    }
}  


int main(){
    vector<thread> threadvec;
    for(int i = 0; i < threadNum; ++i){
        threadvec.emplace_back(thread(callBack, i));
    }

    for(int i  = 0; i < threadNum; ++i)
        threadvec[i].join();
    cout << "结束" << endl;
    
}