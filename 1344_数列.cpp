
// Problem#: 1344
// Submission#: 2897604
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <algorithm>
using namespace std;
long long  a[20];
long long  t[2000];
int main() {
    int k;
    int n;
    while(cin >> k >> n) {
        for(int i = 0;i< 10;i ++) {
            if(i == 0)a[i] = 1;
            else a[i] =  a[i - 1] * k;
        //  cout << a[i] << endl;
        }
        int alls = (1 << 10) - 1;
        
        for(int i = 1;i <=alls;i ++) {
            t[i] =  0;
            //cout << i << ": ";
            for(int j = 0;j < 10;j ++) {
                if((i & (1 << j)) > 0) {
                    //cout << j << " ";
                    t[i] += a[j];
                }   
                
                
            }   //cout << endl;
        }
        sort(t + 1, t+ alls + 1);
        cout << t[n] << endl;
        
    }
    
    
}                                 