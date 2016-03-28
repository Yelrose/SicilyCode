
// Problem#: 1763
// Submission#: 1838457
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
using namespace std;
long long now[40];
long long nxt[40];
int main(){
    int n,m;
    while(cin >> n >> m){
        for(int i = 0;i < n;i ++){
            now[i] = 0;
        }
        now[0] = 1;
        for(int i = 0;i < m;i ++){
            for(int j = 0;j < n;j ++){
                nxt[j] = now[(j + 1) % n] + now[((j - 1) + n )% n];
            }
            for(int j = 0;j < n;j ++){
                now[j] = nxt[j];
            }
        }
        cout << now[0] << endl;
    }
}                                 