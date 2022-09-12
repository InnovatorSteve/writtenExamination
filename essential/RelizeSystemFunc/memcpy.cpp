//内存拷贝
//  1.四字节拷贝性能更高
//  2.定义临时指针，不破坏原来指针位置。
//  3.指针类型转换为同一类型 进行拷贝 不能类型指针不能直接++
//  4.地址重叠 要从高位开始复制。
#include<iostream>
using namespace std;

// void memcpy(void *dest, void *src, int size){
//     uint8_t *pdest = (uint8_t*)dest;   //uint8_t  1个字节 char  uint16_t 2个字节 short uint32_t 4字节 int
//     uint8_t *psrc = (uint8_t*)src;
//     int loops = (size / sizeof(uint32_t));  //四字节对齐 速度更快  32位机器读写一次读写四字节
//     for(int i = 0; i < loops; ++i){
//         *((uint32_t*)pdest) = *((uint32_t*)psrc);
//         pdest += sizeof(uint32_t);
//         psrc += sizeof(uint32_t);
//     }
//     loops = (size % sizeof(uint32_t));
//     for(int i = 0; i < loops; ++i){
//         *pdest++ = *psrc++;  //一条语句实现的问题在于 非原子性的 一旦复制出现错误，可能指针指向与实际已复制 不一致
//     } 
// }
void memcpyOverlap(void *dest, void *src, int size){
    uint8_t *pdest = (uint8_t*)dest;   
    uint8_t *psrc = (uint8_t*)src;
    pdest += size - 1;
    psrc += size - 1;
    int loops = (size / sizeof(uint32_t));  //按照CPU位宽拷贝。
    while(loops--){
        *((uint32_t*)pdest) = *((uint32_t*)psrc);
        pdest -= sizeof(uint32_t);
        psrc -= sizeof(uint32_t);
    }
    loops = (size % sizeof(uint32_t));
    while(loops--){
        *pdest-- = *psrc--;  //一条语句实现的问题在于 非原子性的 一旦复制出现错误，可能指针指向与实际已复制 不一致
    } 
}

void memcpy(void *dest, void *src, int size){
    if(dest == nullptr || src == nullptr) return;
    uint8_t *pdest = (uint8_t*)dest;   //uint8_t  1个字节 char  uint16_t 2个字节 short uint32_t 4字节 int
    uint8_t *psrc = (uint8_t*)src;
    if(psrc + size * sizeof(uint8_t) <= dest){
        memcpyOverlap(dest, src, size);
    }else{
        int loops = (size / sizeof(uint32_t));  //四字节对齐 速度更快  32位机器读写一次读写四字节
        for(int i = 0; i < loops; ++i){
            *((uint32_t*)pdest) = *((uint32_t*)psrc);
            pdest += sizeof(uint32_t);
            psrc += sizeof(uint32_t);
        }
        loops = (size % sizeof(uint32_t));
        for(int i = 0; i < loops; ++i){
            *pdest++ = *psrc++;  //一条语句实现的问题在于 非原子性的 一旦复制出现错误，可能指针指向与实际已复制 不一致
        } 
    }

}

int main(){
    int a[] = {10, 20, 30}; //-exec x/8x a 查看a的内存信息
    short b[] = {1, 2, 3};
    char c[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    memcpy(a, b, 4);
    for(int i = 0; i < 3; ++i)   //131073 20 30
        cout << a[i] << " ";
    cout << endl;

    memcpy(a, c, 6);
    for(int i = 0; i < 3; ++i)  //1684234849 26213 30
        cout << a[i] << " ";
    cout << endl;

    memcpy(c, b, 5);
    for(int i = 0; i < 5; ++i)
        cout << static_cast<int>(c[i]) << " ";
}