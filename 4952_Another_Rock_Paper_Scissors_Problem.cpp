
// Problem#: 4952
// Submission#: 1265089
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
using namespace std;

long long int k;
char all[4] = "PSR";
long long int a[34];
long long int b[34];
long long int plusf(long long int n,int change){
    for(int i = 0;i < change;i ++){
        n ++;
        if(n > 3)n =1;
    }
    return n;
}
void go(long long int n){

    long long int k1;
    long long int k2;
    int change = 1;
    if(n <= 3)change += 2;
    int bb;
    for(int i = 0;i < 30;i ++){
        if(a[i] >= n){
            k2 = a[i];
            k1 = a[i - 1];
            break;

        }
    }
    //cout << k1 << "  " << k2 << endl;
    if(n > (k2 + k1) / 2){
        n = n - (k2 + k1) / 2;
        change ++;
        k2 = k2 - (k2 + k1) / 2;
    }
    else {
        n -= k1;
        k2 -=(k2 + k1) / 2;
    }
    //cout << n << "   " << k2 << endl;
       long long int k21;
        long long int k22;
    while(n > 3){
        //cout << n <<"  "<< k2 <<endl;
        k21 = k2 / 3;
        k22 = k21 * 2;
        if(n > k22){
            change += 2;
            n -= k22;
            k2 = k21;
        }
        else if(n > k21){
            change += 1;
            n -= k21;
            k2 = k21;
        }
        else {
            k2 = k21;
        }

    }
   // cout << n <<"  "<< k2 <<endl;
    cout << all[plusf(n,change) - 1] << endl;

}
int main(){
    a[0] = 0;
    a[1] = 3;
    for(int i = 2;a[i - 1] < 10e13;i ++){
        a[i] = a[i - 1] * 3;
        b[i - 1] = (a[i] + a[i - 1]) / 2;
        //cout << " x" << endl;
    }
    long long int n;
    while(cin >> n && n > 0){
        go(n);
    }
}                                 