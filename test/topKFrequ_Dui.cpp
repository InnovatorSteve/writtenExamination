#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<time.h>
//test
using namespace std;
//自建大顶堆
class Solution {
public:
    void MaxHeap(vector<pair<int, int>>& frequentVec, int root, int len){
        int left = root * 2 + 1, right = root * 2 + 2, largest = root;
        if(left < len && frequentVec[left].second > frequentVec[largest].second) largest = left;
        if(right < len && frequentVec[right].second > frequentVec[largest].second) largest = right;
        if(largest != root){
            swap(frequentVec[largest], frequentVec[root]);
            MaxHeap(frequentVec, largest, len);
        }
    }
    void buildMaxHeap(vector<pair<int, int>>& frequentVec, int len){
        for(int i = len / 2 - 1; i >= 0; --i)
            MaxHeap(frequentVec, i, len);
    }
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> frequentMap;
        for(auto& num : nums) frequentMap[num]++;
        vector<pair<int, int>> frequentVec(frequentMap.begin(), frequentMap.end());
        int len = frequentVec.size();
        buildMaxHeap(frequentVec, len);
        vector<int> ans;
        for(int i = 0; i < k; ++i){
            ans.emplace_back(frequentVec[0].first);
            swap(frequentVec[0], frequentVec[--len]);
            MaxHeap(frequentVec, 0, len);
        }
        return ans;
    }
};

//使用优先队列 堆
class Solution1{
public:
    struct cmp{
        bool operator()(pair<int, int>& a, pair<int, int>& b){
            return a.second > b.second;
        }
    };
    // static bool cmp(pair<int, int>& a, pair<int, int>& b){
    //         return a.second > b.second;
    // }
    vector<int> topKFrequent(vector<int>& nums, int k){
        map<int, int> fre_map;
        for(auto num : nums) fre_map[num]++;
        // priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(&cmp)> q(cmp);
        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> q;
        for(auto& [num, count] : fre_map){
            if(q.size() == k){
                if(q.top().second < count)
                    q.pop(), q.emplace(num, count);
            }else q.emplace(num, count);
        }
        vector<int> ret;
        while(!q.empty()){
            ret.emplace_back(q.top().first);
            q.pop();
        }
        return ret;
    }
};

//使用快排
class Solution2{
public:
    void qsort(vector<pair<int, int>>& numsVec, int k, vector<int>& ans, int start, int end){
        int q = rand() % (end - start + 1) + start;
        swap(numsVec[start], numsVec[q]);
        int index = start;
        for(int i = start + 1; i <= end; ++i){
            if(numsVec[i].second >= numsVec[start].second)
                swap(numsVec[i], numsVec[++index]); 
        }
        swap(numsVec[index], numsVec[start]);
        if(index - start + 1 > k){//当前已完成  [start, index) 均大于numsVec[index] 例需要前3大 现求得为前4大 那么需要缩小范围
            qsort(numsVec, k, ans, start, index - 1);
        }else{
            for(int i = start; i <= index; ++i)
                ans.emplace_back(numsVec[i].first);
            if(index - start + 1 < k)
                qsort(numsVec, k - (index - start + 1), ans, index + 1, end);
        }
    }
    vector<int> topKFrequent(vector<int>& nums, int k){
        srand(time(0));
        map<int, int> numsMap;
        for(auto num : nums) numsMap[num]++;
        vector<pair<int, int>> numsVec(numsMap.begin(), numsMap.end());
        vector<int> ans;
        qsort(numsVec, k, ans, 0, numsVec.size() - 1);
        return ans;
    }
};
int main()
{
    vector<int> nums = {1,1,1,2,2,3};
    int k = 2;
    Solution2 s;
    vector<int> ans = s.topKFrequent(nums, k);
    for(auto& num : ans) cout << num << " ";
    cout << endl;
    system("pause");
    return 0;
}