
// Problem#: 9095
// Submission#: 2897994
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <map>
using namespace std;

pair<int ,int > H[100010];
int fa[100010];
int vis[100010];
int countfa = 0;
int maxf;
int main() {
    int N;
    scanf("%d",&N);
    for(int i = 1;i <= N;i ++) {
        int t;
        scanf("%d",&t);
        H[i].first = t;
        H[i].second = i;
    }
    sort(H+1,H+N + 1);

    H[0].first = -1;
    maxf = 0;
    for(int i = N;i >= 1;i --) {
        int t = H[i].second;
        //cout << "set  " << H[i].first << " at " << H[i].second << endl;
        vis[t] = 1;
        countfa ++;
        if(vis[t + 1] == 1) {
            countfa --;
        }
        if(vis[t - 1] == 1) {
            countfa --;
        }
        if(H[i - 1].first != H[i].first) {
            maxf = max(maxf,countfa);
        //    cout << countfa << endl;
        }
    }
    printf("%d\n",maxf);
    return 0;
}                                 