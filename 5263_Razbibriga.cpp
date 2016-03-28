
// Problem#: 5263
// Submission#: 2179719
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <cstdio>
using namespace std;

long long cross[26][26];

long long C(long long i,long long j){
    long long sumf = 1;
    long long sume = 1;
    while(j -- ){
        sumf *= i;
        sume *= (j + 1);
    }
    return sumf / sume;
}

long long A(long long i,long long j){
    long long sumf = 1;
    while(j --){
        sumf *= i;
        i --;
    }
    return sumf;
}

int main(){
    ios::sync_with_stdio(0);
    int N;
    cin >> N;
    string tmp;
    for(int i = 0 ;i < N;i ++){
        cin >> tmp;
        cross[tmp[0] - 'A'][tmp[tmp.size() -1] - 'A'] ++;
    }
    long long countf = 0;
    for(int i = 0;i < 26; i++){
        for(int j = 0;j < 26;j ++){
            for(int k = 0;k < 26;k ++){
                for(int kk = 0;kk < 26;kk ++){
                    if(i == j && j == k && k == kk){
                        if(cross[i][j] >= 4){
                            countf += A(cross[i][j],4);
                        }

                    }
                    else if(k == kk){
                        if(cross[i][k] >= 2 && cross[k][j] >= 2){
                            countf += (A(cross[i][k],2) * A(cross[k][j],2));
                        }
                    }
                    else if(i == k && k == j && k != kk ){
                        if(cross[i][j] >= 2){
                            countf += (A(cross[i][j],2) * cross[i][kk]*cross[kk][j]);
                        }
                    }
                    else if(i == kk && kk == j && k != kk){
                        if(cross[i][j] >= 2){
                            countf += (A(cross[i][j],2) * cross[i][k] * cross[k][j]);
                        }
                    }
                    else if(i == kk && k == j){
                        if(cross[i][k] >= 2){
                            countf += (A(cross[i][k],2) * cross[i][kk] * cross[k][j]);
                        }
                    }
                    else if(i== k && kk == j){
                        if(cross[i][kk] >= 2){
                            countf += (A(cross[i][kk],2) * cross[i][k] * cross[kk][j]);
                        }
                    }
                    else {
                        countf  += (cross[i][k] * cross[k][j] * cross[i][kk] * cross[kk][j]);
                    }








                }
            }
        }
    }
    cout << countf << endl;
    return 0;
}                                 