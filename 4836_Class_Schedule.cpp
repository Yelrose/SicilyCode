
// Problem#: 4836
// Submission#: 1221729
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include<iostream>
#include<cstring>
#include <cmath>
using namespace std;

long cdec[26][1000];
long sum[26][1000];
long energ[26][1000];
long C,T,L;

long abs(long n){
    if(n < 0)return (-n);
    return n;
}
void kkk(){
    memset(sum,0,sizeof(sum));
    cin >> C >> T >> L;
    for(long i = 0;i < C;i ++){
        for(long j = 0;j < T;j ++){
            cin >> cdec[i][j] >> energ[i][j];
        }
    }
    for(long i = 0;i < T;i ++ ){
        sum[0][i] = energ[0][i] + cdec[0][i];
    }
    for(long i = 1;i < C;i ++){
        for(long j = 0;j < T;j ++){
            long min = sum[i - 1][0] + energ[i][j] + abs((cdec[i - 1][0] - cdec[i][j]));
            for(long k = 1;k < T;k ++){
                if((sum[i - 1][k] + energ[i][j] + abs(cdec[i - 1][k] - cdec[i][j])) <  min){
                    min = sum[i - 1][k] + energ[i][j] + abs(cdec[i - 1][k] - cdec[i][j]);
                }
            }
            sum[i][j] = min;

        }
    }
    long min = sum[C - 1][0] + L - cdec[C - 1][0];
    for(long i = 0;i < T;i ++){
        if(min > sum[C - 1][i] + L -cdec[C-1][i]){
            min = sum[C - 1][i] + L -cdec[C-1][i];
        }
    }
    /*cout << "==============="<<endl;
    for(int i = 0;i < C;i ++){
        for(int j = 0;j < T ;j ++){
            cout <<sum[i][j] <<" ";
        }
        cout << endl;
    }*/
    cout << min << endl;
}

int main(){
    long n;
    cin >> n;
    for(long i = 0;i < n;i ++)
    kkk();
}                                 