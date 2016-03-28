
// Problem#: 2012
// Submission#: 1770812
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int rudu[1001];
int main(){

    int n;
    while(scanf("%d",&n) != EOF){
        memset(rudu,0,sizeof(rudu));
    char k;
    for(int i = 0;i < n;i ++){
        for(int j =0;j < n;j ++){
                cin >> k;
                if(k == '1'){
                    rudu[i] ++;
                }
        }
    }
    int pos = 0;
    for(int i = 0;i < n;i ++){
        if(rudu[i] > rudu[pos]){
            pos = i;
    
        }
    }
  
        printf("%d\n",pos + 1);
    }
}                                 