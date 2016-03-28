
// Problem#: 10358
// Submission#: 2745693
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <cstdio>
#include <map>
using namespace std;

int N;
int num[5000100];
int newt[5000100];
int matrix[51][51];

int shift(int t){
    return t + 2500000;
}

int calc(int x1,int y1,int x2, int y2) {
    return matrix[x2][y2] + matrix[x1 - 1][y1 - 1] - matrix[x2][y1 - 1] - matrix[x1 - 1][y2];
}
map<int ,int > record;
int main() {
    scanf("%d",&N);
    for(int i = 1;i <= N;i ++){
        for(int j= 1;j <= N;j ++){
            scanf("%d",&matrix[i][j]);
            matrix[i][j] += matrix[i][j - 1] + matrix[i- 1][j] - matrix[i - 1][j - 1];
        }
    }
    int rt = 1;
    long long countf = 0;
    for(int i = 1;i <= N - 1;i ++){
        for(int j = 1;j <= N - 1;j ++){
            for(int i2 = 1;i2 <= i;i2 ++){
                for(int j2 = 1;j2 <= j; j2 ++){
                    int res = shift(calc(i2,j2,i,j));
                    if(newt[res] != rt){
                        newt[res] = rt;
                        num[res] = 0;
                    }
                    num[res] ++;
                }
            }
            for(int i2 = i + 1;i2 <= N;i2 ++){
                for(int j2 = j + 1;j2 <= N; j2 ++){
                    int res = shift(calc(i+1,j + 1,i2,j2));
                    if(newt[res] == rt){
                        countf += num[res];
                    }
                }
            }
            rt ++;

        }
    }
    for(int i = 2;i <= N;i ++){
        for(int j = 1;j <= N - 1;j ++){
            for(int i2 = i;i2 <= N;i2 ++){
                for(int j2 = 1;j2 <= j; j2 ++) {
                    int res = shift(calc(i,j2,i2,j));
                    if(newt[res] != rt){
                        newt[res] = rt;
                        num[res] = 0;
                    }
                    num[res] ++;

                }
            }
            for(int i2 = i - 1;i2>=1 ;i2 --){
                for(int j2 = j + 1;j2 <= N; j2 ++){
                    int res = shift(calc(i2,j + 1,i - 1,j2));
                    if(rt == newt[res]){
                        countf += num[res];
                    }
                }
            }
            rt ++;

        }
    }
    printf("%d\n",countf);
    return 0;
}                                 