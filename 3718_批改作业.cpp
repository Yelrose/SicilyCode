
// Problem#: 3718
// Submission#: 2897625
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    int n,m;
    scanf("%d%d",&n,&m);
    int countf= 0;
    for(int i = 0;i < n;i ++) {
        double g = 0;
        for(int j = 0;j < m;j ++) {
            double t;
            scanf("%lf",&t);
            g += t;
        }
        g /= m;
        if( g - 60 < 1e-4) {
            
            countf ++;
        }
        printf("%.2lf\n",g);
        
    }
    printf("%d\n",countf);
    return 0;
}                                 