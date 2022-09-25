#include<iostream>
#include<string>
#include<sstream>
#include<bitset>
#include<iomanip>  //控制精度
using namespace std;

int main(){
    int n = 78;
    cout << "8进制: " << oct << n << endl; //等同于oct(cout)  还支持dec hex
    cout << bitset<8>(n) << endl;  //八位二进制
    
    cout.width(5); //输出宽度 仅影响一个cout
    cout.setf(ios_base::showpoint);  //显示小数点 以及小数末尾的0
    //setf可以设置的格式常量如下：
            // ios_base ::boolalpha 输入和输出bool值，可以为true或false
            // ios_base ::showbase 对于输出，使用C++基数前缀(0，0x)
            // ios_base ::showpoint 显示末尾的小数点
            // ios_base ::uppercase 对于16进制输出，使用大写字母，E表示法
            // ios_base ::showpos  在正数前面加上+
cout.unsetf(ios::adjustfield | ios::basefield | ios::floatfield); //恢复默认设置

    //保留两位小数到变量中
    double x = 2.0/3.0;
    cout << fixed << setprecision(2) << x << endl; //fixed表示浮点输出带有小数点 与setprecision合用将指定浮点数字的小数点后要显示的位数，
    //而不是要显示的总有效数位数。而这通常正是我们想要的。

    stringstream ss;
    ss << fixed << setprecision(2) << x ;
    ss >> x;
    cout << "stringstream保存到变量中：" << x << endl;

    //字符串进制转换
    char str2R[] = "101010test123 1";
    char* ptr; // 数值后的下一个字符
    long ret = strtol(str2R, &ptr, 2);
    printf("strtol 二进制转10进制：%ld\t, 剩余字符串：%s\n", ret, ptr);
    // cout << "strtol 二进制转10进制：" << ret << " 剩余字符串：" << ptr << endl;

    //十进制转其他进制
    itoa(ret, str2R, 8);
    printf("十进制转八进制：%s", str2R);
    //字符数组转string
    string s1(str2R);
    s1 = s1 + str2R; //+ 两侧不能都是字符数组
    //string 转字符数组 str1.c_str();

//     #include<cstdio>  
// 	sprintf(s, "%8o", 123);	//八进制输出，宽度占8个位置   x十六进制 b 二进制
// 	sprintf(s, "%10.3f", 3.1415626); //产生：" 3.142"
// 	int i = 100;
// 	sprintf(s, "%.2f", i);	//注意这是不对的
// 	sprintf(s, "%.2f", (double)i);	//要按照这种方式才行


    return 0;
}