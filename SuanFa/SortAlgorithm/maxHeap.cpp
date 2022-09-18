#include<iostream>
#include<vector>
using namespace std;

void maxHeap(vector<int>& arr, int root, int len){
    int left = root * 2, right = root * 2 + 1, largest = root;
    if(left < len && arr[left] > arr[largest]) largest = left;
    if(right < len && arr[right] > arr[largest]) largest = right;
    if(largest != root){
        swap(arr[largest], arr[root]);
        maxHeap(arr, largest, len);
    }
}

void createHead(vector<int>& arr, int len){
    for(int i = (len + 1) >> 1; i >= 0; --i)
        maxHeap(arr, i, len);
}

int main(){
    vector<int> arr =  {7, 2, 5, 9, 3, 5, 10, 42};
    int len = arr.size();
    createHead(arr, len);
    while(len){
        swap(arr[0], arr[len - 1]);
        len--;
        maxHeap(arr, 0, len);
    }
    return 0;
}