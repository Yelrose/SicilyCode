
// Problem#: 5296
// Submission#: 1319677
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;
queue<int > zz;
struct R{
    int x1,x2,y1,y2;
}All[1000];
vector<int > a[1000];
int tot;
//int k[1000];
int dis[1000];
int vis[1000];
void go(int n){
    for(int i = 0;i < 1000;i ++){
        a[i].clear();
        dis[i] = 1;
        vis[i] = 0;
    }

    for(int i = 0;i < n;i ++){
        cin >> All[i].x1 >> All[i].y1 >> All[i].x2 >> All[i].y2;
        for(int j = 0;j < i;j ++){
            //cout << "fuc" << endl;
            if((All[i].x1 > All[j].x2) && (All[i].y1 > All[j].y2)){
                a[j].push_back(i);
                //k[j] ++;
                //cout << "x1" << endl;
            }
            if((All[j].x1 > All[i].x2) && (All[j].y1 > All[i].y2)){
                a[i].push_back(j);
                //cout << "x2" << endl;
            }
        }
    }
    for(int i = 0;i < n;i ++){
        if(vis[i] == 0){
            zz.push(i);
            vis[i] = 1;
        }
        while(!zz.empty()){

            int k = zz.front();
           // cout << k << " ";
            zz.pop();
            for(vector<int >::iterator j = a[k].begin();j != a[k].end();j ++){
                if(dis[k] + 1 > dis[* j]){
                    dis[* j] = dis[k] + 1;
                    zz.push(* j);
                    vis[* j] = 1;
                }
            }
        }
        //cout << endl;
    }
    int max = 0;
    for(int i = 0;i < n;i ++){
        //cout << dis[i] << " ";
        if(dis[i] > max){
            max = dis[i];
        }
    }
   // cout << endl;
    cout << max << endl;


}


int main(){
    int n;
    while(cin >> n && n!= 0)
    {
        go(n);
    }
}                                 