#include<iostream>
#include<string>
#include<string.h>
#include<sstream>
using namespace std;

void stringToInt(){
    //1. int atoi(const char* nptr)  atoi函数扫描nptr函数，跳过开始的空白符(可通过 isspace()检测)，
    //直到遇到数字或者±符号时才会开始转到，直至非数字或者'\0'  转换失败返回0
    //C++中若需要将string类型转为int类型，需先将string转为const char*。
    // char* c; 
    // string s="1234"; 
    // c = s.c_str(); //c最后指向的内容是垃圾，因为s对象被析构，其内容被处理，同时，编译器也将报错——将一个const char *赋与一个char *。
    char c[20]; 
    string s="1234"; 
    strcpy(c, s.c_str()); 

    //2. 使用stringstream  需要包含sstream
    stringstream ss;
    int n;
    ss << " 1234.ab";
    ss >> n;
    cout << n;
    ss.clear();

    //3. stoi stol stoll
    // int stoi(const std::string& str, std::size_t* pos, int base = 10);
    //str 要转换的字符串   pos 首个未转换字符的地址    base 数的底
    
}

void intToString(){
    stringstream ss;
    int n = 1234;
    ss << n;
    string s;
    ss >> s;

    string strInt = to_string(n);  //注意的浮点类型可能产生非预期效果

    char str;
    sprintf(&str, "%d", n);


}

int main(){

}