
// Problem#: 7911
// Submission#: 2023765
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <cstdio>
using namespace std;
struct d{
    int r,c;
    int w,h;
}all[101];
int main(){
    int n;
    int ca = 1;
    while(scanf("%d",&n) && n!= 0){
        for(int i = 1;i <= n;i ++){
            scanf("%d%d%d%d",&all[i].r,&all[i].c,&all[i].w,&all[i].h);
        }
        int q;
        scanf("%d",&q);
        printf("Desktop %d:\n",ca);
        ca ++;
        for(int i = 0;i < q;i ++){
            int r,c;
            scanf("%d%d",&r,&c);
            int f = 0;
            for(int j = 1;j <= n;j ++){
                if((r >= all[j].r )&& (r <= (all[j].r + all[j].h - 1)) && (c >= all[j].c )&& (c<= (all[j].c + all[j].w - 1))){
                    f = j;
                }
            }
            if(f == 0){
                printf("background\n");
            }
            else printf("window %d\n",f);
        }
    }
}                                 