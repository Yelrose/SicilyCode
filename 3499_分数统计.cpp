
// Problem#: 3499
// Submission#: 2897636
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    int T;
    scanf("%d",&T);
    while(T --) {
        int m;
        scanf("%d",&m);
        double maxf =  0;
        double minf = 100;
        double sumf = 0;
        for(int i = 0;i < m;i ++) {
            double t;
            scanf("%lf",&t);
            maxf = max(t,maxf);
            minf = min(t,minf);
            sumf +=  t;
            
        }
        sumf -= (maxf + minf);
        printf("%.2lf\n",sumf/(m - 2));
    }
    
}                                 