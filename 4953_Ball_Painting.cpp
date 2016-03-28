
// Problem#: 4953
// Submission#: 2180318
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
using namespace std;
const long long md = 1000000007;
int main(){
    int n;
    while(cin >> n && n != 0){
        long long sumf = 1;
        for(int i = 0;i < 2 * n - 1;i ++){
            sumf *= 2;
            sumf %= md;
        }
        for(int i = 1;i <= 2* n - 1;i += 2){
            sumf *= i;
            sumf %= md;
        }
        cout << sumf << endl;
    }
}                                 