#include<iostream>
#include<condition_variable>
#include<mutex>
#include<thread>
#include<vector>
#include<ctime>
using namespace std;
#define threadsNum 3
//信号量 顺序执行
//c++11 没有信号量 c++20有
class semaphore{
public:
    semaphore() : count(0), wakeups(0) {}
    semaphore(int _count) : count(_count), wakeups(0) {}
    void wait(){
        unique_lock<mutex> lock(mtx);
        // if(--count < 0){ //等同于count < 1 即没有可用线程，那么就条件变量等待，直至可用。
        //     cond.wait(lock, [&]()->bool{return wakeups > 0;});
        //     --wakeups;
        // }
        if(count <= 0)
            cond.wait(lock, [&]()->bool{return count > 0;});
        --count;
    }
    void signal(){
        lock_guard<mutex> lock(mtx);
        // if(++count <= 0){
        //     ++wakeups;  //代表阻塞被释放的线程  没有可用进程时 执行P操作就会进入此条件
        //     cond.notify_one();  //V操作后 有新的可用资源，便进行通知
        // }
        if(++count <= 1) //说明生产前没有资源可用，通知在条件阻塞的线程
            cond.notify_one();   //经过测试 是否添加辅助变量wakeups不影响效率
    }

private:
    int count;
    int wakeups;
    mutex mtx;
    condition_variable cond;
};

vector<semaphore> semaphores(3);
int num = 1;
void callback(int id){
    if(num == 1 && id == 0) semaphores[id].signal();
    while(num <= 1000){
        semaphores[id].wait();
        if(num <= 1000){
            cout << static_cast<char>('A' + id) << num++ << endl;
        }
        semaphores[(id + 1) % 3].signal();  //放在外边是为了唤醒所有下一线程，避免无法结束
    }
}

int main(){
    clock_t start_time = clock();
    vector<thread> threads(threadsNum);   
    for(int i = 0; i < threadsNum; ++i)
        threads[i] = thread(callback, i);
    for(int i = 0; i < threadsNum; ++i)
        threads[i].join();
    clock_t end_time = clock();
    cout << "执行完毕" << (double)(end_time - start_time) / CLOCKS_PER_SEC << endl;


}