
// Problem#: 5227
// Submission#: 2899756
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

char word[200][5];
long long md = 97654321;
long long dp[550][260][52];
int U,L,P;
int len;
int main() {
    scanf("%d%d%d",&U,&L,&P);
    for(int i = 0;i < P;i ++) {
        scanf("%s",word[i]);
    }   
    len = U + L;
    for(int i = 0;i < 26;i ++)
        dp[1][0][i] = 1;
    for(int i = 26;i < 52;i ++) {
        dp[1][1][i] = 1;
    }
    for(int i = 2;i <= len;i ++) {
    //  cout << i<< "-=----------------------" << endl;
        for(int j = 0;j <= min(i,U);j ++) {
             for(int k =0 ;k < P;k ++) {
                if(word[k][1] >= 'A' && word[k][1] <= 'Z') {
                    int in = word[k][1] - 'A' + 26;
                    if(j == 0)continue;
                    int in2 ;
                    if(word[k][0]  >= 'A' && word[k][0] <= 'Z')in2 = word[k][0] - 'A' + 26;
                    else in2 = word[k][0] - 'a';
                    dp[i][j][in] +=  dp[i - 1][j - 1][in2]; 
                    dp[i][j][in] %= md; 
                //  cout << word[k] << " " << dp[i][j][in] << " " << i << " " << j << " " << in << " " << in2<< endl;
                    
                }
                else {
                    int in = word[k][1] - 'a';
                    if(j == i)continue;
                    int in2 ;
                    if(word[k][0]  >= 'A' && word[k][0] <= 'Z')in2 = word[k][0] - 'A' + 26;
                    else in2 = word[k][0] - 'a';
                    dp[i][j][in] +=  dp[i - 1][j][in2];
                    dp[i][j][in] %= md; 
                //  cout << word[k] << " " << dp[i][j][in] << " " << i << " " << j << " " << in << " " << in2 << endl;
                    
                }
                
             }
            
        }
    }
    long long sumf = 0;
    for(int i = 0;i < 54;i ++) {
        sumf += dp[U+L][U][i];
        sumf %= md;
        
    }
    printf("%lld\n",sumf);
}                                 