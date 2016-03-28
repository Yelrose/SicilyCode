
// Problem#: 10619
// Submission#: 2897983
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
#include <set>
using namespace  std;

vector<int > X[510];
vector<int > Y[510];
int matchx[510];
int matchy[510];
int vis[510];
int dfs(int t) {
    if(vis[t] == 1)return 0;
    vis[t] = 1;
    for(int i = 0;i < X[t].size();i++ ) {
        int nxt = X[t][i];
        if(matchy[nxt] == 0) {
            matchx[t] =  nxt;
            matchy[nxt] = t;
            vis[t] = 0;
            return 1;
        }
        else if(matchy[nxt] == t){
            continue;
        }
        else if(matchy[nxt] != t) {
            int ret = dfs(matchy[nxt]);
            if(ret == 1) {
                matchy[nxt] =  t;
                matchx[t] =  nxt;
                vis[t] = 0;
                return 1;
            }
        }
    }
    vis[t] = 0;
    return 0;
}
set<int > xx;
set<int > yy;

int main() {
    int N;
    scanf("%d",&N);
    for(int i = 0;i < N;i ++) {
        int a,b;
        scanf("%d%d",&a,&b);
        X[a].push_back(b);
        X[b].push_back(a);
        xx.insert(a);
        yy.insert(b);
    }
    for(int i = 1;i <= 500;i ++) {
        //memset(vis,0,sizeof(vis));
        dfs(i);
    }
    int tx = 0;
    int ty = 0;
    for(int i = 1;i <= 500;i ++) {
        if(matchx[i] > 0)tx ++;
        if(matchy[i] > 0)ty ++;
    }
    if(tx ==  xx.size() && ty == yy.size()) {
        puts("Slavko");
    }
    else puts("Mirko");
    return 0;

}                                 