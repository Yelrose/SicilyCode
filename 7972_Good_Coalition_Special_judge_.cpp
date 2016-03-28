
// Problem#: 7972
// Submission#: 2180315
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iomanip>
using namespace  std;

double PofWin[150];
int countfman[150];
double dp[151];
int vis[151];
double maxf;
int main(){
    int T;
    ios::sync_with_stdio(0);
    cin >> T;
    while(T --){
        int n;
        cin >> n;
        for(int i = 0; i < n ;i ++){
            double tmp;int c;
            cin >> c >> tmp;
            countfman[i] =c;
            PofWin[i] = tmp/100;
        }
        memset(vis,0,sizeof(vis));
        vis[0] = 1;
        dp[0] = 1;
        maxf = 0;
        for(int i = 0;i < n;i ++){
            for(int j = 150;j >= countfman[i];j --){
                if(!vis[j - countfman[i]])continue;
                double k = dp[j - countfman[i]] *  PofWin[i];
                if(vis[j]==0){
                    vis[j] = 1;
                    dp[j] = k;
                }
                else if(dp[j] < k){
                    dp[j] = k;
                }
                if(j >= 76 && vis[j] == 1){
                    if(dp[j] > maxf)maxf =  dp[j];
                }

            }
        }
        cout<<setprecision(6) << fixed <<  maxf * 100 << endl;
    }

}                                 