
// Problem#: 7144
// Submission#: 1838574
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <cstdio>
using namespace std;
int tran[1000];
int main(){
    int T;
    scanf("%d",&T);
    while(T --){
        int n;
        scanf("%d",&n);
        for(int i =0;i < n;i ++){
            scanf("%d",&tran[i]);
        }
        int countf = 0;
        for(int i = 0;i < n;i ++){
            for(int j = 0;j < i;j ++){
                for(int k = 0;k < j;k ++){
                    if(tran[i] + tran[j] <= tran[k] || tran[i] + tran[k] <= tran[j] || tran[j] + tran[k] <= tran[i]){
                        
                    }
                    else countf ++;
                
                }
            }
        }
        printf("%d\n",countf);
    }
}                                 