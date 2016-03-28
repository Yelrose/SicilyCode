
// Problem#: 10399
// Submission#: 2776344
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

double dp[2010];
int pos[2010];

int main() {
    int N,A,B;
    scanf("%d%d%d",&N,&A,&B);
    for(int i = 0;i < N;i ++) {
        scanf("%d",&pos[i]);
    }
    sort(pos,pos + N);
    for(int i = 0;i < N;i ++) {
        dp[i] = A + 1.0* B * (pos[i] - pos[0]) / 2.0;
        for(int k = 1;k <= i;k ++) {
            dp[i] = min(dp[i],dp[k - 1] + A +  (pos[i] - pos[k]) / 2.0 * B );
        }
    }
    double ans = dp[N - 1];
    int one,two;

    one=int(ans+0.4);

    two= int(ans+0.6) > int(ans+0.4) ? 5 : 0;
    if(two) printf("%d.%d\n",one,two);
    else printf("%d\n",one);
    return 0;
}                                 