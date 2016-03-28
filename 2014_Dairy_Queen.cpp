
// Problem#: 2014
// Submission#: 1812717
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
using namespace std;
int dp[1000];
int main(){
        int n,m;
        cin >> n >> m;
        for(int i = 0;i < m;i ++){
            int tmp;
            cin >> tmp;

            for(int ii = n;ii >= 1;ii --){
                for(int j = 1;j * tmp < ii;j ++){
                    dp[ii] += dp[ii - j * tmp];
                }
            }

             for(int j = 1;j * tmp <= n;j ++){
                dp[j * tmp] += 1;
            }

        }


        cout << dp[n] << endl;
}                                 