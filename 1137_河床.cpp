
// Problem#: 1137
// Submission#: 1464942
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
using namespace std;

int a[30001];
int abs(int i){
    return (i < 0)?-i:i;
}
int main(){
    int n,k;
    cin >> n >> k;
    for(int i = 0;i < n;i ++){
        cin >> a[i];
    }
    int cou = 0;
  int len = 0;
    for(int i = 0;i < n;i ++){
        int max,min;
        max = min = a[i];
        len = 0;
        for(int j = i;j < n;j ++){
            if(abs(a[j] - max) <= k && abs(a[j] - min) <= k){
                len ++;
                if(a[j] > max) max = a[j];
                if(a[j] < min) min = a[j];
            }
            else break;
        }
        if(len > cou)cou = len;
    }
    cout << cou << endl;

}                                 