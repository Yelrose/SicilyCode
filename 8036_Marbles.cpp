
// Problem#: 8036
// Submission#: 2077648
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <cstdio>
using namespace std;
int n;
int m;
int array[300000];
bool judge(int maxf){
    int t = 0;

    for(int i = 0 ;i < m;i ++){
        t += ((array[i] / maxf) + ((array[i] % maxf == 0)?0:1));
    }
    if(t > n)return false;
    else return true;
}


int main(){
    scanf("%d%d",&n,&m);
    int maxf = 0;
    for(int i = 0;i < m;i ++){
        scanf("%d",&array[i]);
        if(array[i] > maxf){
            maxf = array[i];
        }
    }
    int minf = 1;
    while(minf < maxf){
        int mid = (minf + maxf ) >> 1;
        bool calc =judge(mid);
        if(calc){
            maxf = mid;
        }
        else minf = mid + 1;
    }
    printf("%d\n",maxf);
}                                 