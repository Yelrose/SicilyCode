
// Problem#: 10360
// Submission#: 2746276
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <cstdio>
#include <algorithm>
using namespace std;

long long countf[2000010];


int main(){
    int N;
    scanf("%d",&N);
    long long maxf = 0;
    for(int i = 0;i < N;i ++){
        int t;
        scanf("%d",&t);
        for(int j = 1;j * j <= t;j ++){
            if(t % j == 0){
                countf[j] ++;
                if(countf[j] > 1){
                    maxf = max(maxf,countf[j] * j);
                }
                if(j* j != t){
                    countf[t/j] ++;
                    if(countf[t/j] > 1){
                        maxf = max(maxf,countf[t/j] * (t/j));
                    }
                }
            }
        }

    }
    printf("%lld\n",maxf);
}                                 