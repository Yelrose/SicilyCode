
// Problem#: 4423
// Submission#: 1791714
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int countf[65];

int main(){
    int T;
    scanf("%d",&T);
    while(T --){
        long long  n;
        scanf("%lld",&n);
        memset(countf,0,sizeof(countf));
        for(int i = 0;i < n;i ++){
                int k;
                scanf("%d",&k);
                int counta = 0;
                while(k > 0){
                    int a = k % 2;
                    if(a == 1)countf[counta] ++;
                    k /= 2;
                    counta ++;
                }
        }
        long long s = 0;
        long long capa = 1;
        for(int i = 0;i < 65;i ++){
            s += (((n - countf[i]) * countf[i]) * capa);
            capa *= 2;
        }
        printf("%lld\n",s);
    }
}                                 