
// Problem#: 1019
// Submission#: 1812545
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;

struct Node{
    int maxre[210];
    int maxnore[210];
    int renew[210];
    int renew2[210];
}All[101];
int n,m;
int adj[101][101];
int apple[101];

void dfs(int k){
    for(int i = 1;i <= m + 1;i ++){
        All[k].maxre[i] = apple[k];
        All[k].maxnore[i] = apple[k];
    }
    for(int i = 1;i <= n;i ++){
        if(adj[k][i] == 1){
            adj[i][k] = 0;
            dfs(i);

            for(int j = 1;j <= m + 1;j ++){
                All[k].renew[j] = All[k].maxnore[j];
                All[k].renew2[j] = All[k].maxre[j];
                for(int jj = 1;jj < j;jj ++){
                    if(All[k].renew[j] < All[k].maxre[j - jj] + All[i].maxnore[jj]){
                        All[k].renew[j] = All[k].maxre[j - jj] + All[i].maxnore[jj];
                    }
                    if(All[k].renew[j] < All[k].maxnore[j - jj - 1] + All[i].maxre[jj] && (j - jj - 1 >= 1)){
                        All[k].renew[j] = All[k].maxnore[j - jj - 1] + All[i].maxre[jj];
                    }
                    if(All[k].renew2[j] < All[k].maxre[j - jj - 1]  + All[i].maxre[jj] && (j -jj - 1 >= 1)){
                        All[k].renew2[j] = (All[k].maxre[j - jj - 1]  + All[i].maxre[jj]);
                    }

                 }
            }
            for(int j = 1;j <= m+ 1;j ++){
                All[k].maxnore[j] =All[k].renew[j];
                All[k].maxre[j] =All[k].renew2[j];

            }
            /*cout <<"dfs " <<  k << endl;
            for(int j = 1;j <= m + 1;j ++){
                cout << All[k].maxnore[j] << " ";
            }
            cout << endl;
            for(int j = 1;j <= m + 1;j ++){
                cout << All[k].maxre[j] << " ";
            }
            cout << endl;
                */
        }
    }/*
    cout <<"dfs " <<  k << endl;
    for(int i = 1;i <= m + 1;i ++){
        cout << All[k].maxnore[i] << " ";
    }
    cout << endl;
    for(int i = 1;i <= m + 1;i ++){
        cout << All[k].maxre[i] << " ";
    }
    cout << endl;*/
}

int main(){

    while(cin >> n >> m){
        memset(All,0,sizeof(All));
        memset(adj,0,sizeof(adj));
        for(int i = 1;i <= n;i ++){
            scanf("%d",&apple[i]);
        }
        for(int i = 0;i < n - 1;i ++){
            int a,b;
            cin >> a >> b;
            adj[a][b] = 1;
            adj[b][a] = 1;
        }
        dfs(1);
        int maxf = All[1].maxnore[m + 1];
        if(maxf < All[1].maxre[m + 1])maxf = All[1].maxre[m + 1];
        cout <<maxf << endl;
    }

}                                 