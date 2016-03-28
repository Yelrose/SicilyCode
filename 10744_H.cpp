
// Problem#: 10744
// Submission#: 2798705
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <cstring>
#include <cstdio>
typedef long long LL;
inline void SWAP(int &a,int &b){ int t=a; a=b; b=t; }
inline LL MIN(LL a, LL b) { return a < b ? a : b; }
inline LL MAX(LL a, LL b) { return a > b ? a : b; }
inline void MINIZE(LL &a,LL b){ if(a>b) { a=b; } }
inline void MAXIZE(LL &a,LL b){ if(a<b){ a=b; } }
#define MAXN 100005
#define INF 100000005

struct node {
    LL minf;
    LL maxf;
}all[MAXN<<3];
LL weight[MAXN];
int dfst;
int it[MAXN];
int ot[MAXN];
int nume,head[MAXN];
struct Edge {
    int v,nxt;
    Edge(){}
    Edge(int a,int b):v(a),nxt(b){}
}e[MAXN<<1];
int fst[MAXN],snd[MAXN];
inline void addEdge(int u,int v){
    e[nume]=Edge(v,head[u]);
    head[u]=nume++;
    e[nume]=Edge(u,head[v]);
    head[v]=nume++;
}
int y1,y2;
int N;
void update(int L,int R,int o,LL  v) {
    if(y1 <= L && R <=  y2) {
        all[o].maxf = v;
        all[o].minf = v;
        return ;
    }
    int M = (L + R) >> 1;
    int lc = o<<1;
    int rc = o<<1|1;
    if(y1 <= M) {
        update(L,M,lc,v);
    }
    if(y2 > M) {
        update(M+1,R,rc,v);
    }
    all[o].minf = MIN(all[lc].minf,all[rc].minf);
    all[o].maxf = MAX(all[lc].maxf,all[rc].maxf);
}
LL  maxans;
LL  minans;
void query(int L,int R,int o) {
    if(y1 <= L && y2 >= R) {
        MAXIZE(maxans,all[o].maxf);
        MINIZE(minans,all[o].minf);
        return ;
    }
    int M = (L + R) >> 1;
    if(y1 <= M) {
        query(L,M,o<<1);
    }
    if(y2 > M) {
        query(M+1,R,o<<1|1);
    }
}

LL solve(int l1,int r1) {
    LL min1,min2;
    LL max1,max2;

    maxans = -1;
    minans = INF;
    y1 = l1;
    y2 = r1;
    query(1,2* N,1);

    min1 = minans;
    max1 = maxans;

    maxans = -1;
    minans = INF;
    y1 = 1;
    y2 = l1 - 1;
    query(1,2 * N,1);

    min2 = minans;
    max2 = maxans;

    maxans = -1;
    minans = INF;
    y1 = r1 + 1;
    y2 = 2 * N;
    query(1,2 * N,1);

    MINIZE(min2,minans);
    MAXIZE(max2,maxans);

    return max1*min1 + max2*min2;
}

int vis[MAXN];
int dfs_t[MAXN], dfs_n;
inline void init() {
    nume=0;
    memset(head,-1,sizeof(head));
    dfst = 1;
    memset(vis,0,sizeof(vis));
}
void dfs() {
    dfs_n=0;
    dfs_t[dfs_n++]=1;
    vis[1] = 1;
    while(dfs_n) {
        int t =  dfs_t[dfs_n-1];
        if(vis[t] == 1){
            it[t] =dfst;
            dfst++;
            vis[t] ++;
            for(int i = head[t]; i != -1; i = e[i].nxt) {
                int nxt = e[i].v;
                if(vis[nxt] == 0) {
                    vis[nxt] ++;
                    dfs_t[dfs_n++] = nxt;
                }
            }
        }
        else if(vis[t] == 2) {
            ot[t] = dfst;
            dfst ++;
            dfs_n--;
        }
    }
    return ;
}
char wordq[8];
int main() {
    int T;
    scanf("%d",&T);
    while(T --) {
        int Q;
        scanf("%d%d",&N,&Q);
        for(int i = 1;i <= N;i ++) {
            scanf("%lld",weight+i);
        }
        init();
        for(int i = 0;i < N - 1;i ++) {
            int a,b;
            scanf("%d%d",&a,&b);
            addEdge(a,b);
            fst[i]=a;
            snd[i]=b;
        }
        dfs();
        for(int i= 1;i <= N;i ++) {
            y1 = it[i];
            y2 = it[i];
            update(1,N<<1,1,weight[i]);
            y1 = ot[i];
            y2 = ot[i];
            update(1,N<<1,1,weight[i]);
        }
        while(Q--) {
            scanf("%s",wordq);
            if(wordq[0]=='Q') {
                int t;
                scanf("%d",&t);
                int k1 = fst[t-1];
                int k2 = snd[t-1];
                if(it[k1] > it[k2] || ot[k1] < ot[k2]) {
                    SWAP(k1,k2);
                }
                printf("%lld\n",solve(it[k2],ot[k2]));
            } else {
                int t;
                LL w;
                scanf("%d%lld",&t,&w);
                weight[t] = w;
                y1 = it[t];
                y2 = it[t];
                update(1,N<<1,1,w);
                y1 = ot[t];
                y2 = ot[t];
                update(1,N<<1,1,w);
            }
        }
    }
}                                 