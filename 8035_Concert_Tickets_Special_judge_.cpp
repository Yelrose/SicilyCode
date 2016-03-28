
// Problem#: 8035
// Submission#: 2155126
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <queue>
#include <cstdio>
using namespace std;

vector<int > boyin;
queue<int > boyout;
int vis[100001];
queue<int >girl;
int main(){
    int M,A;
    scanf("%d%d",&M,&A);
    for(int i = 0;i < A;i ++){
        int t;
        scanf("%d",&t);
        boyin.push_back(t);
        vis[t] = 1;
        printf("ENTER GUY %d\n",t);    }
    for(int i = 1;i <= M;i ++){
        if(vis[i] == 0){
            boyout.push(i);
        }
    }
    int N,B;
    scanf("%d%d",&N,&B);
    for(int i = 0;i < B;i ++){
        int t;
        scanf("%d",&t);
        girl.push(t);
    }
    while(!boyout.empty() && !girl.empty()){
        int g = girl.front();
        int b = boyout.front();
        girl.pop();
        boyout.pop();
        printf("GIVE GIRL %d GUY %d\n",g,b);
        printf("ENTER GUY %d\n",b);
        boyin.push_back(b);
    }
    while(!boyout.empty() && boyin.size() >= 2){
        printf("GIVE GUY %d GUY %d\n",boyin[boyin.size() - 2],boyin[boyin.size() - 1]);
        printf("EXIT GUY %d\n",boyin[boyin.size() - 1]);
        int t = boyout.front();
        boyout.pop();
        printf("GIVE GUY %d GUY %d\n",boyin[boyin.size() - 1],t);
        printf("ENTER GUY %d\n",boyin[boyin.size() - 1]);
        printf("ENTER GUY %d\n",t );
        boyin.push_back(t);
    }
}                                 