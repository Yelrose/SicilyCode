
// Problem#: 3725
// Submission#: 2897639
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
using namespace std;

int main() {
    int n;
    while(cin >> n && n != 0) {
        int minf;
        cin >> minf;
        for(int i = 0;i < n - 1;i ++) {
            int t;
            cin >> t;
            minf = max(minf,t);
        }
        cout << minf << endl;
        
    }
}                                 