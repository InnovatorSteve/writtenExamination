#include<iostream>
#include<vector>
using namespace std;

void MaxHeap(vector<int>& nums, int root, int len){
    int leftSon = root*2+1, rightSon = root*2+2, largest = root;
    if(leftSon <= len && nums[leftSon] > nums[largest]) largest = leftSon;
    if(rightSon <= len && nums[rightSon] > nums[largest]) largest = rightSon;
    if(largest != root){
        swap(nums[largest], nums[root]);
        MaxHeap(nums, largest, len);
    }
}

void buildMaxHeap(vector<int>& nums, int len){
    for(int i = len / 2; i >= 0; --i)
        MaxHeap(nums, i, len);
}

int getKthElement(vector<int>& nums, int k){
    int len = nums.size() - 1;
    buildMaxHeap(nums, len);
    for(int i = 1; i < k; ++i){
        swap(nums[0], nums[len--]);
        MaxHeap(nums, 0, len);
    }
    return nums[0];
}
int main(){
    vector<int> nums({3,1,2,4});
    int k = 2;
    cout << getKthElement(nums, k) << endl;
    return 0;
}