
// Problem#: 1063
// Submission#: 1602906
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
// Problem#: 6200
// Submission#: 1602881
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <algorithm>
#include <map>
#include <cstring>
#include <stdio.h>
using namespace std;

struct Info{
    int id;
    int height;
    int salary;
}All[300000];
int xiashu[300000];
map<int ,int >fa;
map<int ,int >idtoindex;
bool cmp(const Info &a,const Info &b){
    return a.salary > b.salary;
}
void go(){

    int n,m;
    memset(xiashu,0,sizeof(xiashu));
    fa.clear();
    idtoindex.clear();
    scanf("%d%d",&n,&m);
    for(int i = 0;i < n;i ++){
        scanf("%d%d%d",&All[i].id,&All[i].salary,&All[i].height);
    }
    sort(All,All + n,cmp);
    for(int i = 0;i < n;i ++){
        idtoindex[All[i].id] = i;
    }
    for(int i = n- 1;i >= 0;i --){
        for(int j = i - 1;j >= 0;j --){
            if(All[j].height >= All[i].height){
                fa[All[i].id] = All[j].id;
                xiashu[idtoindex[All[j].id]] += (xiashu[idtoindex[All[i].id]] + 1);
                break;
            }
        }
    }
    for(int i = 0;i < m;i ++){
        int k;
        scanf("%d",&k);
        printf("%d %d\n",fa[k],xiashu[idtoindex[k]]);
    }
}

int main(){
    int T;
    //cout << 0x7FFFFFFF << endl;
    scanf("%d",&T);
    while(T --){
        go();
    }
}                                 