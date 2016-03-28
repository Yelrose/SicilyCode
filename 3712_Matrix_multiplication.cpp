
// Problem#: 3712
// Submission#: 2897638
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int n;
int A[10][10];
int B[10][10];
int C[10][10];

void calc() {
    memset(C,0,sizeof(C));
    for(int k = 0;k < n;k ++)
        for(int i = 0;i < n;i ++) {
            for(int j= 0;j < n;j ++) {
                C[i][j] += A[i][k] * B[k][j];   
            }
        }
    
}

int main() {
    while(~scanf("%d",&n)) {
        for(int i = 0;i < n;i ++) {
            for(int j = 0;j < n;j ++) {
                scanf("%d",&A[i][j]);
            }
        }
        for(int i = 0;i < n;i ++){
            for(int j = 0;j < n;j ++) {
                scanf("%d",&B[i][j]);
            }
        }
        calc();
        for(int i = 0;i <  n;i ++) {
            for(int j = 0;j < n;j ++) {
                if(j > 0)printf(" ");
                printf("%d",C[i][j]);
            }
            puts("");
        }
    }
}                                 