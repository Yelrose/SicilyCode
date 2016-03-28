
// Problem#: 8038
// Submission#: 2156390
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <map>
using namespace std;

long long dis[600][600];
long long dp[600][600];
int lowbit(int x){
    return x&(-x);
}
int n;
map<int ,int >func;
map<int ,int >funt;
int main(){
    int z = 0xffffffff;
    int zz = 1;
    for(int i = 0;i < 10;i ++){
        func[i] =z;
        funt[i] = zz;
        z = z << 1;
        zz = zz << 1;
    }
    int k;
    cin >> k;
        n = 1 << k;

        for(int i = 0;i < n;i ++){
            for(int j = 0;j < n;j ++)cin >> dis[i][j];
        }
        for(int i = 1;i < n;i ++){
       //     cout << i << " ====================" << endl;
            int ii = i - 1;
            int kk = i ^ ii;
            kk = ~kk;
            kk = lowbit(kk);
            int x = 0;
           // cout <<  "fuck  " << kk << endl;
            int y = kk;
            y = y >> 1;
            y --;
            while(kk > 1){
                kk/=2;
                x ++;
            }

            for(int j = 0;j < n;j ++){
                long long res = -1;
                int beg= func[x-1]&j^funt[x- 1];
                int end = beg|y;

                for(int jj = beg ;jj <= end;jj ++){

                    if(jj != j){
                     //   cout << "j:"<<j << " jj:" << jj << " <<y:"<<y<< endl;

                        if(res == -1){
                            res = dp[i-1][jj] + dis[jj][j];

                        }
                        else {
                            res = min(res,dp[i -1][jj] + dis[jj][j]);
                        }
                    }
                }
                dp[i][j] = res;

            }
        }
        long long res =dp[n -1][0];
        for(int i = 0;i < n;i ++){
            res = min(res,dp[n-1][i]);
        }
        cout <<res << endl;



}                                 