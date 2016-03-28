
// Problem#: 9169
// Submission#: 2363533
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
/*************************************************************************
    > File Name: a.cpp
    > Author: Yelrose
    > Mail: 270018958@qq.com 
    > Created Time: 2013年10月28日 星期一 14时54分27秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <stack>
using namespace std;

const double pi = acos(-1);
const int MAX_INT = 0x7fffffff;
const double EPS = 1e-4;

int a[1500];
int b[1500];
int nxt[1500];
long long K;
int N,M;

void pow(long long t){
    memset(b,0,sizeof(b));
    b[1] = 1;
    while(t > 0){
        if(t & 1 == 1){
            memset(nxt,0,sizeof(nxt));
            for(int i = 0;i < M;i ++){
                for(int j = 0;j < M;j ++){
                    if(b[i] && a[j]){
                        nxt[(i * j)%M] = 1;
                    }
                }
            }
            for(int i = 0;i < M;i ++){
                b[i] = nxt[i];
            }

        }
        memset(nxt,0,sizeof(nxt));
        for(int i = 0;i < M;i ++){
            for(int j = 0;j < M;j ++){
                if(a[i]&& a[j]){
                    nxt[(i*j)%M]= 1;
                }

            }
        }
        for(int i  = 0;i < M;i ++){
            a[i] = nxt[i];
        }

        t/=2;
    }
}


int main() {
    ios::sync_with_stdio(0);
    cin >> K >> M >> N;
    for(int i = 0;i < N;i ++){
        int t;
        cin >> t;
        a[t] = 1;
    }
    pow(K);
    for(int i = 0;i < M;i ++){
        if(b[i])cout << i << " ";
    }
    cout << endl;
    return 0;
}                                 