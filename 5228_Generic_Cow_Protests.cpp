
// Problem#: 5228
// Submission#: 2897618
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <cstdio>
#include <map>
using namespace std;
const long long md =  1000000009;
long long Ai[100010];           
long long Si[100010];
map<long long ,int > mapx;

long long C[100010];
int sz = 1;
int lowbit(int x) {
    return x & (-x);
}

long long sum(int x) {
    long long ret = 0;
    while(x > 0) {
        ret += C[x];
        ret %= md;
        x -= lowbit(x);
    }
    return ret;
}

void add(int x,long long  d) {
    while(x <= sz) {
        C[x] += d;
        C[x] %= md;
        x += lowbit(x);
        
    }
    
}
int main() {
    int N;
    scanf("%d",&N);
    mapx[0] = 0;
    for(int i = 1;i <= N;i ++)  {
        scanf("%lld",&Ai[i]);
        Si[i] =  Si[i - 1]  + Ai[i];
        mapx[Si[i]] = 0;
    }
    sz = 1;
    for(map<long long ,int >::iterator it = mapx.begin();it != mapx.end();it ++) {
        it -> second = sz ++;
    }
    add(mapx[0],1);
    for(int i = 1;i <= N;i ++) {
        long long t = sum(mapx[Si[i]]);
        add(mapx[Si[i]],t); 
        if(i == N){
            printf("%lld\n",t);
            
        }
        
    }
    
}                                 