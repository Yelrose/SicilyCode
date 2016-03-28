
// Problem#: 1156
// Submission#: 1296404
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <queue>
#include <cstring>
#include <stack>
using namespace std;


char zi[1001];
int  r[1001];
int l[1001];
char node[1001];
int fa[1001];
int n;
int head = 0;
int vis[1001];
queue<int > ca;
void go(){
    memset(fa,0,sizeof(fa));
    //memset(vis,0,sizeof(vis));
    head = 0;
    for(int i = 0;i < n;i ++){
        int a,b,c;char k;
        cin >> a >> k >> b >> c;
        ca.push(a);
        fa[b] = a;
        fa[c] = a;
        l[a] = b;
        r[a] = c;
        node[a] = k;
    }
    stack<int > ta;
    while(!ca.empty()){
        int temp = ca.front();
        ca.pop();
        if(fa[temp] == 0){
            head = temp;
        }

    }
    ta.push(head);
    while(!ta.empty()){
        int temp = ta.top();
        //vis[temp] == 1;
        ta.pop();
        int b = l[temp];
        int a = r[temp];
        cout << node[temp];
        if(a > 0){
            ta.push(a);
           // vis[a] = 1;
        }
        if(b > 0){

            ta.push(b);


        }

    }
    cout << endl;

}



int main(){
    while(cin >> n){
        go();
    }

}                                 