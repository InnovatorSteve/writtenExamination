#include<iostream>

using namespace std;

int* test(int i){
  float a = 1 / 2; // 1 / 2是整形除法 不能得到预期的0.5
  int b = i;
  int *c;  //指针没有初始化  野指针 后边赋值 会覆盖未知区域
  switch(b){
    case 0:
      *c = b;
      break;
    case  1 + 2:
      b = 3 / a;  //a此时为0  不能作为被除数
      break;
    case 4:
      if(0.5 == a)
        //continue;
      break;
    dafault:
      break;
  } 
  return &b;  //不能返回一个局部变量的地址
}

int main(){
  float a = 0.50;
  if(a == 0.5)
    cout << "yes" << endl;
  int *n = test(3);
  cout << *n << endl;
  return 0;
}