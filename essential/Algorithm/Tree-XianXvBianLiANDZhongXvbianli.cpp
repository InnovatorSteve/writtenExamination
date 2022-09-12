//先序 + 中序
void build1(node* &t, string pre, string mid)//建的树
{
    if(pre.length() == 0) {
        t = NULL;
        return;
    }
    char f = pre[0]; //根节点
    int idx = mid.find(f);
    string ml = mid.substr(0, idx); //左子树的中序
    string mr = mid.substr(idx+1);  //右子树的中序
    int L = ml.length();
    int R = mr.length();
    string pl = pre.substr(1, L); //左子树的前序
    string pr = pre.substr(L+1);  //右子树的前序
    t = new node;
    if(t) {
        t->data = f;
        build1(t->l, pl, ml); //递归建造左子树
        build1(t->r, pr, mr); //递归建造右子树
    }
}

//中序 + 后续
void build2(node* &t, string post, string mid)
{
    if(post.length() == 0) {
        t = NULL;
        return;
    }
    int len = post.length();
    char f = post[len-1];
    int idx = mid.find(f);
    string ml = mid.substr(0, idx);
    string mr = mid.substr(idx+1);
    int L = ml.length();
    int R = mr.length();
    string pl = post.substr(0, L);
    string pr = post.substr(L, R);
    t = new node;
    if(t) {
        t->data = f;
        build2(t->l, pl, ml);
        build2(t->r, pr, mr);
    }
}