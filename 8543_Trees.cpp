
// Problem#: 8543
// Submission#: 2900835
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

vector<int > edge[550];
typedef pair<int ,int > record;
queue<record > bfs;
int vis[550];
int main() {
    int n,m;
    int ca = 1;
    while(~scanf("%d%d",&n,&m)) {
        if(n == 0 && m == 0)break;
        for(int i = 1;i <= n;i ++)edge[i].clear();
        for(int i = 0;i < m;i ++) {
            int a,b;
            scanf("%d%d",&a,&b);
            edge[a].push_back(b);
            edge[b].push_back(a);
        }
        int countf = 0;
        memset(vis,0,sizeof(vis));
        for(int i = 1;i <= n;i ++) {
            if(vis[i] == 0) {
                bfs.push(record(i,0));
                vis[i] = 1;
                bool tree =true;
                while(!bfs.empty()) {
                    record tmp = bfs.front();
                    bfs.pop();
                    int fa = tmp.second;
                    int t = tmp.first;
                    for(int i = 0;i < edge[t].size();i ++) {
                        int nxt = edge[t][i];
                        if(vis[nxt] && nxt == fa)continue;
                        if(vis[nxt])tree = false;
                        else {
                            vis[nxt] = true;
                            bfs.push(record(nxt,t));
                        }
                    }
                }
                if(tree)countf ++;
            }
        }
        if(countf == 0) {
            cout << "Case "<<ca << ": No trees." << endl;
        }
        else if(countf == 1) {
            cout << "Case "<<ca<<": There is one tree." << endl;
        }
        else {
            cout << "Case "<<ca<<": A forest of "<<countf << " trees." << endl;
        }
        ca ++;
    }
}                                 