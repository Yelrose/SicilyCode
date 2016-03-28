
// Problem#: 7148
// Submission#: 2899537
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <queue>
#include <map>
#include <vector>
#include <cstring>
using namespace std;
typedef  pair<int ,int > lo;
char block[500][500];
int vis[500][500];
queue<lo > bfs;
int dx[8] =  {-1,-1,-1,0,0,1,1,1};
int dy[8] = {-1,0,1,-1,1,-1,0,1};
int main() {
    int N,M;
    while(cin >> N >> M) {
        memset(vis,0,sizeof(vis));
        for(int i =  0;i  < N;i ++ ) {
            for(int j = 0;j < M;j ++) {
                cin >> block[i][j];
            }
            
        }
        int count_r = 0;
        int count_t = 0;
        int count_c = 0;
        int v = 1;
        for(int i = 0;i < N;i ++) {
            for(int j = 0;j < M;j ++) {
                if(block[i][j] == '#' && vis[i][j] == 0) {
                    vis[i][j] = v;
                    bfs.push(lo(i,j));
                    int countc = 0;
                    int xmax,xmin,ymax,ymin;
                    xmax = xmin = i;
                    ymax = ymin = j;
                    while(!bfs.empty()) {
                        lo tmp = bfs.front();
                        countc ++;
                        bfs.pop();
                        int x = tmp.first;
                        int y = tmp.second;
                        xmax = max(x,xmax);
                        xmin = min(x,xmin);
                        ymax = max(y,ymax);
                        ymin = min(y,ymin);
                        for(int d = 0;d < 8; d++) {
                            int xx =  x + dx[d];
                            int yy =  y  + dy[d];
                            if(xx < 0 || xx>= N || yy < 0 || yy >= M ) continue;
                            if(block[xx][yy] == '.')continue;
                            if(vis[xx][yy] == 0) {
                                vis[xx][yy] = v;
                                bfs.push(lo(xx,yy));
                            }
                        }
                    }
                    //cout << xmax << " " << xmin << " " << ymax << " "<< ymin << endl;
                    int area =  (xmax - xmin + 1) * (ymax -ymin + 1);
                    double t = countc*1.0 / area;
                    if(t >= 0.85)count_r ++;
                    else if(t >= 0.6)count_c++;
                    else count_t ++;
                
                    
                }
                
            }   
        
        }
        cout << "Rectangle: " << count_r << endl;
        cout << "Circle: " << count_c << endl;
        cout << "Triangle: " << count_t << endl;
        cout << endl;
    }    
}                                 