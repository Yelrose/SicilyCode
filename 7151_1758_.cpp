
// Problem#: 7151
// Submission#: 2899578
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int N,M,K;
char name[30];
char route[30];

void east(int & x,int & y,int p) {
    if(x < 0 || y < 0)return ;
    int xx =  x+ 1;
    int yy =  y;
    if(xx >= N) {
        if(p < 0) {
            x=  y = -1;
            return ;
        }
        else if(p > 0) {
            xx %= N;
            x = xx;
            return ;
        }
        else return ;
    }
    else {
        x = xx;
        y = yy;
        return ;
    }
}

void south(int &x,int &y,int p) {
    if(x <0 || y < 0)return ;
    int xx = x;
    int yy = y - 1;
    if(yy < 0) {
        if(p > 0) {
            y =  M - 1;
            return ;
        }
        else if(p == 0)return ;
        else {
            x = -1;
            y = -1;
            return ;
        }
    }
    x = xx;
    y = yy;
    return;
}

void west(int &x,int &y,int p) {
    if(x < 0 || y < 0)return;
    int xx = x - 1;
    int yy = y;
    if(xx < 0) {
        if(p > 0) {
            x =  N - 1;
            return ;
        }
        else if(p == 0)return;
        else {
            x = y = -1;
            return ;
        }
    }
    x= xx;
    y = yy;
    return ;
}

void north(int & x,int &  y,int p) {
    if(x < 0 || y < 0 )return ;
    int xx =  x;
    int yy = y + 1;
    if(yy >= M) {
        if(p > 0) {
            y = 0;
            return ;
        }
        else if(p == 0)return;
        else {
            x= y = -1;
            return ;
        }
    }
    x = xx;
    y = yy;
    return;
}


int main() {
    while(~scanf("%d%d%d",&N,&M,&K)) {
        if(N == 0 && M ==0 && K == 0)break;
        while(K --) {
            int x,y,p;
            scanf("%s%d%d%d%s",name,&x,&y,&p,route);
            int len = strlen(route);
            for(int i = 0;i < len;i ++) {
                if(route[i]== 'N')north(x,y,p);
                else if(route[i] == 'E')east(x,y,p);
                else if(route[i] == 'W')west(x,y,p);
                else if(route[i] == 'S')south(x,y,p);
            }
            if(x == -1 && y == -1) {
                printf("%s is out of square!\n",name);
            }
            else {
                printf("%d %d\n",x,y);
            }
        }
        puts("");
    }
    return 0;
}                                 