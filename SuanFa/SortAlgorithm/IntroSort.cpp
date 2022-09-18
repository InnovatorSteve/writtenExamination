#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
//数据量的分界线，决定了使用quick sort/heap sort还是insertion sort
const int threshold=16;
  
void insertionSort(vector<int>& nums, int len) {  
	for (int i = 1; i <= len; ++i) {
		for (int j = i - 1; j >= 0 && nums[j] > nums[j + 1]; --j)
			swap(nums[j], nums[j + 1]);
	}
}

//堆排序
void maxHeap(vector<int>& nums, int start, int end, int root) {  //对其中一部分进行堆排序 root要计算相对位置
	int l = (root - start) * 2 + 1 + start, r = (root - start) * 2 + 2 + start;
    int largest = root;
	if (l <= end && nums[l] > nums[largest]) largest = l;
	if (r <= end && nums[r] > nums[largest]) largest = r;
	if (largest != root) {
		swap(nums[root], nums[largest]);
		maxHeap(nums, start, end, largest);
	}
}
void createMaxHeap(vector<int>& nums, int start, int end) {
	for (int i = start + (end - start) / 2; i >= start; --i)
		maxHeap(nums, start, end, i);
}
void heapSort(vector<int>& nums, int start, int end) {
	createMaxHeap(nums, start, end);
	for (int i = end; i > start; --i) {
		swap(nums[i], nums[start]);
		maxHeap(nums, start, i, start);
	}
}
 
//三点中值
int median3(vector<int>& array,int first,int median,int end)
{
		if(array[first]<array[median])
		{
				if(array[median]<array[end])
						return median;
				else if(array[first]<array[end])
						return end;
				else
						return first;
		}
		else if(array[first]<array[end])
				return first;
		else if(array[median]<array[end])
				return end;
		else 
				return median;
}
 
//对数组分割
int partition(vector<int>& nums, int left, int right, int pivot) {
	int target = nums[pivot];
	swap(nums[pivot], nums[right]);
	int index = left;
	for (int i = left; i < right; ++i) {
		if (nums[i] <= target)
			swap(nums[i], nums[index++]);
	}
	swap(nums[index], nums[right]);
	return index;
}
 
//递归的对数组进行分割排序
void introSortLoop(vector<int>& array,int begin,int end,int depthLimit)
{
		while((end-begin+1)>threshold) //子数组数据量大小，则交给后面的插入排序进行处理
		{
				if(depthLimit==0)      //递归深度过大，则由堆排序代替
				{
						heapSort(array,begin,end);
						return ;
				}
				--depthLimit;
				//使用quick sort进行排序
				int cut=partition(array,begin,end,
								median3(array,begin,begin+(end-begin)/2,end)); 
				introSortLoop(array,cut,end,depthLimit);
				end=cut;    //对左半段进行递归的sort
		}
}
 
//计算最大容忍的递归深度
int lg(int n)
{
		int k;
		for(k=0;n>1;n>>=1) ++k;
		return k;
}
 
 
//霸气的introsort
void introSort(vector<int>& array,int len)
{
		if(len!=1)
		{
				introSortLoop(array,0,len-1,lg(len)*2);
				insertionSort(array,len - 1);
		}
}
    vector<int> sortArray(vector<int>& nums) {
        introSort(nums, nums.size());
        return nums;
    }
};

int main(){
    vector<int> nums = { 5864,-12333,4151,-6239,-10306,10866,-7013,13195,-8855,1150,-560,
    3227,10387,-2329,5169,-19527,2689,597,4255,-13697,12495,19719,15995,8991,-12859,5601,
    8195,3943,16216,-19677,15590,10316,-4255,45,-6508,-5416,4993,15278,-6015,-18843,-8400,
    -6994,3608,-7695,-14698,-2684,8753,18019,3266,-10860,-14354,8708,19037,-16188,4932,1403,
    -10571,18368,-9786,13410,1686,-17352,-13827,6647,16747,2664,-15830,13673,-10248,2115,-19074,
    -919,4382,18718,-7449,-16031,333,-14066,-2505,-9975,-226,-18986,17487,-3498,-17203,-3506,8462,
    -191,10563,10160,12627,-8306,9439,-16640,4586,-12067,-19904,-5607,-15989,15651,-18358,-850,-850,
    3472,8969,13113,1269,4808,123,16848,9857,17099,14566,4854,-19826,957,-10325,-8686,11542,-10343,
    -16353,-9446,-18914,3242,5897,-19881,-16532,14827,-5840,2873,-10823,-4545,5028,-4985,15482,-8196,
    14376,-11370,4044,-18929,15051,5562,15969,-4135,13438,12928,-5472,10521,11392,-16511,461,12535,12429,
    13353,5861,6523,2158,16888,8264,580,-18042,-10113,-809,3072,14636,-12239,-18102,8235,14993,-15364,
    -19620,-13386,-18777,-7497,5057,-8141,-3481,10271,-9995,-7095,3227,596,-16996,-18539,1110,-13797,
    10370,-17772,11653,15077,18369,11289,-19190,-8459,9841,-7993,-5988,-12463,-11450,503,17321,11286,
    -2143,-10043,2124,4675,9222,-7730,-7148,5883,-16544,-10609,-14124,2870,-17110,-8522,-15060,-3181,
    -7346,-14611,-19707,10749,-18521,3296,12425,-12432,3861,5762,19198,-8727,14496,38,6655,9821,16008,
    };
	Solution s;
    s.sortArray(nums);
    for(int i = 1; i < nums.size(); ++i) if(nums[i] < nums[i - 1]) cout << "!!!!cuowu" << endl;
    return 0;   
}


