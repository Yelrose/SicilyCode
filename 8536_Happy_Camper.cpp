
// Problem#: 8536
// Submission#: 2900823
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    long long a,b,c;
    int ca = 1;
    while(~scanf("%lld%lld%lld",&a,&b,&c)) {
        if(a == 0 && b == 0 && c == 0)break;
        long long d =  a * (c/ b) + min(c %b,a);
        printf("Case %d: %lld\n",ca,d);
        ca ++;
    }
    return 0;
}                                 