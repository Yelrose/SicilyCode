
// Problem#: 1940
// Submission#: 1740242
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int rudu[100001];
vector<int > vet[100001];

int T;
int n,m;
int tim;
int heap[100001];
int tot;
void insert(int k){
    int hole = ++tot;
    for(;hole > 1 && k < heap[hole / 2];hole /= 2){
        heap[hole] = heap[hole / 2];
    }
    heap[hole] = k;
}

int deletemin(){
    int tmp1 = heap[1];
    heap[1] = heap[tot --];
    int hole = 1;
    int child;
    int tmp = heap[hole];
    for(;hole * 2 <= tot;hole = child){
        child = hole * 2;
        if(child != tot && heap[child + 1] < heap[child]){
            child ++;
        }
        if(heap[child] < tmp)heap[hole] = heap[child];
        else break;
    }
    heap[hole] = tmp;
    return tmp1;
}


int main(){
    scanf("%d",&T);
    while(T --){
        tot = 0;
        memset(rudu,0,sizeof(rudu));

        scanf("%d%d",&n,&m);
        for(int i = 1;i <= n;i ++ ){
            vet[i].clear();
        }
        for(int i = 0;i <m;i ++){
            int a,b;
            scanf("%d%d",&a,&b);
            vet[a].push_back(b);
            rudu[b] ++;
        }
        for(int i = 1;i <= n;i ++){
            if(rudu[i] == 0)insert(i);
        }
         bool first = false;
        while(tot > 0){
            int tmp = deletemin();
           
            printf("%d ",tmp);
            for(int i = 0;i < vet[tmp].size();i ++){
                if(-- rudu[vet[tmp][i]] == 0){
                    insert(vet[tmp][i]);
                }

            }
        }


        printf("\n");
    }
}                                 