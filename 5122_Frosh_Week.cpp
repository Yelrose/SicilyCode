
// Problem#: 5122
// Submission#: 1301165
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
using namespace std;

int A[1000001];
int L[1000001];
int R[1000001];
long long int rev;

int n;

void mergehe(int l,int m,int r){
    int l_n = m - l + 1;
    int r_n = r - m;
    for(int i = 0;i < l_n;i ++){
        L[i] = A[l + i];
    }
    //L[l_n] = 999999999;
    for(int i = 0;i < r_n;i ++){
        R[i] = A[m + 1 + i];
    }
    //R[r_n] = 999999999;
    long long int l_i,r_i;
    l_i = r_i = 0;
    for(int i = l;i <= r;i ++){
        if(l_i == l_n){
            A[i] = R[r_i ++];

        }
        else if(r_i == r_n){
            A[i] = L[l_i ++];
        }
        else if(L[l_i] > R[r_i]){
            A[i] = R[r_i ++];
            rev += (l_n - l_i);
        }
        else {
            A[i] = L[l_i ++];
        }

    }
}

void merge(int l,int r){
    int m = (r + l) / 2;
    if(l < r){
        merge(l,m);
        merge(m + 1,r);
        mergehe(l,m,r);
    }
    return ;

}
int main(){
    cin >> n;
    rev = 0;
    for(int i = 0;i < n;i ++){
        cin >> A[i];
    }
    merge(0,n - 1);
  
    cout << rev << endl;
    //int k = 999999999;
    //cout << k<< endl;

}                                 