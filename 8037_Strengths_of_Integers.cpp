
// Problem#: 8037
// Submission#: 2155087
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <cstdio>
using namespace std;
long long slcm[60];
long long gcd(long long a,long long b){
    if(b == 0)return a;
    else return gcd(b,a%b);
}
long long lcm(long long a,long long b){
    return a* b / gcd(a,b);
}
long long calc(long long k){
    long long left  = k - ((k - k/slcm[2]) + (k /slcm[3] - k/slcm[4]) +(k/slcm[7] - k/slcm[8]) + (k/slcm[15] - k/slcm[16]) + (k/slcm[31] - k/slcm[32]));
    long long sumf =(k -  k / slcm[2]) * 2 + 3*left+
    (k/slcm[3] - k/slcm[4]) * 4 +
    (k/slcm[7] - k/slcm[8]) * 4 +
    (k / slcm[15] - k/slcm[16]) * 4 +
    (k / slcm[31] - k/slcm[32]) * 4;
    return sumf;
}

int main(){
    long long sum = 1;
    for(long long i = 2;i <= 32;i ++){

        sum = lcm(sum,i);
        slcm[i] = sum;
    }
    long long a,b;
    scanf("%lld%lld",&a,&b);
   // cout << calc(a - 1) << endl;
    //cout << calc(b) << endl;
    printf("%lld\n",calc(b) - calc(a - 1));
    return 0;

}                                 