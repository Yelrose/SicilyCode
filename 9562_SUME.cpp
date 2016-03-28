
// Problem#: 9562
// Submission#: 2899803
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <cstdio>
using namespace std;

int matrix[1000][1000];

int main() {
    int n;
    scanf("%d",&n);
    for(int i = 0;i < n;i ++) {
        for(int j = 0;j < n;j ++) {
            scanf("%d",&matrix[i][j]);
        }
    }
    if(n == 2) {
        puts("1 1");
    }
    else {
        for(int i = 0;i < n;i++) {
            if(i == 0)  {
                printf("%d",(matrix[i][i + 1] + matrix[i][i + 2] - matrix[i+ 1][i + 2] )/ 2);
            }
            else if(i == n - 1) {
                printf(" %d",(matrix[i][i - 1] + matrix[i][i - 2] - matrix[i - 1][i - 2] )/ 2);
                
            }
            else {
                printf(" %d",(matrix[i][i - 1] + matrix[i][i + 1] - matrix[i - 1][i + 1] )/ 2);
                
            }
        }
        puts("");
    }
}                                 