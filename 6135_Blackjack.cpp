
// Problem#: 6135
// Submission#: 2899781
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <cstdio>
using namespace std;
int a[300];
int main() {
    
    int N,M;
    scanf("%d%d",&N,&M);
    for(int i = 0;i  < N;i ++) {
        scanf("%d",&a[i]);
    }
    int maxf = 0;
    for(int i = 0;i < N;i ++) {
        for(int j = 0;j < N;j ++) {
            for(int k = 0;k < N;k ++) {
                if(i == j || j == k || i == k)continue;
                if(a[i] + a[j] + a[k] <= M) {
                    maxf = max(maxf,a[i] + a[j] + a[k]);
                }  
                
            }
        }
        
    }
    printf("%d\n",maxf);
}                                 