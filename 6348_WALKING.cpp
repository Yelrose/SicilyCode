
// Problem#: 6348
// Submission#: 1662826
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
double L;
struct A{
    int intim;
    double out;

}array[600];
int n;
bool cmp(const A a,const A b){
    return a.intim < b.intim;
}
int k[600];
int main(){
    scanf("%lf%d",&L,&n);
    for(int i = 0;i < n;i ++){
        int t,v;
        scanf("%d%d",&t,&v);
        array[i].intim = t;
        array[i].out = t+ (L / v);
    }
    sort(array,array + n,cmp);
    k[0] = 1;
    for(int i = 0;i < n;i ++){
        bool find = false;
        for(int j = 0;j < i;j ++){
            if(array[j].out > array[i].out){
                if(k[j] + 1 > k[i]){
                    k[i] = k[j] + 1;
                    find = true;

                }
            }
        }
        if(!find)k[i] = 1;
    }
    int max = k[0];
    for(int i = 0;i < n;i ++){
        if(k[i] > max)max = k[i];
    }
    printf("%d",max);
}                                 