
// Problem#: 1350
// Submission#: 1841875
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

int nxt[1000001];
int vis[1000001];
int rudu[1000001];
queue<int >bfs;
int main(){
    int n;
    int cir;
    while(cin >> n){
        cir = 0;
        memset(rudu,0,sizeof(rudu));
        for(int i = 1;i <= n;i ++){
            cin >> nxt[i];
            rudu[nxt[i]] ++;
        }


        for(int i = 1;i <= n;i ++){
            if(rudu[i] == 0){
                bfs.push(i);
            }
        }memset(vis,0,sizeof(vis));
        while(!bfs.empty()){
            int tmp = bfs.front();bfs.pop();
            //cout << tmp << endl;
            vis[tmp] = 1;
            if( -- rudu[nxt[tmp]] == 0)bfs.push(nxt[tmp]);

        }


        for(int i = 1;i <= n;i ++){
            if(!vis[i]){
                bfs.push(i);
                while(!bfs.empty()){
                    int k = bfs.front();
                    bfs.pop();
                    vis[k] = 1;
                    if(vis[nxt[k]] == 1){
                        cir ++;
                    }
                    else {
                        bfs.push(nxt[k]);
                    }
                }
            }
        }
        cout << cir << endl;
    }
}                                 