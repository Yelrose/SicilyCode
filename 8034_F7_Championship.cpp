
// Problem#: 8034
// Submission#: 2077597
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int  n;
int array[300000];
bool solve(int k){
    //cout << "fu " << k << " " << array[k]<< endl;
    int m = array[k] +  n;
    //cout << m << endl;
    int j = 1;
    for(int i = n - 1;i > k;i --){
        if(array[i] == array[k]){
        }
        else if(array[i] + j > m){
      //      cout << array[i] << " " << j << " " << m << endl;

             return false;
        }
        j ++;
    }
    return true;
}


int main(){
    scanf("%d",&n);
    for(int i = 0;i < n;i ++){
        scanf("%d",&array[i]);
    }
    sort(array,array+n);
    int maxf = n - 1;
    int minf = 0;
    while(minf < maxf){
        int mid = (minf + maxf) >> 1;
        bool judge = solve(mid);
        if(judge){
            maxf = mid;
        }
        else {
            minf = mid + 1;
        }
    }
    cout << (n - minf) << endl;
}                                 