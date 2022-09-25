#include<iostream>
#include<assert.h>
using namespace std;

class X{}; //sizeof(X):1                 32位  64位
class Y : public virtual X {}; //sizeof(Y):4  8
class Z : public virtual X {}; //sizeof(Z):4  8
class A : public virtual Y {}; //sizeof(A):8  8 
class B : public Y, public Z{}; //sizeof(B):8  16
class C : public virtual Y, public virtual Z {}; //sizeof(C):12  16
class D : public virtual C{}; //sizeof(D):16   16
class E{
public:
    int x;  //4字节
    virtual void fun(){} //虚表指针64位下 8字节 字节对齐一共16字节
};
class F : public virtual E{   //sizeof(F)  32位字节
    int y;
    virtual void fun() {}   
};
class G : public virtual F{
int m;
virtual void funG() {}   //48
};
//虚基类指针：如果是虚继承，则子类的大小为：
//虚基类的大小 + 4个字节(用来存放指向虚基对象的指针）+子类新增成员的大小。
//test
void test01(){
    char str[] = "hello";
    char* p = str;
    int n = 10;

    cout << sizeof(str) << endl;
    cout << sizeof(p) << endl;
    cout << sizeof(n) << endl; 
}
void test02(char str[100]){
   cout<< sizeof(str) << endl;   //8 传地址
}
void test03(){
    void *p = malloc(100);
    cout << sizeof(p) << endl;
    free(p);
}
//实现内存拷贝函数
char* strcpy(char* strDest, const char* strSrc){
    assert(strDest != nullptr && strSrc != nullptr);
    char *ret = strDest;
    while((*strDest++ = *strSrc++) != '\0');
    return ret;
}
int main(){
    //class C c;
    // cout << sizeof(G) << endl;
    // char str[100] = {0};
    // cout<< sizeof(str) << endl; //100
    //test03();
    char* src = "qwert";
    char *dest = (char*)malloc(sizeof(src));
    strcpy(dest, src);
    cout << dest << sizeof(dest) << endl;
    return 0;
}