
// Problem#: 6503
// Submission#: 1695624
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <stdio.h>
#include <vector>
#include <cstring>
using namespace std;
unsigned int INF = 4000000000 + 100;

struct Edge{
    int t;
    unsigned int road;
    char d;

};
vector<Edge > edge[4000];
unsigned disi[4000];
unsigned diso[4000];
int cmp(int a,int b){
    if(diso[a] != diso[b]){
        return diso[a] < diso[b];
    }
    return disi[a] < disi[b];
}
int heap[5000];
int mapkey[4000];
int sizeheap;
int n,m,p;
void inistial(){
    sizeheap = 0;
    memset(mapkey,0,sizeof(mapkey));
}

void insert(int k){

    int hole = ++ sizeheap;
    for(;hole > 1 && cmp(k,heap[hole /2]);hole /=2){
        heap[hole] = heap[hole / 2];
        mapkey[heap[hole]] =hole;
    }
    heap[hole] = k;
    mapkey[heap[hole]] =hole;
}


void percolateDown(int hole){
    int child;
    int temp = heap[hole];
    for(;hole * 2 <= sizeheap;hole = child){
        child = hole * 2;
        if(child != sizeheap && cmp(heap[child + 1],heap[child])){
            child ++;
        }
        if(cmp(heap[child],temp)){
            heap[hole] = heap[child];
            mapkey[heap[hole]] =hole;
        }
        else break;
    }
    heap[hole] = temp;
    mapkey[heap[hole]] =hole;
}

void decrease(int k){
    int hole = mapkey[k];
    if(hole == 0){
        insert(k);
        return;
    }
    percolateDown(hole);


}
int delemin(){
    int temp = heap[1];
    mapkey[temp] = 0;
    heap[1] = heap[sizeheap --];
    if(sizeheap == 0)return temp;
    int hole =1;
    percolateDown(1);
    return temp;
}


void dijkstra(int s,int t){
    memset(disi,INF,sizeof(disi));
    memset(disi,INF,sizeof(diso));
    inistial();
    disi[s] = 0;
    diso[s] = 0;
    insert(s);
    while(sizeheap){
        int temp = delemin();
        for(int i = 0;i < edge[temp].size();i ++){
            int b = edge[temp][i].t;
            unsigned int c = edge[temp][i].road;
            if(edge[temp][i].d == 'I'){
                if(diso[temp] < diso[b]){
                    diso[b] = diso[temp];
                    disi[b] = disi[temp] + c;
                    decrease(b);
                }
                else if(diso[temp] == diso[b]){
                    if(disi[temp] + c < disi[b]){
                            diso[b] = diso[temp];
                            disi[b] = disi[temp] + c;
                            decrease(b);

                    }
                }
            }
            else if(edge[temp][i].d == 'O'){
                 if(diso[temp] + c < diso[b]){
                    diso[b] = diso[temp] + c;
                    disi[b] = disi[temp];
                    decrease(b);
                }
                else if(diso[temp]+ c == diso[b]){
                    if(disi[temp] < disi[b]){
                            diso[b] = diso[temp] +c ;
                            disi[b] = disi[temp];
                            decrease(b);

                    }
                }
            }


        }
    }
    if(disi[t] == INF || diso[t] == INF)printf("IMPOSSIBLE\n");
    else printf("%u %u\n",diso[t],disi[t]);
}

int main(){
    scanf("%d%d%d",&n,&m,&p);
    for(int i = 0;i < m;i ++){
        int a;
        int b;
        Edge temp;
        scanf("%d %d %u %c",&a,&b,&temp.road,&temp.d);
        temp.t = b;
        edge[a].push_back(temp);
        temp.t = a;
        edge[b].push_back(temp);

    }
    for(int i = 0;i < p;i ++){
        int a,b;
        scanf("%d%d",&a,&b);
        dijkstra(a,b);
    }

}                                 