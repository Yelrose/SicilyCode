
// Problem#: 10482
// Submission#: 2775610
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <cstdio>
#include <set>
#include <queue>
#include <vector>
using namespace std;


vector<int > member[1000010];
set<int > group[250010];
int gs = 0;
int inq[250010];
queue<int > bfs;
int main() {
    int N,G;
    scanf("%d%d", &N , &G);
    for(int i = 0;i< G;i ++){
        int n;
        scanf("%d",&n);
        for(int j = 0 ;j < n;j ++){
            int t;
            scanf("%d",&t);
            group[i].insert(t);
            member[t].push_back(i);
        }
    }
    int sumf = 0;
    bfs.push(1);
    inq[1] = 1;
    while(!bfs.empty()){
        int t = bfs.front();
        bfs.pop();
        sumf ++;
        for(int i = 0;i < member[t].size();i ++){
            int nxt = member[t][i];
            group[nxt].erase(t);
            if(group[nxt].size() == 1){
                int tt = *group[nxt].begin();
                if(!inq[tt]){
                    bfs.push(tt);
                    inq[tt] = 1;
                }
            }
        }
    }
    printf("%d\n",sumf);
    return 0;
}                                 