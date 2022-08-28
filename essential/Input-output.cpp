#include<iostream>
#include<string>
#include<sstream>
#include<bitset>
#include<iomanip>  //控制精度
using namespace std;

int main(){
    int n = 78;
    cout << "8进制: " << oct << n << endl;
    cout << "10进制 " << dec << n << endl;
    cout << "16进制 " << hex << n << endl;
    cout << bitset<8>(35) << endl;  //八位二进制

    //保留两位小数到变量中
    double x = 2.0/3.0;
    double x1 = 0.345;  // 0.34  需注意
    cout << fixed << setprecision(2) << x1 << endl;
    x = (x * 100 + 0.5) / 100;
    printf(".3%lf\n", x);

    stringstream ss;
    ss << fixed << setprecision(2) << x ;
    ss >> x1;
    cout << "stringstream保存到变量中：" << x1 << endl;

    //进制转换
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

    //sprintf
//     #include<cstdio>  
// int main()  
// {  
// 	char s[100]={0};
// 	sprintf(s, "%d", 123); //十进制输出产生"123"
// 	sprintf(s, "%4d%4d", 123, 4567); //指定宽度不足的左边补空格，产生：" 1234567"
// 	sprintf(s, "%8o", 123);	//八进制输出，宽度占8个位置
// 	sprintf(s, "%8x", 4567); //小写16 进制，宽度占8 个位置，右对齐
// 	sprintf(s, "%10.3f", 3.1415626); //产生：" 3.142"
// 	int i = 100;
// 	sprintf(s, "%.2f", i);	//注意这是不对的
// 	sprintf(s, "%.2f", (double)i);	//要按照这种方式才行
// 	return 0;  
// }  


    // std::string input = "41 3.14 false hello world";
    // std::istringstream stream(input);
 
    // int n;
    // double f;
    // bool b;
 
    // stream >> n >> f >> std::boolalpha >> b;
    // std::cout << "n = " << n << '\n'
    //           << "f = " << f << '\n'
    //           << "b = " << std::boolalpha << b << '\n';  //boolalpha让输出流将bool解析成为true或者 false。   noboolalpha 恢复为0 1 int
 
    // // 用 streambuf 重载提取剩余内容
    // stream >> std::cout.rdbuf();
    // std::cout << '\n';
    /*n = 41
    f = 3.14
    b = false
    hello world*/
    return 0;
}