
// Problem#: 7146
// Submission#: 2899523
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <cstdio>
#include <map>
using namespace std;
int fa[100010];
int num[100010];
int sumf[100010];
int findfa(int f) {
    if(f == fa[f])return fa[f];
    else return fa[f] = findfa(fa[f]);
    
}
map<string ,int > sti;
int IQmsy;
char buff[20];
char buff2[20];
int main() {
    int N;
    scanf("%d",&N);
    for(int i = 0;i < N;i ++) {
        int IQ ;
        scanf("%s%d",buff,&IQ);
        string tmp = buff;
        sti[tmp] = i;
        fa[i] = i;
        num[i] = 1;
        if(tmp == "msy"){
            IQmsy = IQ;
        }
        else {
            sumf[i] =  IQ;
            
        }
    }
    int Q;
    scanf("%d",&Q);
    while(Q --) {
        int cmd;
        scanf("%d",&cmd);
        if(cmd == 1) {
            scanf("%s%s",buff,buff2);
            string t = buff;
            string t2 = buff2;
            int i1 = sti[t];
            int i2 = sti[t2];
            int fa1 = findfa(i1);
            int fa2 = findfa(i2);
            if(fa1 == fa2) {
                
            }
            else {
                sumf[fa1] += sumf[fa2];
                num[fa1] += num[fa2];
                fa[fa2] = fa1;  
            }
        }
        else {
            scanf("%s",buff);
            string t = buff;
            int i = sti[t];
            int fa1 = findfa(i);
            int fa2 = findfa(sti["msy"]);
            if(fa1 != fa2) {
                printf("%d\n",sumf[fa1] / num[fa1]);
                
            }
            else {
                printf("%d\n",(-sumf[fa1] + IQmsy)/num[fa1]);
                
            }
            
        }
        
    }
    return 0;
}                                 