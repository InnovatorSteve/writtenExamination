/**
 * struct ListNode {
 *	int val;
 *	struct ListNode *next;
 * };
 */

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     * 
     * @param a ListNode类vector 指向每段碎片的开头
     * @return ListNode类
     */
    map<int,int>l,r;
    ListNode* solve(vector<ListNode*>& a) {
        // write code here
        
        int i,mi=1e9;
        ListNode*p;
        for(i=0;i<a.size();i++){
            p=a[i];
            
            mi=min(mi,p->val);
            if(!p)continue;
            while(p->next){
                r[p->val]=p->next->val;
                l[p->next->val]=p->val;
                p=p->next;
                mi=min(mi,p->val);
            }
        }
        ListNode*out=new ListNode(mi);
        p=out;
        if(l[mi]>r[mi]){
            while(r[p->val]!=mi){
                p->next=new ListNode(r[p->val]);
                p=p->next;
            }
        }
        else{
            while(l[p->val]!=mi){
                p->next=new ListNode(l[p->val]);
                p=p->next;
            }
        }
        return out;
    }
};