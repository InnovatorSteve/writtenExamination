#include<iostream>
#include<string.h>
using namespace std;
class String{
public:
    String(const char *str = nullptr);
    String(const String& other);
    ~String();
    String &operator=(const String& other);
    void print() {cout << m_data << endl;}
private:
    char *m_data;
};
//构造函数
String::String(const char *str){
    cout << 1 << endl;
    if(str == nullptr){
        m_data = new char[1];
        *m_data = '\0';
    }else{
        int length = strlen(str);
        m_data = new char[length + 1];
        strcpy(m_data, str);
    }
}
String::~String(void){
    cout << 4 << endl;

    delete[] m_data;
}
//拷贝构造函数
String::String(const String& other){
    cout << 2 << endl;

    int length = strlen(other.m_data);
    m_data = new char[length + 1];
    strcpy(m_data, other.m_data);
}
//复制构造
String& String::operator=(const String& other){
    cout << 3 << endl;

    if(this == &other)
        return *this;
    delete[] m_data;
    int length = strlen(other.m_data);
    m_data = new char[length + 1];
    strcpy(m_data, other.m_data);
    return *this; 
}

int main(){
    String s1("qwe");
    s1.print();
    String s2(s1);
    s2.print();
    String s3 = s2; //等同于  String s3(s2);
    s3 = s1;
    s3.print();
    return 0;
}