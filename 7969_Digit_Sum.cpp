
// Problem#: 7969
// Submission#: 2045365
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <cstdio>
using namespace std;

long long f[10][20];
long long ten[20];
//f(n,m)= f(n-1,m) + (n - 1) * (10 ^ m - 1)+ f(9,m - 1)
int init(){
    for(int i = 1;i < 10;i ++){
        f[i][1] = f[i - 1][1] + i;
    //    cout << f[i][1] << " ";
    }
    //cout << endl;
    ten[0] = 1;
    for(int i = 1;i <= 17;i ++){
        ten[i] = ten[i - 1] * 10;
    }
    for(int i = 2;i < 17;i ++){
        for(int j = 1;j <10;j ++){
            f[j][i] =  f[j-1][i] + j;
            int n = j - 1;
            for(int k = i - 1;k > 0;k --){
                f[j][i] += (f[9][k] + n * 9 * ten[k - 1]);
                n += 9;
            }
        }


    }

}

long long cul(string t){
    long long sumf = 0;
    long long  c = 0;
    for(int i = 0;i < t.size();i ++){
        int n = t[i] - '0';
        sumf += f[n][t.size() - i] + c*(n * ten[t.size() -i -1]);
        c += n;

    }
    return sumf;
}

long long num(string a){
    long long sumf = 0;
    for(int i = 0;i < a.size();i ++){
        sumf += (a[i] - '0');
    }
    return sumf;
}


int main(){
    init();
    int T;
    cin >> T;
    while(T --){
            string a;
            string b;
            cin >> a >> b;
            long long cu1 = cul(a);
            long long cu2 = cul(b);
            //cout << cu1 << " " << cu2 << endl;
            cout << cu2 - cu1 + num(a) << endl;
    }
}                                 