
// Problem#: 1211
// Submission#: 1401271
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
using namespace std;

int R[101][101];
int W[101][101];
int Temp[101][101];
int n,m,k;
void go(){
    for(int i = 1;i <= n;i ++){
        for(int j = 1;j <= n;j ++){
            int sum = 0;
            for(int k = 1;k <= n;k ++){
                sum += R[i][k] * W[k][j];
            }
            Temp[i][j] = sum;

        }
    }
    for(int i = 1;i <= n;i ++){
        for(int j = 1;j <= n;j ++){
            W[i][j] = Temp[i][j];
        }
    }
}

int main(){
    cin >> n >> m >> k;
    for(int i = 0;i < m;i ++){
        int a,b;
        cin >> a >> b;
        R[a][b] = 1;
        W[a][b] = 1;
    }
    for(int i = 2;i <= k;i ++){
        go();
    }
    int q;
    cin >> q;
    for(int i = 0;i < q;i ++){
        int a,b;
        cin >> a >> b;
        cout << W[a][b] << endl;

    }
}                                 