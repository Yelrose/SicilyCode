
// Problem#: 1092
// Submission#: 2897381
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
// Problem#: 1092
// Submission#: 2897380
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <cstring>
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <map>
#include <vector>
#include <queue>
#include <deque>
using namespace std;

struct point{
    int x,y;
    int shine;
};

bool cmp(const point a,const point b) {
    if(a.x == b.x)return a.y < b.y;
    return a.x < b.x;
}
map<int ,int > mapy;
point all[10000];
int maxbright;
void add(int l,int r,int o,int v,int y1,int y2);
int getMax();
void init();
int main() {

    int n,W,H;
    while(~scanf("%d%d%d",&n,&W,&H)) {
        init();
        maxbright = 0;
        for(int i = 0;i < n;i ++) {
            scanf("%d%d%d",&all[i].x,&all[i].y,&all[i].shine);
            mapy[all[i].y] = 0;
        }
        sort(all,all+n,cmp);
        int countf = 0;
        for(map<int ,int >::iterator it = mapy.begin();it != mapy.end();it ++) {
            countf ++;
            it -> second = countf;
        }
        int i,j ;
        i = 0;j= 0;
        while(i < n) {

            while(all[i].x - all[j].x >=  W) {
                add(1,countf,1,-all[j].shine,mapy.upper_bound(all[j].y - H) -> second,mapy[all[j].y]);
                j ++;
            }
            add(1,countf,1,all[i].shine,mapy.upper_bound(all[i].y - H) -> second,mapy[all[i].y]);
            maxbright = max(maxbright,getMax());
            i ++;
        }
        printf("%d\n",maxbright);
    }


}

int sumv[40010];
int maxv[40010];
int addv[40010];
void maintain(int o,int L,int R) {
    int lc = o * 2;
    int rc = o * 2 + 1;
    if(R > L) {
        maxv[o] =  max(maxv[lc],maxv[rc]);
    }
    if(L == R) {
        maxv[o] = 0;
    }
    maxv[o] += addv[o];
}



void add(int l,int r,int o,int v,int y1,int y2) {
    int lc = o * 2,rc = 2*o + 1;
    if(y1 <= l && y2 >= r) {
        addv[o] += v;

    } else {
        int m= (l + r) >> 1;
        if(y1 <= m) add(l, m,lc,v,y1,y2);
        if(y2 > m) add(m+1,r,rc,v,y1,y2);
    }
    maintain(o,l,r);

}

int getMax() {
    return maxv[1];
}

void init() {
    mapy.clear();
    memset(maxv,0,sizeof(maxv));
    memset(addv,0,sizeof(addv));
}                                 