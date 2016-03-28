
// Problem#: 1010
// Submission#: 2899801
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
char a[300];
char b[300];
char c[410];
int dp[210][210];
int main() {
    int T;
    scanf("%d",&T);
    int ca = 1;
    while(T -- ) {
        scanf("%s%s%s",a,b,c);
        memset(dp,0,sizeof(dp));
        dp[0][0] = 1;
        int len = strlen(c);
        int lena = strlen(a);
        int lenb = strlen(b);
        for(int i = 1;i <= len;i ++) {
            for(int j = 0;j <= min(i,lena);j ++) {
                if((i - j) <= lenb) {
                
                    if(j > 0) {
                        if(c[i - 1] ==  a[j - 1]) {
                            dp[j][i - j] = max(dp[j][i - j],dp[j - 1][i - j]);
                        }
                    }
                    if(i - j > 0) {
                        if(c[i - 1] == b[i - j - 1]) {
                            dp[j][i - j] = max(dp[j][i - j],dp[j][i - j - 1]);
                        }
                    }
                
                    //cout << j << " " << i -j  << " dp[i][j] " << dp[j][i - j] << endl;
                }
            }
            
        }
        //cout << dp[lena][lenb] << endl;
        if(dp[lena][lenb] > 0) {
            printf("Data set %d: yes\n",ca);
        }
        else {
            
            printf("Data set %d: no\n",ca);
        }
        ca ++;
    }
}                                 