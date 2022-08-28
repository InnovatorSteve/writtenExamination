#include<iostream>
#include<vector>
using namespace std;

int binarySerach(vector<int>& arr, int target){
    int left = 0, right = arr.size() - 1;
    while(left < right){
        int mid = (left + right) >> 1;
        if(arr[mid] >=  target)
            right = mid;
        else
            left = mid + 1;
    }
    return arr[left] == target ? left : -1;
}

int main(){
    vector<int> arr = {1,3,3,3,5,7,7,9};
    int index = binarySerach(arr, 7);
    cout << index << endl;
    return 0;
}