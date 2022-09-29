#include<iostream>
#include<string>
#include<unordered_map>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;
string canDealQue;
//h:[e,f,g]:2;e:[b]:6;f:[c]:6;g:[d]:6;b:[a]:5;c:[a]:5;d:[a]:5;a:[]:3/2   22
//a:[b,c]:3;b:[c,d,g]:1;g:[d,f]:2;c:[]:4;d:[]:5;f:[c]:6/3  17
//a:[]:3;b:[a]:7;c:[a]:8;d:[a,c]:4;e:[b,c]:3;f:[a,b]:2;g:[c]:5/3  18
void addCoreTask(vector<int>& coreTime, int time){ //选择执行时间最短的 添加任务时间 即最早结束的
    int minTime = INT_MAX, minIndex = -1;
    for(int i = 0; i < coreTime.size(); ++i){
        if(coreTime[i] < minTime){
            minTime = coreTime[i];
            minIndex = i;
        }
    }
    coreTime[minIndex] += time;
}

string remove(string& curDealTasks, unordered_map<char, set<char>>& depend){//完成一次并发  会有新的可处理任务产生
    string newCanDealQue;//执行完当前并发任务，会有新的就绪任务产生
    for(int i = 0; i < curDealTasks.size(); ++i){
        for(auto it = depend.begin(); it != depend.end(); ++it){
            if(it->second.erase(curDealTasks[i]) != 0 && it->second.empty())  //被移除个数不为0
                newCanDealQue += it->first;
        }
    }
    curDealTasks.clear();  //清零 继续记录下一次并发处理的任务
    return newCanDealQue;
}

void mySort(string& waitRunseq, string& newCanDealQue){//将就绪任务排序 保证先来先服务
    string temp = waitRunseq;
    for(int i = 0; i < temp.size(); ++i){
        if(newCanDealQue.find(temp[i]) == string::npos)
            temp.erase(i--, 1);
    }
    newCanDealQue = temp;
}

int main(){
    string s;
    cin >> s;
    size_t pos = s.find('/');
    int coreNum = stoi(s.substr(pos + 1));
    s.erase(pos, s.size() - pos);
    unordered_map<char, int> time;
    unordered_map<char, set<char>> depend;
    string seq;
    for(int i = 0; i < s.size(); ++i){//处理数据
        char curChar = s[i];  seq += curChar;
        i += 3;
        if(s[i] == ']') {time[curChar] = s[i + 2] - '0'; i += 3; continue;}
        depend[curChar].insert(s[i++]);
        while(s[i] == ','){
            depend[curChar].insert(s[++i]), i++;
        }
        if(s[i] == ']')
            time[curChar] = s[i + 2] - '0';
        i += 3;  //应该加4  但是for循环还有+1
    }
    int ans = 0;  string waitRunseq = seq;
    vector<int> coreTime(coreNum, 0);
    for(int i = 0; i < seq.size(); ++i){ //初始可以处理的任务
        if(depend[seq[i]].empty())
            canDealQue += seq[i];
    }
    int cntCore = 0;
    while(!waitRunseq.empty()){//需要处理的队列不为空  //这里题目没有出现 部分任务无法执行的情况，所以和下个while效果基本相同
        string curDealTasks;
        while(!canDealQue.empty()){//可以处理的任务不为空 
            curDealTasks += canDealQue.front();  //先来先服务
            addCoreTask(coreTime, time[canDealQue.front()]);   //添加至最早结束的core
            if(waitRunseq.find(canDealQue.front()) != string::npos)
                waitRunseq.erase(waitRunseq.find(canDealQue.front()), 1);  //从等待处理队列 删除已处理任务
            canDealQue.erase(0, 1);  //当前可处理队列 删除已处理任务
            ++cntCore;  //本次并发数
            if(canDealQue.empty()){//这里要写到 在判断是否并发数等于coreNum之前 因为如果处理到当前并发可执行的最后一个任务的时候，
            //可处理队列是空的  那么就需要等到最晚结束的core执行完，才会有新的就绪任务    
            //主要是保证 在任务达到并发上限，但是没有新的任务产生的情况。  如果有3个core，但是只分配了1个任务，就没有新的就绪任务了，写在最后也可以
                coreTime.assign(coreNum, *max_element(coreTime.begin(), coreTime.end())); //没有新的就绪任务，同步core，结束早的等待最晚的
                cntCore = 0; auto newCanDealQue = remove(curDealTasks, depend); //本轮并发分配技术，cnt置零，告知未就绪任务，如果依赖当前并发任务，可以开始了
                mySort(waitRunseq, newCanDealQue); canDealQue += newCanDealQue; continue;// += 保证上轮就绪任务执行完，再处理新的就绪任务
            }//continue; 本轮并发已结束，没必要继续执行下列
            if(cntCore % coreNum == 0){//各个core都分配了任务，而且还有可就绪任务
                cntCore = 0; auto newCanDealQue = remove(curDealTasks, depend); 
                mySort(waitRunseq, newCanDealQue); canDealQue += newCanDealQue;
            }
        }
    }
    string curNoDependTask;
    cout << *max_element(coreTime.begin(), coreTime.end());
    return 0; 
}
