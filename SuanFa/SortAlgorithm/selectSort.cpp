#include<iostream>
#include<vector>
using namespace std;

template<typename T>
void insertSort(std::vector<T>& arr){
    int len = arr.size();
    for(int i = 1; i < len; ++i){
        for(int j = i - 1; j >= 0 && arr[j] > arr[j + 1]; --j)
            swap(arr[j], arr[j + 1]);
    }
}

int main(){
    vector<int> arr = {7, 2, 5, 9, 3, 5, 10, 42};
    //insertSort(arr);
    insertSort<int>(arr);
    return 0;
}


//选择排序  保存当前未排序中最小元素下标  并与未排序第一个元素交换， 
// template<typename T>
// void Selection_Sort(std::vector<T>& arr){
//     int len = arr.size();
//     for(int i = 0; i < len  - 1; ++i){
//         int min = i;
//         for(int j = i + 1; j < len; ++j)
//             if(arr[j] < arr[min]) min = j;
//         if(min != i) swap(arr[i], arr[min]);
//     }
// }