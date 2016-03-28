
// Problem#: 6505
// Submission#: 1701801
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
long long  can[100000];
long long  color[100000];
int n,m;
int main(){

    scanf("%d%d",&n,&m);
    for(int i = 0;i < n;i ++){
        scanf("%lld",&can[i]);
    }
    for(int i = 0;i < m;i ++){
        scanf("%lld",&color[i]);
    }
    sort(can,can + n);
    sort(color,color + m);
    long long cost = 0;
    int a = 0;
    int b = 0;
    while(a < n && b < m){
        if(color[b] == 0) b ++;
        else if(can[a] >= color[b]){
            cost += (can[a] - color[b]);
          
            b ++;

        }
        else a++;
    }
 
    printf("%lld\n",cost);
}                                 