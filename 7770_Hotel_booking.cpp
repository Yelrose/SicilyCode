
// Problem#: 7770
// Submission#: 2059967
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;
typedef pair<int ,int > edge;
int n;
int m;
int hotel;
int hot[100];
vector<edge > road[10001];
int livehotel[10001];
int dis[10001];
int inq[10001];
int vis[10001];
queue<int >bfs;
queue<int >bfs2;

void init(){
    for(int i = 1;i <= n;i ++){
        road[i].clear();

    }
    memset(vis,0,sizeof(vis));


}
void solve(){
    init();
    scanf("%d",&hotel);
    for(int i = 0;i < hotel;i ++){
        scanf("%d",&hot[i]);

    }
    scanf("%d",&m);
    for(int i = 0;i < m;i ++){
        int a,b,cost;
        scanf("%d%d%d",&a,&b,&cost);
        road[a].push_back(edge(b,cost));
        road[b].push_back(edge(a,cost));
    }
    bfs.push(1);
    vis[1] = 1;
    while(!bfs.empty()){

        int t = bfs.front();
       // cout << t << " " << livehotel[t] << endl;
        bfs.pop();
        memset(dis,-1,sizeof(dis));
        dis[t] = 0;
        inq[t] = 1;
        bfs2.push(t);
        while(!bfs2.empty()){
            int k = bfs2.front();
            inq[k] = 0;
            bfs2.pop();
            for(int i = 0;i < road[k].size();i ++){
                int des = road[k][i].first;
                int cost =road[k][i].second;
                if(dis[des] == -1 || dis[des] > dis[k] + cost){
                    dis[des] = dis[k] + cost;
                    if(!inq[des]){
                        inq[des] = 1;
                        bfs2.push(des);
                    }
                }
            }
        }
        if(dis[n] != -1&&dis[n] <= 600 && vis[n] == 0){

            livehotel[n] = livehotel[t];
           // cout << "find" << livehotel[n] << " " << n << " " << t << endl;
            vis[n] = 1;
        }
        for(int i = 0;i < hotel;i ++){
            int h = hot[i];
            if(dis[h] != -1 &&dis[h]<= 600 && vis[h] == 0){
                livehotel[h] = livehotel[t] + 1;
                vis[h] = 1;
                bfs.push(h);
            }
        }

    }
    if(vis[n] == 0)printf("-1\n");
    else printf("%d\n",livehotel[n]);

}



int main(){
    while(scanf("%d",&n) && n!=0){
            solve();
    }

    return 0;

}                                 