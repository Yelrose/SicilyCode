
// Problem#: 1199
// Submission#: 2858405
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
    
int eular(int n)
{
    int ret=1,i;
    for(i=2;i*i<=n;i++){
        if(n%i==0)
        {
            n/=i,ret*=i-1;
            while(n%i==0)
            n/=i,ret*=i;
        }
    }
    if(n>1)
        ret*=n-1;
    return ret;
}
    
int main() {
    int T;
    
    scanf("%d",&T);
    while(T --) {
        int N,M;
        scanf("%d%d",&N,&M);

        int ans = 0;
        for(int i = 1;i * i <= N ;i ++) {
            if(N % i == 0) {
                if(i >= M)
                    ans += eular(N / i);
                
                if(i * i != N && N / i >= M) {
                    ans += eular(i);
                        
                }
                
                    
            }
                
        }
        printf("%d\n",ans);
            
        
        
    }
    return 0;
}                                 