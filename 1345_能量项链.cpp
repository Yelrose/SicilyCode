
// Problem#: 1345
// Submission#: 2288641
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int p[101];
int N;
int dp[110][110];
void solve(){
    for(int i = 0;i < N;i ++){
        cin >> p[i];
    }
    memset(dp,0,sizeof(dp));
    int maxf = 0;
    for(int l = 2;l <= N;l ++){
        for(int i = 0;i < N;i ++){
            for(int j = 1;j < l;j ++){
                dp[i][l] = max(dp[i][l],dp[i][j] + dp[(i +j)%N][l- j] + p[i] * p[(i + l)%N] * p[(i + j)%N]);
                maxf = max(maxf,dp[i][l]);
            }
        }
        
    }
    cout << maxf << endl;
}


int main(){
    ios::sync_with_stdio(false);
    while(cin >> N){
        solve();
        
    }
    return 0;
}                                 