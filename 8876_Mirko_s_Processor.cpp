
// Problem#: 8876
// Submission#: 2273092
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>
using namespace std;

struct lo{
    int first;
    int second;
    int flip;
    lo(int a,int b,int c):first(a),second(b),flip(c){

    }
    lo(){
    }
};


vector<lo > bits[100010][32];
int shift[100010];
int vis[100010][32];
int num[100010][32];


int main(){
    int N,M;
    scanf("%d%d",&N,&M);
    for(int i = 0;i < M;i ++){
        int mod,a,b;
        scanf("%d%d%d",&mod,&a,&b);
        a --;
        if(mod ==2)b --;
        if(mod == 2){
            unsigned int u;
            scanf("%u",&u);
            //cout << "fuck: " << u << endl;
            for(int j = 0;j < 32;j++){
                int t = u % 2;
                u /= 2;
                bits[a][(j + shift[a])%32].push_back(lo(b,(j + shift[b])%32,t));
                bits[b][(j + shift[b]) % 32].push_back(lo(a,(j + shift[a])%32,t));
            }

        }
        else {
            shift[a] +=  b;
            shift[a] += 32;
            shift[a] %= 32;

        }
    }
    bool fail = 0;
    queue<lo > bfs;
    for(int i = 0;i < N;i ++){
        for(int j = 31;j >= 0;j --){
            if(vis[i][j] == 0){
                num[i][j] = 0;
                vis[i][j] = 1;
                bfs.push(lo(i,j,0));
                while(!bfs.empty()){
                    lo tmp = bfs.front();
                    bfs.pop();
                    int t = tmp.first;
                    int b = tmp.second;
                    for(int k = 0;k < bits[t][b].size();k ++){
                        int nt = bits[t][b][k].first;
                        int nb = bits[t][b][k].second;
                        int flip = bits[t][b][k].flip;
                        if(!vis[nt][nb]){
                            vis[nt][nb] = 1;
                            if(flip == 0){
                                num[nt][nb] = num[t][b];
                            }
                            else {
                                num[nt][nb] = 1 - num[t][b];
                            }
                            bfs.push(lo(nt,nb,0));
                        }
                        if(vis[nt][nb]){
                            if(flip == 0){
                                fail |= (num[nt][nb] != num[t][b]);
                            }
                            else {
                                fail |= (num[nt][nb] == num[t][b]);
                            }
                        }
                    }
                }
            }
        }
    }
    if(fail){
        printf("-1\n");
        return 0;
    }
    for(int i = 0;i < N;i ++){
    //        cout << shift[i] << endl;
            if(i > 0){
                printf(" ");
            }
            unsigned int u = 0;
            for(int j = 31;j >= 0;j --){
                //cout << num[i][j];
                u = u << 1;
                u += num[i][j];
            }
            //cout << endl;
            printf("%u",u);
    }
    printf("\n");
}                                 