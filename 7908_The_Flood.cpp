
// Problem#: 7908
// Submission#: 2046871
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
#define rep(i,n) for(int i = 0;i < n;i ++)
using namespace std;
typedef pair<int ,int > lo;
int n,m;
int grid[100][100];
int vis[100][100];
int dx[4] = {0,1,-1,0};
int dy[4] = {-1,0,0,1};
queue<lo > bfs;
bool inrange(int x,int y){
    return (x < n && x >= 0 && y < m && y >= 0);
}
int flood(int height){
        memset(vis,0,sizeof(vis));
        rep(i,n){
            if(grid[i][0] - height <= 0){
                bfs.push(lo(i,0));
                vis[i][0] = 1;
            }
            if(grid[i][m - 1] - height <= 0){
                bfs.push(lo(i,m - 1));
                vis[i][m - 1]= 1;
            }
        }
        rep(i,m){
            if(grid[0][i] <= height){
                bfs.push(lo(0,i));
                vis[0][i] = 1;
            }
            if(grid[n - 1][i] <= height){
                bfs.push(lo(n - 1,i));
                vis[n - 1][i] = 1;
            }
        }
        while(!bfs.empty()){
            lo t = bfs.front();
            bfs.pop();
            int x = t.first;
            int y = t.second;
            for(int i = 0; i < 4;i ++){
                int xx = x + dx[i];
                int yy = y + dy[i];
                if(!inrange(xx,yy))continue;
                if(vis[xx][yy] == 0 && grid[xx][yy] <=height ){
                    vis[xx][yy] = 1;
                    bfs.push(lo(xx,yy));
                }
             }
        }
        int part=  0;
        for(int i = 0;i < n;i ++){
            for(int j = 0;j < m;j ++){
                if(vis[i][j])continue;
                vis[i][j] = 1;
                part ++;
                bfs.push(lo(i,j));
                while(!bfs.empty()){
                    lo t = bfs.front();
                    bfs.pop();
                    int x = t.first;
                    int y = t.second;
                    rep(d,4){
                        int xx = x + dx[d];
                        int yy = y + dy[d];
                        if(!inrange(xx,yy))continue;
                        if(vis[xx][yy] == 0){
                            vis[xx][yy] = 1;
                            bfs.push(lo(xx,yy));
                        }
                    }
                }
            }
        }
        return part;
}




int main(){
    int ca = 1;
    while(scanf("%d%d",&n,&m) && !(n == 0 && m == 0)){
        int minf = 1001;
        int maxf = -1;
        for(int i = 0;i < n;i ++){
            for(int j = 0;j < m;j ++){
                scanf("%d",&grid[i][j]);
                if(grid[i][j] > maxf) maxf = grid[i][j];
                if(grid[i][j] < minf)minf = grid[i][j];
            }
        }
        int part;
        int mid;
        for(int i = minf;i <= maxf;i ++){
            mid =i;
            part = flood(i);
            if(part >= 2)break;
        }
        if(part >= 2) printf("Case %d: Island splits when ocean rises %d feet.\n",ca,mid);
        else printf("Case %d: Island never splits.\n",ca);
        ca ++;
    }

}                                 