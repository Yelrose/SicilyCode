
// Problem#: 1088
// Submission#: 2181906
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 10e5;
int C[maxn + 1];
int countf[maxn];
int lowbit(int k){
    return k&(-k);
}

int sum(int x){
    int ret = 0;
    while(x > 0){
        ret +=C[x];x -=lowbit(x);
    }
    return ret;
}

void add(int x,int d){
    while(x <= maxn){
        C[x] += d;x += lowbit(x);
    }
}

struct cow{
    int s;
    int e;
    int id;
}all[maxn];



bool cmp1(const cow a,const cow b){
    if(a.e == b.e)return a.s < b.s;
    else return a.e > b.e;
}


int main(){
    int N;
    while(scanf("%d",&N)!=EOF&& N!=0){
        memset(C,0,sizeof(C));
        memset(countf,0,sizeof(countf));
        for(int i = 0; i< N;i ++){
            scanf("%d%d",&all[i].s,&all[i].e);
            all[i].id = i;
        }
        sort(all,all + N,cmp1);
        int same = 0;
        for(int i =0;i < N;i ++){
            if(i > 0){
                if(all[i].s == all[i - 1].s && all[i].e == all[i - 1].e){
                    same ++;
                }
                else same = 0;
            }
            countf[all[i].id] = sum(all[i].s + 1) - same;
            add(all[i].s + 1,1);

        }
        for(int i = 0;i < N;i  ++){
            printf("%d\n",countf[i]);
        }
    }

}                                 