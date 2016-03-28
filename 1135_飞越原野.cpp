
// Problem#: 1135
// Submission#: 2053918
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;
struct lo{
    int x,y;
    int d;
    lo(int xx,int yy , int dd):x(xx),y(yy),d(dd){

    }
    lo(){

    }
};
const int inf = 0x7fffffff;
int graph[101][101];
int dis[101][101][101];
lo path[101][101][101];
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,1,-1};
int n,m,D;
queue<lo > bfs;
bool inrange(int x,int y){
    return (0<=x && x < n && 0 <= y && y < m);
}


void printp(){
    cout << n - 1 << "x" << m - 1 << "d" << D-1 << endl;
    lo t = path[n - 1][m - 1][D-1];
    while(!(t.x == 0 && t.y ==0 && t.d == 0)){
        cout << "<-" << t.x << "x" << t.y << "d"<<t.d << endl;
        t = path[t.x][t.y][t.d];
    }
}
int main(){

    for(int i = 0;i < 101;i ++){
        for(int j  = 0;j < 101;j ++){
            for(int k = 0;k < 101;k ++){
                dis[i][j][k] = inf;
            }
        }
    }
    cin >> n >> m >> D;
    for(int i = 0;i < n;i ++){
        for(int j = 0;j < m;j ++){
            char ch;
            cin >> ch;
            graph[i][j] = (ch == 'P')?1:0;
        }
    }
    dis[0][0][0] = 0;
     bfs.push(lo(0,0,0));
    while(!bfs.empty()){
        lo t = bfs.front();
        int x = t.x;
        int y = t.y;
        int d = t.d;
        bfs.pop();
        for(int i = 0;i < 4;i ++){

                int dd = t.d;
                int xx = t.x + dx[i];
                int yy = t.y + dy[i];
                if(!inrange(xx,yy))continue;
                if(graph[xx][yy] == 0)continue;
                if(dis[xx][yy][dd] > dis[x][y][d] + 1){
                    dis[xx][yy][dd] = dis[x][y][d] + 1;
                    path[xx][yy][dd] = lo(x,y,d);
                    bfs.push(lo(xx,yy,dd));
                }

        }
        for(int i = 0;i < 4;i ++){


            for(int j = d + 1;j <= D;j ++){
                int xx = t.x + dx[i] * (j - d);
                int yy = t.y + dy[i] * (j - d);
                if(!inrange(xx,yy))continue;
                if(graph[xx][yy] == 0)continue;
                int dd = j;
                if(dis[xx][yy][dd] > dis[x][y][d] + 1){
                    dis[xx][yy][dd] = dis[x][y][d] + 1;
                    path[xx][yy][dd] = lo(x,y,d);
                    bfs.push(lo(xx,yy,dd));
                }
            }
        }
    }
    int minf = inf;
    for(int i = 0;i <= D;i ++){
        if(dis[n- 1][m - 1][i] < minf)minf = dis[n - 1][m - 1][i];
    }

    if(minf == inf)cout << "impossible" << endl;
    else {
      //  printp();
        cout << minf << endl;
    }
}                                 