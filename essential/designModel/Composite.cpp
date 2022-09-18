#include<iostream>
#include<string>
#include<list>
using namespace std;

class Company{
public:
    Company(string name) : m_name(name) {}
    ~Company() {}
    virtual void add(Company* pCom) {}
    virtual void show(int depth) {}
protected:
    string m_name;
};

class ConcerteCompany: public Company{
public:
    ConcerteCompany(string name) : Company(name) {}
    virtual ~ConcerteCompany() {}
    void add(Company* pcom){ m_listCompany.emplace_back(pcom); }
    void show(int depth){
        for(int i = 0; i > depth; ++i)
            cout << "-";
        cout << m_name << endl;
        for(auto& it : m_listCompany) it->show(depth + 2);
    }
private:
    list<Company*> m_listCompany;
};

class FinanceDepartment : public Company{
public:
    FinanceDepartment(string name): Company(name) {}
    ~FinanceDepartment() {}
    void show(int depth){
        for(int i = 0; i < depth; ++i)
            cout << "-";
        cout << m_name << endl;
    }
};

class HRDepartment : public Company{
public:
    HRDepartment(string name) : Company(name) {}
    ~HRDepartment(){}
    void show(int depth){
        for(int i = 0; i < depth; ++i)
            cout << "-";
        cout << m_name << endl;
    }
};
int main(){
    Company* root = new ConcerteCompany("总公司");
    Company* left1 = new FinanceDepartment("财务部");
    Company* right2 = new HRDepartment("人力资源部");
    root->add(left1);
    root->add(right2);

    Company* mid1 = new ConcerteCompany("分公司A");
    Company* left3 = new FinanceDepartment("财务部");
    Company* right4 = new HRDepartment("人力资源部");
    mid1->add(left3);
    mid1->add(right4);
    root->add(mid1);

    Company* mid2 = new ConcerteCompany("分公司B");
    Company* left5 = new FinanceDepartment("财务部");
    Company* right6 = new HRDepartment("人力资源部");
    mid2->add(left5);
    mid2->add(right6);
    root->add(mid2);

    root->show(0);

    delete left1, left3, left5, right2, right4, right6;
    delete root, mid1, mid2;
    return 0;
}