#include<iostream>
#include<thread>
#include<mutex>
#include<vector>
// #include<windows.h>//引入休眠函数
#define winNum 10
using namespace std;
mutex m;//实例化互斥量 m
int num = 100;

void callback(int a){
    while(num > 0){
        lock_guard<mutex> lg(m);// m.lock();   出了作用域自动解锁 避免死锁  或者在进程中出现异常 导致不能执行到unlock的情况
        if(num > 0){
            cout << a << "在卖第" << num-- << "张票。\n";
        }
        // Sleep(10);  //windows.h  搭配使用，下边这个可以跨平台
        this_thread::sleep_for(chrono::milliseconds(100));  //休眠100毫秒
        // m.unlock();
    }
}

int main(){
    // thread *threadNums = new thread[winNum];
    vector<thread> vecThread(winNum);
    for(int i = 0; i < winNum; ++i){
        vecThread[i] = thread(callback, i);//从第二个参数开始是传入回调函数参数 如果有多个 依次写上
    }
    for(int i = 0; i < winNum; ++i)
        vecThread[i].join();
    cout << "票卖完了" << endl;
    return 0;
}

//c 版多线程卖票
// #include<pthread.h>
// #include<unistd.h>
// #include<iostream>
// #include<mutex>

// using namespace std;
// pthread_mutex_t mtx;
// int num = 100;

// void *callback(void* arg){
//     int curId= (int)(*(int*)arg);//首先转换指针类型 然后* 取值 再转换类型  最外层(int)可不要
//     while(num > 0){//循环 才会一直卖
//         // cout << curId << endl;
//         pthread_mutex_lock(&mtx);
//         if(num > 0){//因为num-- 非原子操作，从while循环到 加锁 可能已经被修改了 变成了-1等 所以加锁后再次判断
//             cout << curId << "正在卖第：" << num-- << "张票" << endl;
//         }
//         pthread_mutex_unlock(&mtx);
//         usleep(100);//休眠一会儿才让其他线程有机会拿到锁 否则票大部分被一个窗口卖完。
//     }
//     return NULL;
// }


// int main(){
//     pthread_mutex_init(&mtx, NULL); //第二个参数设置互斥量参数 一般为NULL
//     pthread_t* threadNums = new pthread_t[10];
//     for(int i = 0; i < 10; ++i){
//         pthread_create(threadNums + i, NULL, callback, &i);
//     } 
//     for(int i = 0; i < 10; ++i){
//         int *thread_retval;//保存目标线程退出状态
//         int ret = pthread_join(*(threadNums + i), (void **)&thread_retval); //ret保存 回收线程资源 是否成功
//     }//join状态 分开设置 否则会等待第一个窗口把全部票卖完 其他窗口无票可卖
//     cout << "票卖完了！" << endl;
//     return 0;
// }