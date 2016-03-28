
// Problem#: 7691
// Submission#: 1969088
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
// Problem#: 7691
// Submission#: 1967123
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <cstdio>
#include <map>
#include <algorithm>
#include <cstring>
using namespace std;
string Num[20];
int Use[10];
int Char[26];
bool nonZero[26];
int n;
int maxs;
int countf;
void dfs(int k,int lvl,int carry){
    if(lvl > maxs && carry == 0){
//      for(int i = 0;i < n;i ++){
//          for(int j = 0;j < Num[i].size();j ++){
//              cout << Char[Num[i][j] - 'A'];
//          }
//          cout << endl;
//      }
        countf ++;
        return ;

    }
    if(Num[k].size() < lvl){
        if(k == n -1)return ;
        else dfs(k + 1,lvl,carry);
        return ;
    }
    char ch =   Num[k][Num[k].size() - lvl];
    if(Char[ch - 'A'] == -1){
        for(int i = 0;i < 10;i ++){
            if(nonZero[ch - 'A'] && i == 0)continue;
            if(Use[i] == 0){
                Char[ch - 'A'] = i;
                Use[i] = 1;
                if(k == n- 1){
                    if(carry % 10 < Char[ch - 'A']){
                        Use[i] = 0;
                        Char[ch - 'A'] = -1;
                        return ;
                    }
                    else if(carry % 10 == Char[ch - 'A']){
                        dfs(0,lvl + 1,carry / 10);
                    }
                }
                else {
                    dfs(k + 1,lvl,carry + Char[ch - 'A']);
                }
                Use[i] = 0;
                Char[ch - 'A'] = -1;
            }
        }
    }
    else{
        if(nonZero[ch - 'A'] && Char[ch - 'A'] == 0)return ;
        if(k == n- 1){
            if(carry % 10 < Char[ch - 'A'])return;
            else if(carry % 10 == Char[ch - 'A'])dfs(0,lvl + 1,carry / 10);

        }
        else dfs(k + 1,lvl,carry + Char[ch - 'A']);
    }


}


int main(){
    while(cin >> n && n != 0){
        memset(Char,-1,sizeof(Char));
        memset(nonZero,0,sizeof(nonZero));
        maxs=0;
        countf = 0;
        for(int i = 0;i < n;i ++){
            cin >> Num[i];
            if(Num[i].size() > maxs)maxs = Num[i].size();
            if(Num[i].size() > 1){
                nonZero[Num[i][0] - 'A'] = 1;

            }
        }
        dfs(0,1,0);
        cout << countf << endl;
    }


}                                 