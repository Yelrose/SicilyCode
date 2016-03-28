
// Problem#: 6584
// Submission#: 1737131
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <cstdio>
using namespace std;

long long C[2002][2002];

int initial(){
    C[0][0] = 1;
    for(int i = 1;i <= 2000;i ++){
        C[0][i] = 1;
        for(int j = 1;j <= i ;j ++){
            C[j][i] = (C[j][i - 1] + C[j - 1][i -1]) % 2552;
        }

    }
}
 int W,H,K,Q;
 int a1,a2,b1,b2;
int main(){
    initial();

    int T;
    scanf("%d",&T);
    while(T --){

        scanf("%d%d%d",&W,&H,&K);
        while(K --){
            scanf("%d",&Q);
            long long sum = 0;

            for(int i = 0;i < Q;i ++){
                scanf("%d%d%d%d",&a1,&a2,&b1,&b2);
                sum += ((C[a1][a1 + a2] * C[W - b1][W + H - b1 - b2]));
                sum %= 2552;



            }
            //cout << "fuck"
            int k =  (C[W][H + W] - sum + 2552) % 2552;
            printf("%d\n",k);
        }

    }

}                                 