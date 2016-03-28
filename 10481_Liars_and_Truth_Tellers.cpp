
// Problem#: 10481
// Submission#: 2775596
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <cstring>
using namespace std;
typedef pair<int ,int > edge;

int N;
vector<edge > linkf[1010];
int vis[1010];
int dis[1010];

bool dfs(int t) {
    vis[t] = 1;
    for(int i = 0;i < linkf[t].size();i ++){
        int nxt = linkf[t][i].first;
        int ty = linkf[t][i].second;
        if(vis[nxt] == 1){
            if(((dis[t] + ty) % 2) != (dis[nxt] % 2)){
                return false;
            }

        }
        else {
            dis[nxt] = dis[t] + ty;
            if(!dfs(nxt)){
                return false;
            }
        }
    }
    return true;

}

int main() {
    int M;
    scanf("%d%d",&N,&M);
    for(int i = 1 ;i <= M;i ++ ) {
        int a,b;char c;
        cin >> a >> b >> c;
        if(c == 'L'){
            linkf[a].push_back(edge(b,1));
            linkf[b].push_back(edge(a,1));
        }
        else {
            linkf[a].push_back(edge(b,0));
            linkf[b].push_back(edge(a,0));
        }
        memset(vis,0,sizeof(vis));
        memset(dis,0,sizeof(dis));

        if(!dfs(a)){
            printf("%d\n",i - 1);
            return 0;
        }
    }
    printf("%d\n",M);
    return 0;


}                                 