
// Problem#: 1034
// Submission#: 1841171
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
// Problem#: 6652
// Submission#: 1729761
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
// Problem#: 3652
// Submission#: 1213118
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

int visit[101];
int V_E[101][101];
int fa[101];
int lvl[101];
int widetim[101];
queue<int > all;
void bfs(int n,int m){
    memset(visit,0,sizeof(visit));
    memset(V_E,0,sizeof(V_E));
    memset(fa,0,sizeof(fa));
    memset(lvl,0,sizeof(lvl));
    memset(widetim,0,sizeof(widetim));
    //cin >> n >> m;
    for(int i = 0;i < m;i ++){
        int a,b;
        cin >> a >> b;
        V_E[a][b] = 1;
        fa[b] = 1;
    }
    for(int i = 1;i <= n;i ++){
        //cout << " x" << endl;
        if(fa[i] == 0){
            lvl[i] = 0;
            all.push(i);
            while(!all.empty()){
                //cout << "X" << endl;
                int k = all.front();
                visit[k] = 1;
                all.pop();
                for(int j = 1;j <= n;j ++) {
                    if(V_E[k][j] == 1){
                        if(visit[j] == 1)
                        {
                            cout << "INVALID" << endl;
                            while(!all.empty()){
                                all.pop();
                            }
                            return ;
                        }
                        all.push(j);
                        lvl[j] = lvl[k] + 1;
                    }
                }

            }
        }
    }
    for(int i = 1;i <= n;i ++){
        if(visit[i] == 0){
            cout << "INVALID" << endl;
            return ;
        }
    }
    //cout << "Xx" << endl;
    int depth = 0;
    int wide = 0;
    for(int i = 1;i <= n;i ++){
        if(lvl[i] > depth)
            depth = lvl[i];
        widetim[lvl[i]] ++;
    }
    for(int i = 0;i <= 100;i ++){
        if(widetim[i] > wide){
            wide = widetim[i];
        }
    }
    cout << depth << " "<< wide << endl;


}

int main(){
    int n,m;
    while(cin >> n >> m && n > 0){
        bfs(n,m);
    }
}                                 