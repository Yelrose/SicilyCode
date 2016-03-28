
// Problem#: 6772
// Submission#: 1804508
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <cstdio>
using namespace std;


long long exGcd(long long a,long long  b,long long  &x,long long &y){
    if(b==0){
        x=1;
        y=0;
        return a;
    }
    long long g=exGcd(b,a%b,x,y);
    long long temp=x;
    x=y;
    y=temp-(a/b)*y;
    return g;
}

int main(){
    long long a,b,c;
    while(cin >>a >> b >> c && !(a == 0 && b == 0 && c ==0)){
        long long x;
        long long y;
        long long gcd = exGcd(a,b,x,y);
        if(c % gcd != 0){
            printf("Unquibable!\n");
            continue;
        }
        long long tim = c / gcd;
        if(x < 0){
            x = (x - x * b);
        }
        x = ((x %(b/gcd)) * ((c / gcd)%(b/gcd))) % (b /gcd);
        y = (c - a * x) / b;
        if(y < 0) {
            printf("Unquibable!\n");
            continue;
        }
        printf("%lld foom",x);
        if(x != 1)printf("s");
        printf(" and %lld foob",y);
        if(y != 1)printf("s");
        printf(" for a twob!\n");

    }

}                                 