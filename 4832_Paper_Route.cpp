
// Problem#: 4832
// Submission#: 1304388
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <cstring>
using namespace std;
int fa[100001];

long long s2f[100001];
long long s2t[100001];
struct v{
    int pre;
    int key;
    int tim;
}All[100001];

int head[100001];
int tot;
int n;
long long int tCam[100001];

long long int min(long long a,long long b){
    if(a > b)return b;
    return a;
}

void addv(int a,int b,int tim){
    if(fa[a] == -1 && a != 0){
        int temp = b;
        b = a;
        a = temp;
    }
    fa[b] = a;
    All[tot].key = b;
    All[tot].pre = head[a];
    All[tot].tim = tim;
    head[a] = tot;
    tot ++;

}

long long findmin(){
    long long int k = s2f[0] + tCam[0];
    for(int i = 1;i <= n;i ++){
        long long xx = s2f[0] - s2t[i] + tCam[i];
        if(xx < k){
            k = xx;
        }
    }
    cout << k << endl;
}

void serch(int i){

    for(int k = head[i];k != -1;k = All[k].pre){

        s2t[All[k].key] = s2t[i] + All[k].tim;
        serch(All[k].key);
        s2f[i] += (s2f[All[k].key] + 2 * All[k].tim);
    }
    //cout << "x" << endl;



}


int main(){
    memset(fa,-1,sizeof(fa));
    memset(head,-1,sizeof(head));
    tot = 0;
    cin >> n;
    cin >> tCam[0];
    for(int i = 1;i <= n;i ++){
        cin >> tCam[i];
    }
    for(int i = 0;i < n;i ++){
        int a,b;
        int tim;
        cin >> a >> b >> tim;
        addv(a,b,tim);
    }

    serch(0);
    findmin();

}                                 