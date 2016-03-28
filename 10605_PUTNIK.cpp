
// Problem#: 10605
// Submission#: 2776433
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <cstdio>
using namespace std;



int dp[1510][1510];
int matrix[1510][1510];

int vis[1510][1510];
int dps(int i,int j) {
    //cout << i << " " << j << endl;
    if(i < j){
        swap(i,j);
    }
    if(vis[i][j]) {
        return dp[i][j];
    }
    else {
        vis[i][j] = 1;
        if(i == j) {
            dp[i][j] = 0;
        }
        else if(i == j + 1) {
            bool first = 0;
            for(int k = 0;k < j;k ++) {
                if(first ++) {
                    dp[i][j] = min(dp[i][j],dps(j,k) + matrix[k][i]);
                }
                else {
                    dp[i][j] = dps(j,k) + matrix[k][i];
                }
            }
        }
        else {
            dp[i][j] = dps(i - 1,j) + matrix[i - 1][i];
        }
        return dp[i][j];
    }
}

int main() {
    int N;
    scanf("%d",&N);
    for(int i = 0;i < N;i ++){
        for(int j = 0;j < N;j ++){
            scanf("%d",&matrix[i][j]);
        }
    }
    vis[1][0] = 1;
    dp[1][0] = matrix[1][0];
    for(int i = 0;i <  N - 1;i ++) {
        dps(i+ 1,i);
    }
    for(int i = 0;i < N;i ++) {
        for(int j = 0;j <  i;j ++) {
            dps(i,j);
        }
    }

    int minf = dps(N - 1,0);
    for(int i = 0;i < N - 1;i ++){
        minf = min(minf,dps(N-1,i));
    }
    printf("%d\n",minf);
}                                 