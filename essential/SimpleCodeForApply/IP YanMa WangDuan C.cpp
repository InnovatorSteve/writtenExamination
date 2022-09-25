//判断IP地址  和子网掩码
#include<stdlib.h>
#include<stdio.h>
#include<string.h>

bool func(char* IPSeg, char* IPAddr, int k){
    int n = k / 8;
    int bit = k % 8;
    int i = 0, j = 0;
    int IPSegNum[5], IPAddrNum[5];
    int numsIndes = 0;
    while(numsIndes < 5){
        int num = 0;
        while(IPSeg[i] != '.' && IPSeg[i] != '\0'){
            char c = IPSeg[i];
            num = num * 10 + IPSeg[i++] - '0';
        }
        IPSegNum[numsIndes] = num;
        num = 0;
        while(IPAddr[j] != '.' && IPAddr[j] != '\0'){
            char c = IPAddr[j];
            num = num * 10 + IPAddr[j++] - '0';
        }
        IPAddrNum[numsIndes] = num;
        ++numsIndes;  ++i, ++j;
    }
    for(int i = 0; i < n; ++i)
        if(IPAddrNum[i] != IPSegNum[i])
            return false;
    if(bit == 0) return true;
    char str1[8], str2[8];
    itoa(IPSegNum[n], str1, 2);
    itoa(IPAddrNum[n], str2, 2);
    char binStr1[8], binStr2[8]; memset(binStr1, '0', 8);  memset(binStr2, '0', 8);
    int temp = 7;
    for(int startIndex = strlen(str1) - 1; startIndex >= 0; --startIndex)
        binStr1[temp--] = str1[startIndex];
    temp = 7;
    for(int startIndex = strlen(str2) - 1; startIndex >= 0; --startIndex)
        binStr2[temp--] = str2[startIndex];
    for(int i = 0; i < bit; ++i)
        if(str1[i] != str2[i])
            return false;
    return true;
}

int main(){
    char *s1 = "10.10.10.0.1";
    char *s2 = "10.10.10.0.33";
    printf("%d\n", func(s1, s2, 35));
}