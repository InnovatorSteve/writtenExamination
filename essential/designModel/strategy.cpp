#include<iostream>
using namespace std;

class ReplaceAlogorithm{
public:
    virtual void replace() = 0;
};

class LRU_ReplaceAlgorithm : public ReplaceAlogorithm{
public:
    void replace() {cout << "Least Recently Used replace algorithm" << endl;}
};
class FIFO_ReplaceAlgorithm : public ReplaceAlogorithm{
public:
    void replace() {cout << "First in First out replace algorithm" << endl;}
};
class Random_ReplaceAlgorithm : public ReplaceAlogorithm{
public:
    void replace() {cout << "Random replace algorithm" << endl;}
};
//方法一
// class Cache{
// public:
//     Cache(ReplaceAlogorithm* ra) : m_ra(ra) {}
//     ~Cache() {delete m_ra; m_ra = nullptr;}
//     void replace() {m_ra->replace();}
// private:
//     ReplaceAlogorithm* m_ra;
// };

//方法二
// enum RA{LRU, FIFO, RANDOM};
// class Cache{
// private:
//     ReplaceAlogorithm* m_ra;
// public:
//     Cache(enum RA ra){
//         if(ra == LRU)
//             m_ra = new LRU_ReplaceAlgorithm();
//         else if(ra == FIFO)
//             m_ra = new FIFO_ReplaceAlgorithm();
//         else if(ra == RANDOM){
//             m_ra = new Random_ReplaceAlgorithm();
//         }
//     }
//     ~Cache() {delete m_ra; m_ra = nullptr;}
//     void replace() {m_ra->replace();}
// };

//方法三
template <typename RA>
class Cache{
private:
    RA m_ra;
public:
    Cache(){}
    ~Cache(){}
    void replace() { m_ra.replace();}

};
int main(){
    //方法一
    // Cache cache = new LRU_ReplaceAlgorithm();//暴露了算法的定义
    // cache.replace();
    //方法二
    // Cache cache(FIFO); //指定标签即可  工厂模式与策略模式相结合
    // cache.replace();
    Cache<Random_ReplaceAlgorithm> cache; //暴露了定义 
    cache.replace();
    return 0;

}