
// Problem#: 4876
// Submission#: 1791382
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
using namespace std;

int wage[1000001];
int inwage[500001];
int n,q;
int intim[500001];
int outim[500001];
vector<int >child[500001];
int tim;
int lowbit(int k){
    return k & (-k);
}

int sumf(int k){
    int s = 0;
    while(k > 0){
        s += wage[k];
        k -= lowbit(k);
    }
    return s;
}

int addf(int pos,int k){
    while(pos <= 2 * n){
        wage[pos] += k;
        pos += lowbit(pos);
    }
}

void dfs(int k){
    intim[k] = tim;
    tim ++;
    for(int i = 0;i < child[k].size();i ++){
        dfs(child[k][i]);
    }
    outim[k] = tim;
    tim ++;

}

void p(){
    int a,b;
    scanf("%d%d",&a,&b);
    addf(intim[a],b);
    addf(outim[a],-b);
}

void u(){
    int k;
    scanf("%d",&k);
    printf("%d\n",sumf(intim[k] - 1) + inwage[k]);
}

int main(){
    scanf("%d%d",&n,&q);
    scanf("%d",&inwage[1]);
    for(int i = 2;i <= n;i ++){
        int fa;
        scanf("%d%d",&inwage[i],&fa);
        child[fa].push_back(i);
    }
    tim = 1;
    dfs(1);
    for(int i = 0;i < q;i ++){
        char k;
        getchar();
        scanf("%c",&k);
        if(k == 'p')p();
        else u();
    }
}                                 