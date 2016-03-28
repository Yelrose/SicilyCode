
// Problem#: 1024
// Submission#: 1729777
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <vector>
#include <cstdio>
#include <queue>
#include <cstring>
#include <map>
using namespace std;

vector<pair<int ,int > > vet[10001];
queue<int > bfs;
int dis[10001];
int n,k;
int main(){
    while(scanf("%d%d",&n,&k)!=EOF){
        memset(dis,0,sizeof(dis));
        for(int i = 0;i < 10001;i ++){
            vet[i].clear();
        }
        for(int i = 0;i < n - 1;i ++){
            int a,b,c;
            scanf("%d%d%d",&a,&b,&c);
            pair<int ,int > tmp;
            tmp.first = b;
            tmp.second = c;
            
            vet[a].push_back(tmp);
            tmp.first = a;
            vet[b].push_back(tmp);
        }
        int maxf = 0;
        bfs.push(k);
        while(!bfs.empty()){
            int tmp = bfs.front();
            bfs.pop();
            for(int i = 0;i < vet[tmp].size();i ++){
                int t = vet[tmp][i].first;
                if(dis[t] == 0){
                    int way = vet[tmp][i].second;
                    dis[t] = dis[tmp] + way;
                    if(dis[t] > maxf)maxf = dis[t];
                    bfs.push(t);
                }
            }
        }
        printf("%d\n",maxf);
    }
}                                 