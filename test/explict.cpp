
class CxString  // ʹ�ùؼ���explicit��������, ��ʾת��  
{  
public:  
    char *_pstr;  
    int _size;  
    explicit CxString(int size)  
    {  
        _size = size;  
        // ����ͬ��, ʡ��...  
    }  
    CxString(const char *p)  
    {  
        // ����ͬ��, ʡ��...  
    }  
};  
  
    // �����ǵ���:  
int main(){
    CxString string1(24);     // ������OK��  
    CxString string2 = 10;    // �����ǲ��е�, ��Ϊexplicit�ؼ���ȡ������ʽת��  
    CxString string3;         // �����ǲ��е�, ��Ϊû��Ĭ�Ϲ��캯��  
    CxString string4("aaaa"); // ������OK��  
    CxString string5 = "bbb"; // ����Ҳ��OK��, ���õ���CxString(const char *p)  
    CxString string6 = 'c';   // �����ǲ��е�, ��ʵ���õ���CxString(int size), ��size����'c'��ascii��, ��explicit�ؼ���ȡ������ʽת��  
    string1 = 2;              // ����Ҳ�ǲ��е�, ��Ϊȡ������ʽת��  
    string2 = 3;              // ����Ҳ�ǲ��е�, ��Ϊȡ������ʽת��  
    string3 = string1;        // ����Ҳ�ǲ��е�, ��Ϊȡ������ʽת��, ������ʵ�ֲ�����"="������  
    const char *p = 'a';  //'a'  ����assic��  "ada"��Ӧ������ַ  
    return 2;
}
