
// Problem#: 2505
// Submission#: 1838371
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
int n;
long long a[1000010];
long long c[1000010];
long long  fabs(long long k){
    if(k < 0) return -k;
    else return k;
}
int main(){
    //ios::sync_with_stdio(0);
    scanf("%d",&n);
    long long tot = 0;
    for(int i = 0;i < n;i ++){
        scanf("%lld",&a[i]);
        tot += a[i];
    }
    tot /= n;
    long long atot = 0;
    for(int i = 1;i < n;i ++){
        atot += a[i];
        c[i] = atot - i * tot;
    }
    sort(c + 1,c + n);
    long long aver;
    n --;
    if(n % 2 == 1){
        aver = 2 * c[n / 2 + 1];
    }
    else aver = c[n / 2] + c[n/2 + 1];
    n ++;
    long long ttt = fabs(aver);
    for(int i = 1;i < n;i ++){
        ttt += fabs(aver - 2 * (c[i]));
    }
    ttt /= 2;
    printf("%lld\n",ttt);


}                                 