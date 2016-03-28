
// Problem#: 9019
// Submission#: 2320592
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <set>
#include <cstring>
using namespace std;
int n,m,s,g;
vector<pair<int ,string > > links[50];
vector<pair<int ,string > > links2[50];
int dis[50];
queue<int > bfs;
set<pair<string ,int > > heap;
void init(){
    for(int i = 0;i < 50;i ++){
            links[i].clear();
            links2[i].clear();
    }
    memset(dis,-1,sizeof(dis));
    heap.clear();
}


void solve(){
    init();
    for(int i = 0;i < m ;i ++){
        int a,b;
        string tmp;
        cin >>a>> b >>tmp;
        links[a].push_back(make_pair(b,tmp));
        links2[b].push_back(make_pair(a,tmp));
    }
    bfs.push(g);
    dis[g] = 0;
    while(!bfs.empty()){
        int tmp = bfs.front();
        bfs.pop();
        for(int i = 0 ;i < links2[tmp].size();i ++){
            int to = links2[tmp][i].first;
            if(dis[to] == -1){
                dis[to] = dis[tmp] + 1;
                bfs.push(to);

            }

        }

    }
    if(dis[s] == -1){
        cout <<"NO" << endl;
        return ;
    }
    heap.insert(make_pair("",s));
    while(!heap.empty()){
        pair<string ,int > tmp = *heap.begin();
        heap.erase(heap.begin());
        string now = tmp.first;
        int np = tmp.second;
        if(np == g){
            cout << now <<endl;
            return ;
        }
        if(now.size() > n *6){
            cout <<"NO" << endl;
            return ;

        }
        for(int i =0 ;i < links[np].size();i ++){
            int nxt = links[np][i].first;
            string p = links[np][i].second;
            if(dis[nxt] != -1){
                heap.insert(make_pair(now + p,nxt));
            }

        }
    }



}


int main(){
    ios::sync_with_stdio(false);
    while(cin >> n >> m >>s>>g&&!(n == 0 && m == 0 &&s ==0 && g == 0)){
        solve();

    }
    return 0;
}                                 