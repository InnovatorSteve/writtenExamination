#include<iostream>
#include<list>
#include<string>
using namespace std;
//观察者 抽象
class Observe{
public:
    Observe(){}
    virtual ~Observe(){}
    virtual void Update(){}  //提供一个更新的接口  供被观察者调用
};
//博客 抽象被观察者
class Blog{
public:
    Blog(){}
    virtual ~Blog(){}
    void attach(Observe* observer) {m_oberves.emplace_back(observer);}
    void detach(Observe* observer) {m_oberves.remove(observer);}
    void notify(){
        for(auto& it : m_oberves) it->Update(); 
    }
    virtual void SetStatus(string s) {m_status = s;}
    virtual string GetStatus() {return m_status;}
private:
    list<Observe*> m_oberves; //观察者链表    双向链表
protected:  //可以被子类访问 但是不能被子类对象访问
    string m_status; //状态
};
//具体博客类
class MyBlog : public Blog{
private:
    string m_name;
public:
    MyBlog(string name) : m_name(name){}
    ~MyBlog() {}
    void SetStatus(string s) {m_status = "notify : " + m_name + s;}
    string GetStaus() {return m_status;}
};
//具体观察者
class ObserverBlog : public Observe{
private:
    string m_name; //观察者名称
    Blog *m_blog;  //观察的博客, 链表可以观察多个博客
public:
    ObserverBlog(string name, Blog* blog) : m_name(name), m_blog(blog) {}
    ~ObserverBlog(){}
    void Update(){
        string status = m_blog->GetStatus();
        cout << m_name << "--- Receve" << status << endl; 
    }
};
int main(){
    Blog *blog = new MyBlog("weifengchao");
    Observe *Observe1 = new ObserverBlog("zhangsan", blog);
    Observe *Observe2 = new ObserverBlog("LiSi", blog);
    blog->attach(Observe1);
    blog->attach(Observe2);
    blog->SetStatus("Published C++(15)---Observe");
    blog->notify();
    delete blog, Observe1, Observe2;
    return 0;
}