
// Problem#: 7145
// Submission#: 2899519
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <cstdio>
using namespace std;
int a[100000];
int b[100000];
int main() {
    int N,M,Q;
    scanf("%d%d%d",&N,&M,&Q);
    for(int i = 0;i < N;i ++) {
        scanf("%d",&a[i]);
    }
    for(int i = 0;i < M;i ++) {
        scanf("%d",&b[i]);
    }
    for(int i = 0;i < Q;i ++) {
        int r1,r2,l1,l2,k;
        scanf("%d%d%d%d%d",&l1,&r1,&l2,&r2,&k);
        //assume in A;
        int l  = l1,r = r1;
        int tot = 0;
        while(l <= r) {
            int m = (l + r) >> 1;
            tot = m - l1;
            int ll = l2;
            int rr = r2;
            while(ll < rr) {
                int mm = ((ll + rr) >> 1) + 1;
                if(b[mm] > a[m]) {
                    rr =  mm - 1;
                }
                else {
                    ll = mm;
                }
                
            }
            if(b[ll] > a[m]) ;
            else 
            tot += ll -l2 + 1;
            if(tot == k - 1) {
                r =l = m;
                break;
            }
            else if(tot > k - 1){
                r = m - 1;
            }
            else {
                l = m + 1;
            }
            
        }
        if(tot == k - 1) {
            printf("%d\n",a[l]);
            continue;
        }
        l = l2,r = r2;
        while(l <= r) {
            int m = (l + r) >> 1;
            tot = m - l2;
            int ll = l1;
            int rr = r1;
            while(ll < rr) {
                int mm =  ((ll + rr) >> 1) + 1;
                if(a[mm] > b[m]) {
                    rr =  mm - 1;
                }
                else {
                    ll = mm;
                }
                
            }
            if(a[ll] > b[m]){
                
            }
            else 
                tot += ll -l1 + 1;
            if(tot == k - 1) {
                r =l = m;
                break;
            }
            else if(tot > k - 1){
                r = m - 1;
            }
            else {
                l = m + 1;
            }

        }
        if(tot == k - 1) {
            printf("%d\n",b[l]);
            continue;
        }       
    }
    
}                                 