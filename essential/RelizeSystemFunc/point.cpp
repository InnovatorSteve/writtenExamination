#include<iostream>
#include<stdio.h>
using namespace std;
void fun1(int *n){
    *n = (*n) + 10;
    
	printf("fun()运行结果:\r\n\r\n*n = %d\r\n", *n);
	printf(" n = 0x%08X\r\n", n);
	printf("&n = 0x%08X\r\n\r\n", &n);
}
void test1(){
    int a = 1;
    int *n = &a;
    fun1(n);
    printf("n = %d \n", *n);
    printf("&n = 0x%08X \n", n);//0x 普通字符 原样输出 %08X 十六进制输出，8为对齐，不足的用0补齐
}

void fun2(char **s){
    *s = (char *)malloc(100);
}
void test02(){
    // char *p = NULL;
    char *p = "jiayou";
    printf("0x%08X\n", p);
    fun2(&p);
    printf("0x%08X\n", p);
    if(p) free(p);

}

void fun3(int* p){//改变形参指向 就与实参无关了  不能使用形参去申请内存
    int b = 100;
    p = &b;
}
void test03(){
    int a = 10;
    int *q;
    q = &a;
    printf("%d\n", *q);
    fun3(q);
    printf("%d\n", *q);
}

void fun4(int *p){
    *p = *p + 10;
}
void test04(){
    int a = 10;
    int *q = &a;
    printf("%d\n", *q);
    fun4(q);
    printf("%d\n", *q);
}

void test05(){
    int a = 10000;
    int b = 20;

    int *p1 = &a;
    int *p2 = &b;

    int num = p1 - p2;
    
    printf("p1= %x\n", p1);
    printf("p2= %x\n", p2);
    printf("num的地址=%x, num=%d\n", &num, num);  
}
int main(){
    test05();

    return 0;
}