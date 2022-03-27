#include<iostream>
#include<string>
using namespace std;

//十六进制字符串串转二进制
string HexStrToBinStr(string& inputHex){
    string binStr;
    for(auto ch : inputHex){
        switch (ch)
        {
        case '0' : binStr += "0000"; break;
        case '1' : binStr += "0001"; break;
        case '2' : binStr += "0010"; break;
        case '3' : binStr += "0011"; break;
        case '4' : binStr += "0100"; break;
        case '5' : binStr += "0101"; break;
        case '6' : binStr += "0110"; break;
        case '7' : binStr += "0111"; break;
        case '8' : binStr += "1000"; break;
        case '9' : binStr += "1001"; break;
        case 'a' : binStr += "1010"; break;
        case 'b' : binStr += "1011"; break;
        case 'c' : binStr += "1100"; break;
        case 'd' : binStr += "1101"; break;
        case 'e' : binStr += "1110"; break;
        case 'f' : binStr += "1111"; break;
        default:
            break;
        }
    }
    cout << &binStr << endl;
    return binStr;
}
//二进制转十进制
struct decStr{
    int len;
    char decstr[100000];
    decStr() : len(0){
        for(int i = 0; i < 100000; ++i)
            decstr[i] = 0;
    }
};
void addCurNumToDecStr(decStr& data, int num){
    for(int i = 0; i < data.len; ++i)
        data.decstr[i] *= 2;
    data.decstr[0] += num;
    for(int i = 0; i < data.len; ++i){
        data.decstr[i + 1] += data.decstr[i] / 10;
        data.decstr[i] %= 10;
    }
    if(data.decstr[data.len] != 0) ++data.len;
}
string assicTostr(decStr&data){
    string decstr;
    for(int i = data.len - 1; i >= 0; --i){
        decstr += data.decstr[i] + '0';
    }
    return decstr;
}
string BinStrToDecStr(string& binStr){
    decStr data;
    for(int i = 0; i < binStr.size(); ++i){
        addCurNumToDecStr(data, binStr[i] == '1' ? 1 : 0);    
    }
    string decstr = assicTostr(data);
    return decstr;
}
int main(){
    string inputHex;
    cin >> inputHex;
    inputHex = inputHex.substr(2);
    string binStr = move(HexStrToBinStr(inputHex));
    cout << &binStr << endl;
    int cnt = 0;
    for(auto ch : binStr)
        if(ch == '1')
            ++cnt;
    cout << cnt << endl;
    cout << binStr << endl;
    string decstr = BinStrToDecStr(binStr);
    cout << decstr << endl;
    system("pause");
    return 0;
}


//十六进制字符串 转为二进制字符串 1 的个数
// int main(){
//     string inputHex;
//     cin >> inputHex;
//     int bitOneNumber[16] = {0, 1, 1, 2, 1, 2, 2, 3, 1, 2, 2, 3, 2, 3, 3, 4};
//     inputHex = inputHex.substr(2);
//     int cnt = 0;
//     for(auto ch : inputHex){
//         if(ch >= '0' && ch <= '9')
//             cnt += bitOneNumber[ch - '0'];
//         else if(ch >= 'a' && ch <= 'f')
//             cnt += bitOneNumber[ch - 'a' + 10];
//         else
//             return -1;
//     }
//     cout << cnt <<  endl;
//     system("pause");
//     return 0;
// }


// int main(){
//     string inputHex;
//     cin >> inputHex;
//     string::size_type index;
//     int i = stoi(inputHex, &index, 16);  //size_type 可以接受string类型最大长度  index 表示处理数字后的下一个位置  
//     cout << i << "   " << index << endl;
//     system("pause");
//     return 0;
// }