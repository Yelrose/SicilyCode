
// Problem#: 4426
// Submission#: 2897675
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
using namespace std;
int N;
int ed[300010];
int ed2[300010];
int edw[300010];
int vis[300010];
pair<int ,int > query[300010];
int ans[300010];
int dfs(int t) {
    vis[t] = 1;
    if(ed2[t] == 0) {
        edw[t] = t;
        return t;
    }
    int nxt =  ed2[t];
    if(vis[nxt] == 1) {
        if(edw[nxt] == 0) {
            edw[t] = -1;
            return -1;
        }
        else {
            edw[t] = edw[nxt];
            return edw[t];
        }
    }
    else {
        edw[t] =  dfs(nxt);
    }
}

int findfa(int t) {
    if(edw[t] == t || edw[t] == -1) return edw[t];
    else return edw[t]= findfa(edw[t]);
}

int main() {
    scanf("%d",&N);
    for(int i = 1;i <= N;i ++) {
        scanf("%d",&ed[i]);
        ed2[i] =ed[i];
    }
    int M;
    scanf("%d",&M);
    for(int i = 0;i < M;i ++) {
        int a,b;
        scanf("%d%d",&a,&b);
        query[i] = pair<int ,int > (a,b);
        if(a == 2) {
            ed2[b] = 0;
        }
    }
    for(int i= 1;i <= N;i ++) {
        if(vis[i] == 0) {
            dfs(i);
        }
    }
    for(int i = M- 1;i >= 0; i --) {
        int q =  query[i].first;
        int t =  query[i].second;
        if(q == 1) {
             ans[i] = findfa(t);
        }
        else {
            ed2[t] = ed[t];
            edw[t] =  findfa(ed2[t]);
            if(edw[t] == t) {
                edw[t] = -1;
            }
        }
    }
    for(int i = 0;i < M;i ++) {
        if(query[i].first == 1) {
            if(ans[i] == -1) {
                puts("CIKLUS");
            }
            else {
                printf("%d\n",ans[i]);
            }
        }
    }
    return 0;
}                                 