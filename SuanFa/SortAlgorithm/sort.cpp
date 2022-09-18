#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

    int maxBits(int maxNum){
        int k = 0;
        while(maxNum > 0)
            maxNum /= 10, ++k;
        return k;
    }
    void sortPositive(vector<int>& positive, int maxbits){
        int radix = 1; vector<int> temp(positive.size());
        for(int i = 1; i <= maxbits; ++i){
            vector<int> count(10);
            for(auto& num : positive)
                ++count[num / radix % 10];
            for(int i = 1; i < 10; ++i)
                count[i] += count[i - 1];
            for(int i = positive.size() - 1; i >= 0; --i)
                temp[--count[positive[i] / radix % 10]] = positive[i];
            radix *= 10;
            positive = temp;
        }
    }
    void sortNegaive(vector<int>& nums, int maxbits){
        int radix = 1; vector<int> temp(nums.size());
        for(int i = 1; i <= maxbits; ++i){
            vector<int> count(10);
            for(auto& num :nums)
                ++count[-num / radix % 10];
            for(int i = 8; i >= 0; --i)
                count[i] += count[i + 1];
            for(int i = nums.size() - 1; i >= 0; --i)
                temp[--count[-nums[i] / radix % 10]] = nums[i];
            radix *= 10;
            nums = temp;
        }
    }
    vector<int> sortArray(vector<int>& nums) {
        vector<int> positive, negative;
        for(auto& num : nums) if(num >= 0) positive.emplace_back(num); else negative.emplace_back(num);
        if(positive.size() > 0) sortPositive(positive, maxBits(*max_element(positive.begin(), positive.end())));
        if(negative.size() > 0) sortNegaive(negative, maxBits(-*min_element(negative.begin(), negative.end())));
        nums = negative;
        nums.insert(nums.end(), positive.begin(), positive.end());
        return nums;
    }

int main(){
    vector<int> nums = {-5,-2,-3,-1};//{5864,-12333,4151,-6239,-10306,10866,-7013,13195,-8855,1150,-560,3227,10387,-2329,5169,-19527,2689,597,4255,-13697,12495,19719,15995,8991,-12859,5601,8195,3943,16216,-19677,15590,10316,-4255,45,-6508,-5416,4993,15278,-6015,-18843,-8400,-6994,3608,-7695,-14698,-2684,8753,18019,3266,-10860,-14354,8708,19037,-16188,4932,1403,-10571,18368,-9786,13410,1686,-17352,-13827,6647};
    sortArray(nums);
    return 0;
}


// class Solution {
// public:
//     void bubbleSort(vector<int>& nums)
//     {
//         for(int i = 0; i < nums.size() - 1; ++i)
//         {
//             for(int j = 0; j < nums.size() - 1 - i; ++j)
//             {
//                 if(nums[j] > nums[j + 1])
//                 {
//                     swap(nums[j], nums[j + 1]);
//                 }
//             }
//         }
//     }

//     void selection_sort(vector<int>& nums)
//     {
//         for(int i = 0; i < nums.size() - 1; ++i)
//         {
//             int min_index = i;
//             for(int j = i; j < nums.size(); ++j)
//             {
//                 if(nums[j] < nums[min_index])
//                 {
//                     min_index = j;
//                 }
//             }
//             swap(nums[i], nums[min_index]);
//         }
//     }

//     void insertion_sort(vector<int>& nums)
//     {
//         for(int i = 1; i < nums.size(); ++i)
//         {
//             int key = nums[i];
//             int j = i - 1;
//             while(j >= 0 && (nums[j] > key))
//             {
//                 nums[j + 1] = nums[j];
//                 --j;
//             }
//             nums[j + 1] = key;
//         }
//     }

//     void shell_sort(vector<int>& nums)
//     {
//         int gap = 1;
//         while(gap < nums.size())
//         {
//             gap = gap * 3 + 1;
//         }
//         while(gap > 0)
//         {
//             for(int i = gap; i < nums.size(); ++i)
//             {
//                 int key = nums[i];
//                 int j = i - gap;
//                 while(j >= 0 && (nums[j] > key))
//                 {
//                     nums[j + gap] = nums[j];
//                     j -= gap;
//                 }
//                 nums[j + gap] = key;
//             }
//             gap /= 3;
//         }
//     }

//     void merge(vector<int>& nums, int left, int mid, int right)
//     {
//         int n = right - left + 1;
//         vector<int> tmp(n);
//         int i = left;
//         int j = mid + 1;
//         int t = 0;
//         while(i <= mid && j <= right)
//         {
//             if(nums[i] < nums[j])
//             {
//                 tmp[t++] = nums[i++];
//             }
//             else
//             {
//                 tmp[t++] = nums[j++];
//             }
//         }
//         while(i <= mid)
//         {
//             tmp[t++] = nums[i++];
//         }
//         while(j <= right)
//         {
//             tmp[t++] = nums[j++];
//         }
//         t = 0;
//         while(left <= right)
//         {
//             nums[left++] = tmp[t++];
//         }
//     }
//     void mergeSort(vector<int>& nums, int left, int right)
//     {
//         if(left >= right)
//         {
//             return;
//         }
//         int mid = left + (right - left) / 2;
//         mergeSort(nums, left, mid);
//         mergeSort(nums, mid + 1, right);
//         merge(nums, left, mid, right);
//     }

//     void quick_sort_recursive(vector<int>& nums, int start, int end)
//     {
//         if(start >= end)
//         {
//             return;
//         }
//         int key = nums[end];
//         int left = start, right = end - 1;
//         while(left < right)
//         {
//             while(left < right && nums[left] < key)
//             {
//                 ++left;
//             }
//             while(left < right && nums[right] > key)
//             {
//                 --right;
//             }
//             swap(nums[left], nums[right]);
//         }
//         if(nums[left] >= nums[end])
//         {
//             swap(nums[left], nums[end]);
//         }
//         else
//         {
//             ++left;
//         }
//         quick_sort_recursive(nums, start, left - 1);
//         quick_sort_recursive(nums, left + 1, end);
//     }
//     void quick_sort(vector<int>& nums)
//     {
//         quick_sort_recursive(nums, 0, nums.size() - 1);
//     }

//     void heap_sort(vector<int>& nums)
//     {
//         int n = nums.size();
//         for(int i = n / 2 - 1; i >= 0; --i)
//         {
//             swiftdown(nums, i, n - 1);
//         }
//         for(int i = n - 1; i > 0; --i){
//             swap(nums[0], nums[i]);
//             swiftdown(nums, 0, i - 1);
//         }
//     }
//     void swiftdown(vector<int>& nums, int start, int end)
//     {
//         while((2 * start + 1) <= end)
//         {
//             int j = 2 * start + 1;
//             if((j + 1) <= end && nums[j] < nums[j + 1])
//             {
//                 ++j;
//             }
//             if(nums[start] > nums[j])
//             {
//                 return;
//             }
//             else
//             {
//                 swap(nums[start], nums[j]);
//             }
//             start = j;
//         }
//     }

//     vector<int> countSort(vector<int>& nums, int max, int min)
//     {
//         int n = max - min + 1;
//         vector<int> cnt(n);
//         for(int i = 0; i < nums.size(); ++i)
//         {
//             cnt[nums[i] - min]++;
//         }
//         for(int i = 1; i < n; ++i)
//         {
//             cnt[i] += cnt[i - 1];
//         }
//         vector<int> ans(nums.size());
//         for(int i = nums.size() - 1; i >= 0; --i)
//         {
//             ans[cnt[nums[i] - min] - 1] = nums[i];
//             --cnt[nums[i] - min];
//         }
//         return ans;
//     }

//     vector<int> sortArray(vector<int>& nums) {
//         // //冒泡排序
//         // bubbleSort(nums);
        
//         // //选择排序
//         // selection_sort(nums);

//         // //插入排序
//         // insertion_sort(nums);

//         // //希尔排序
//         // shell_sort(nums);

//         // //归并排序
//         // mergeSort(nums, 0, nums.size() - 1);

//         // //快速排序
//         // quick_sort(nums);

//         // //堆排序
//         // heap_sort(nums);

//         //计数排序
//         int max = *max_element(nums.begin(), nums.end());
//         int min = *min_element(nums.begin(), nums.end());
//         return countSort(nums, max, min);
//         return nums;
//     }
// };