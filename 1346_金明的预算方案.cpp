
// Problem#: 1346
// Submission#: 2122220
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <cstdlib>
using namespace std;
int N,m;
int P[70];
int V[70];
int fa[70];
int dp[32020];
int dp2[32020];
vector<int > child[70];
int main(){
    while(scanf("%d%d",&N,&m)!= EOF){
        memset(dp,0,sizeof(dp));
        for(int i = 0 ;i < m;i ++){
            child[i].clear();
            scanf("%d%d%d",&V[i],&P[i],&fa[i]);
        }
        for(int i = 0; i < m;i ++){
            if(fa[i] > 0)child[fa[i]-1].push_back(i);
        }
        int maxf = 0;
        for(int i = 0 ;i < m;i ++){
            memset(dp2,0,sizeof(dp2));
            if(fa[i] == 0) {

                for(int j = N;j >= V[i];j --){
                    dp2[j] = dp[j - V[i]] + V[i] * P[i];
                }
                for(int j = 0;j < child[i].size();j ++){
                    int c = child[i][j];
                    for(int k = N;k >= V[i] + V[c];k --){
                        dp2[k] = max(dp2[k],dp2[k - V[c]] + V[c] * P[c]);
                    }
                }
                for(int i = 0;i <= N;i ++){

                    dp[i] = max(dp[i],dp2[i]);
                    maxf = max(maxf,dp[i]);
                }
            }

        }
        printf("%d\n",maxf);
    }

    return 0;
}                                 