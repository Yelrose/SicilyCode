
// Problem#: 4425
// Submission#: 2897664
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <cstdio>
using namespace std;
int n;
int a[200000];
int tmp[200000];
long long  mergesort(int s,int e) {
    
    if(s == e)return 0;
    int m = (s + e) >> 1;
    long long  countf = 0;
    
    countf += mergesort(s,m);
    countf += mergesort(m+1,e);
    int i = s;
    int j = m + 1;
    int sz = 0;
    while(1) {
        if(i > m) {
            while(j <= e) {
                tmp[sz ++] = a[j];
                j ++;
            }
            break;
            
        }
        else if(j > e) {
            while( i <=  m ) {
                tmp[sz ++] = a[i];
                i ++; 
            }
            break;
        }
        if(a[i] < a[j]) {
            tmp[sz ++] =  a[i];
            i ++;
        }
        else {
            tmp[sz ++] = a[j];
            countf += m - i + 1;
            j ++;
        }
        
    }
    for(int i = s;i <= e;i ++) {
        a[i] = tmp[i - s];
        
    }
    return countf;
}

int main() {
    int T;
    scanf("%d",&T);
    while(T --) {
        long long  countf = 0;
        scanf("%d",&n); 
        for(int i = 0;i < n;i ++) scanf("%d",&a[i]);
        int i = 0;
        int j = 0;
        while(i < n) {
            j = i;
            while(j < n - 1 && a[j] > a[j + 1 ]) {
                j ++;
            }
            int l = i;
            int r = j;
            if(l < r) {
                countf ++;
            }
            while(l < r) {
                swap(a[l],a[r]);
                l ++;
                r --;
            }  
            i = j + 1;
            
        }
    
        countf +=  mergesort(0,n - 1);

        
        printf("%lld\n",countf);    
    
    }
    return 0;
}                                 