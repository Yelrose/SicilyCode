
// Problem#: 6547
// Submission#: 2899794
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int main() {
    int n;
    while(~scanf("%lld",&n)) {
        if(n == 1){
            puts("No");
            continue;
        }
        if(n == -1)break;
        bool flag = false;
        for(int i= 2;i * i <= n;i ++) {
            if(n % i== 0) {
                flag = true;
                break;
            }
        }
        if(flag) {
            puts("No");
        }
        else puts("Yes");
    }
    
}                                 