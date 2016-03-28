
// Problem#: 2011
// Submission#: 1658721
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
// Problem#: 2011
// Submission#: 1459956
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <cstring>
#include <queue>
#include <stdio.h>
using namespace std;

int ext[362881];
int jie[10];
int lesNum[10];

class G{
   public:
   G(){};
   G(const G & g){
    for(int i = 0;i < 3;i ++){
        for(int j = 0;j < 3;j ++){
            this -> mat[i][j] = g.mat[i][j];
        }
    }
    this -> tim = g.tim;
   }
    int mat[3][3];
    int tim;

};
 G lu;
    G ld;
    G ru;
    G rd;
queue <G > go;
int Con(const G & g){
    int sum = 0;
    memset(lesNum,0,sizeof(lesNum));
    for(int i = 0;i < 3;i ++){
        for(int j = 0;j < 3;j ++){
            int countf = 0;
            for(int k = 1;k < g.mat[i][j];k ++){
                if(lesNum[k] > 0)countf++;
            }
            sum += (g.mat[i][j] - countf - 1)* jie[9 - (i * 3 + j + 1)];
            lesNum[g.mat[i][j]] = 1;

        }
    }
    return sum;

}

bool Goal(const G & g){
    for(int i = 0;i < 3;i ++){
        for(int j =0 ;j < 3;j ++){
            if(g.mat[i][j] != i * 3 + j + 1){
                return false;
            }
        }
    }
    return true;
}
void bfs(){

    while(!go.empty()){

        G fron = go.front();
        go.pop();
        lu = ld = ru = rd = fron;
        lu.tim = ld.tim = ru.tim = rd.tim = (fron.tim + 1);

        int temp;
        temp = lu.mat[0][0];
        lu.mat[0][0] = lu.mat[0][1];
        lu.mat[0][1] = lu.mat[1][1];
        lu.mat[1][1] = lu.mat[1][0];
        lu.mat[1][0] = temp;

        temp = ld.mat[1][0];
        ld.mat[1][0] = ld.mat[1][1];
        ld.mat[1][1] = ld.mat[2][1];
        ld.mat[2][1] = ld.mat[2][0];
        ld.mat[2][0] = temp;

        temp = ru.mat[0][1];
        ru.mat[0][1] = ru.mat[0][2];
        ru.mat[0][2] = ru.mat[1][2];
        ru.mat[1][2] = ru.mat[1][1];
        ru.mat[1][1] = temp;

        temp = rd.mat[1][1];
        rd.mat[1][1] = rd.mat[1][2];
        rd.mat[1][2] = rd.mat[2][2];
        rd.mat[2][2] = rd.mat[2][1];
        rd.mat[2][1] = temp;

        if(ext[Con(lu)] == -1){
            go.push(lu);
            ext[Con(lu)] = lu.tim;

        }
        if(ext[Con(ld)] == -1){
            go.push(ld);
            ext[Con(ld)] = ld.tim;

        }
        if(ext[Con(ru)] == -1){
            go.push(ru);
            ext[Con(ru)]  = ru.tim;

        }
        if(ext[Con(rd)] == -1){
            go.push(rd);
            ext[Con(rd)] = rd.tim;


        }

    }

}
int main(){
    jie[0] = 1;
    for(int i = 1;i <= 9;i ++){
        jie[i] = jie[i - 1] * i;
    }
    memset(ext,-1,sizeof(ext));
    G beg;
    for(int i = 0;i < 3;i ++){
        for(int j = 0;j < 3;j ++){
            beg.mat[i][j] = i * 3 + j + 1;
        }
    }
    ext[Con(beg)] = 0;
    beg.tim = 0;
    go.push(beg);
    bfs();
    while(scanf("%d",&beg.mat[0][0])!=EOF){
        for(int i = 0;i < 3;i ++){
            for(int j = 0;j < 3;j ++){
                if(i + j > 0){
                    scanf("%d",&beg.mat[i][j]);
                }
            }
        }
        printf("%d\n",ext[Con(beg)]);


    }
}                                 