
// Problem#: 10606
// Submission#: 2776791
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
// Problem#: 10606
// Submission#: 2776690
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <cstdio>
#include <stack>
#include <queue>
#include <vector>
#define MAXN 1000010
#define md 1000000007
using namespace std;
int N,K;
int linkf[MAXN];
vector<int > backlink[MAXN];
vector<int > group[MAXN];
int gs = 0;
int vis[MAXN];
int vis2[MAXN];
stack<int > dfs_s;
void dfs(int t) {
    int k = t;
    while(vis[k] == 0) {
        dfs_s.push(k);
        vis[k] = 1;
        k = linkf[k];
    }
    bool findf = false;
    while(!dfs_s.empty()) {
        int tmp = dfs_s.top();
        dfs_s.pop();
        if(findf == false) {
            group[gs].push_back(tmp);
        }
        if(tmp ==  k) {
            findf = true;
        }


    }
    if(!findf) {
        group[gs].clear();
    }
    else {
        gs ++;
    }
}



long long dp[MAXN][2];

void initDP(int group_size) {
    dp[1][0] = K;
    dp[1][1] = 0;
    for(int i = 2;i <= group_size;i ++) {
        dp[i][0] = (dp[i - 1][1]) % md;
        dp[i][1] = ((dp[i - 1][0] * (K - 1)) % md + (dp[i - 1][1] * (K - 2)) % md) % md;
    }
}

long long dfs2(int t) {
    long long s = 1;
    for(int i = 0;i < backlink[t].size();i ++) {
        int nxt = backlink[t][i];
        if(vis2[nxt] == 0) {
            vis2[nxt] = 1;
            s *= ((K - 1) * dfs2(nxt)) % md;
            s %= md;
        }
    }
    return s;
}


int main() {
    scanf("%d%d",&N,&K);
    for(int i = 1;i <= N;i ++) {
        scanf("%d",&linkf[i]);
        backlink[linkf[i]].push_back(i);
    }
    for(int i = 1 ;i <= N;i ++) {
        if(vis[i] == 0) {
            dfs(i);
        }
    }
    int maxgs = 0;
    for(int i = 0;i < gs;i ++) {
        maxgs = max(maxgs,(int )group[i].size());
    }
    initDP(maxgs);
    long long countf = 1;
    for(int i = 0;i < gs;i ++) {
        long long s = K;
        if(group[i].size() > 1) s = dp[group[i].size()][1];
        for(int j = 0;j < group[i].size();j ++) {
            vis2[group[i][j]] = 1;
        }
        for(int j = 0;j < group[i].size();j ++) {
            s *= dfs2(group[i][j]);
            s %= md;
        }
        countf *= s;
        countf %= md;
    }
    printf("%lld\n",countf);
    return 0;
}                                 