#include<iostream>
#include<queue>
#include<thread>
#include<condition_variable>//条件变量
#include<mutex>

using namespace std;
mutex mtx;  
condition_variable cond;//条件变量要搭配互斥量使用
queue<int> que;//生产消费队列

void producerCallBack(){
    int data = 1;
    while(1){
        data = rand();
        unique_lock<mutex> locker(mtx); //unique_lock 是通用互斥包装器，允许延迟锁定、锁定的有时限尝试、递归锁定、所有权转移和与条件变量一同使用
        que.push(data);
        cout << "存入" << data << endl;
        cond.notify_one();
        this_thread::sleep_for(chrono::milliseconds(100));
    }
}

void consumerCallBack(){
    while(1){
        unique_lock<mutex> lock(mtx);
        while(que.empty())
            cond.wait(lock);
        cout << "取出" << que.back() << endl;
        que.pop();
        this_thread::sleep_for(chrono::milliseconds(100));
    }
}

int main(){
    thread producer(producerCallBack);
    thread consumer(consumerCallBack);
    producer.join();
    consumer.join();
    cout << "生产者-消费者模型执行完毕！" << endl;
    return 0;
}


