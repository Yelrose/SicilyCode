
// Problem#: 1136
// Submission#: 1916461
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <cstdio>
using namespace std;
int array[100001];
struct Node{
    int max_prefix;
    int max_suffix;
    int max_sum;
    int sum;
    int l;
    int r;
    int pre;
    int suf;
    int maxl;
    int maxr;
}node[400001];
void RMQ_init(int l,int r,int k){

    node[k].r = r;
    node[k].l = l;
    int m = (r + l ) >> 1;
    if(l == r)node[k].sum = array[l];
    else {
        RMQ_init(l,m,2 * k);
        RMQ_init(m + 1,r,2 * k + 1);
        node[k].sum = node[2 * k].sum + node[2 * k + 1].sum;
    }
}

void RMQ_initpre(int l,int r,int k){
    int m = (l + r) >> 1;
    if(r == l){
        node[k].pre = l;
        node[k].max_prefix =array[l];
    }
    else {
        RMQ_initpre(l,m,2 * k);
        RMQ_initpre(m + 1,r,2 * k + 1);
        node[k].pre= node[2 * k].pre;
        node[k].max_prefix = node[2 * k].max_prefix;
        if(node[k].max_prefix < node[2 *k].sum + node[2 * k + 1].max_prefix){
            node[k].pre = node[2 * k + 1].pre;
            node[k].max_prefix = node[2 *k].sum + node[2 * k + 1].max_prefix;
        }
    }
    //cout << node[k].pre << " " << node[k].l << " " << node[k].r << "xx " << node[k].max_prefix  << endl;
}

void RMQ_initsuf(int l,int r,int k){
       int m = (l + r) >> 1;
    if(r == l){
        node[k].suf = l;
        node[k].max_suffix =array[l];
    }
    else {
        RMQ_initsuf(l,m,2 * k);
        RMQ_initsuf(m + 1,r,2 * k + 1);
        node[k].suf= node[2 * k + 1].suf;
        node[k].max_suffix = node[2 * k + 1].max_suffix;
        if(node[k].max_suffix <= node[2 *k + 1].sum + node[2 * k].max_suffix){
            node[k].suf = node[2 * k].suf;
            node[k].max_suffix = node[2 *k + 1].sum + node[2 * k].max_suffix;
        }
    }
    //cout << node[k].suf << " " << node[k].l << " " << node[k].r << "xx " << node[k].max_suffix  << endl;

}

void RMQ_initsum(int l,int r,int k){
    int m = (r + l) >> 1;
    if(l == r){
        node[k].max_sum  = array[l];
        node[k].maxl = l;
        node[k].maxr = r;
    }

    else {
        RMQ_initsum(l,m,2 * k);
        RMQ_initsum(m + 1,r,2 * k + 1);
        node[k].max_sum = node[2*k].max_sum;
        node[k].maxl = node[2 * k].maxl;
        node[k].maxr = node[2 * k].maxr;
        if(node[k].max_sum < node[2 * k].max_suffix + node[2 * k + 1].max_prefix){
            node[k].max_sum = node[2 * k].max_suffix + node[2 * k + 1].max_prefix;
            node[k].maxl = node[2 * k].suf;
            node[k].maxr = node[2 * k + 1].pre;
        }
        if(node[k].max_sum < node[2 * k + 1].max_sum){
            node[k].max_sum = node[2 * k + 1].max_sum;
            node[k].maxl = node[2 * k + 1].maxl;
            node[k].maxr = node[2 * k + 1].maxr;
        }
    }
   // cout << node[k].maxl << " " << node[k].maxr << " " << node[k].l << " " << node[k].r << "xx " << node[k].max_sum  << endl;

}

Node query(int l,int r,int k){
    int m = (node[k].r + node[k].l )>> 1;
    if(l <= node[k].l && r >= node[k].r){
        //cout << "shit" << node[k].suf << endl;
        return node[k];
    }
    else if(r <= m){
        return query(l,r,2 * k);

    }
    else if(l > m){
        return query(l,r,2 * k + 1);
    }
    else if(r > m && l <= m){
        Node ll = query(l,m,2 * k);
        Node rr = query(m + 1,r,2 * k + 1);
        Node res;
        res.max_sum = ll.max_sum;
        res.maxl = ll.maxl;
        res.maxr = ll.maxr;
        if(res.max_sum < ll.max_suffix + rr.max_prefix){
            res.max_sum = ll.max_suffix + rr.max_prefix;
            res.maxl = ll.suf;
            res.maxr = rr.pre;
        }
        if(res.max_sum < rr.max_sum){
            res.max_sum = rr.max_sum;
            res.maxl = rr.maxl;
            res.maxr = rr.maxr;
        }
        res.sum = ll.sum + rr.sum;
        res.max_prefix =ll.max_prefix;
        res.pre = ll.pre;
        if(res.max_prefix < ll.sum + rr.max_prefix){
            res.max_prefix = ll.sum + rr.max_prefix;
            res.pre= rr.pre;
        }
        res.max_suffix = rr.max_suffix;
        res.suf = rr.suf;
        if(res.max_suffix <= ll.max_suffix + rr.sum){
            res.max_suffix = ll.max_suffix + rr.sum;
            res.suf = ll.suf;
        }
        //cout << res.suf << " " << l << " " << r << " " << k << endl;
        return res;
    }
}

int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i = 1;i <= n;i ++){
        scanf("%d",&array[i]);
    }
    RMQ_init(1,n,1);
    RMQ_initpre(1,n,1);
    RMQ_initsuf(1,n,1);
    RMQ_initsum(1,n,1);
    for(int i = 0;i < m;i ++){
        int r,l;
        scanf("%d%d",&l,&r);
        Node k = query(l,r,1);
        printf("%d %d %d\n",k.maxl,k.maxr,k.max_sum);
    }
}                                 