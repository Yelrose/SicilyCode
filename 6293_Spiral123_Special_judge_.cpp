
// Problem#: 6293
// Submission#: 1631352
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <cstring>

using namespace std;

int row[4][201];
int col[4][201];
int count[3];
int dx[202][202];
int dy[202][202];
int n;
int spiral[202][202];
int all[202][202][202];
const int stat[3] = {1,2,3};
int statj;
int countzero;
int lastco;

int lastro;
void initial(){
    countzero = 0;
    statj = 0;

    memset(count,0,sizeof(count));
    memset(col,0,sizeof(col));
    memset(row,0,sizeof(row));
    memset(spiral,0,sizeof(spiral));


}
void form(){
    int dco = 1;
    int dro = 0;
    int ro = 1;
    int co = 1;
    dx[ro][co] = dro;
    dy[ro][co] = dco;
    while(dco + dro != 0){
        spiral[ro][co] = -1;
        if(ro + dro <= n && ro + dro > 0 && co + dco > 0 && co + dco <= n && spiral[ro + dro][co + dco] == 0){
            dx[ro][co] = dro;
            dy[ro][co] = dco;
            ro += dro;
            co += dco;
            continue;
        }
        else if(dro == 0 && dco == -1){
            dro = -1;
            dco = 0;
        }
        else if(dro == 1 && dco == 0){
            dro = 0;
            dco = -1;
        }
        else if(dro == 0 && dco == 1){
            dro = 1;
            dco = 0;
        }
        else if(dro == -1 && dco == 0){
            dro = 0;
            dco = 1;
        }
        if(spiral[dro + ro][dco + co] == -1){
            dro = 0;
            dco = 0;
        }
        dx[ro][co] = dro;
        dy[ro][co] = dco;
        ro += dro;
        co += dco;
    }


}

bool dfs(int ro,int co){
    bool change = false;
    int lastc = lastco;
    int lastr = lastro;
    lastco = dy[ro][co];
    lastro = dx[ro][co];
    if(lastc != dy[ro][co] && lastr != dx[ro][co]){
        change =true;
    }
    if(row[statj][ro] == 0 && col[statj][co] == 0){

        row[statj][ro] = 1;
        col[statj][co] = 1;
        spiral[ro][co] = stat[statj];
        count[statj] ++;
        statj = (statj + 1) % 3;
        if(change){

            if(lastc != 0){
                if(row[0][ro] == 0 || row[1][ro] == 0 || row[2][ro] == 0){
                   spiral[ro][co] = -1;

                statj = statj - 1;
                if(statj < 0) statj = 2;
                count[statj] --;
                row[statj][ro] = 0;
                col[statj][co] = 0;
                lastco = lastc;
                lastro = lastr;

                    return false;
                }
            }
            else if(lastr != 0){
                if(col[0][co] == 0 || col[1][co] == 0 || col[2][co] ==0 ){
                   spiral[ro][co] = -1;

                statj = statj - 1;
                if(statj < 0) statj = 2;
                count[statj] --;
                row[statj][ro] = 0;
                col[statj][co] = 0;
                lastco = lastc;
                lastro = lastr;

                    return false;
                }
            }
        }
        if(dx[ro][co] == 0 && dy[ro][co] == 0){

            if( count[0] == n && count[1] == n && count[2] == n)
            return true;
            else {
                spiral[ro][co] = -1;

                statj = statj - 1;
                if(statj < 0) statj = 2;
                count[statj] --;
                row[statj][ro] = 0;
                col[statj][co] = 0;
                lastco = lastc;
                lastro = lastr;

                return false;
            }
        }

        if(dfs(ro + dx[ro][co],co + dy[ro][co])){

             return true;
        }

        spiral[ro][co] = -1;

        statj = statj - 1;
        if(statj < 0) statj = 2;
        count[statj] --;
        row[statj][ro] = 0;
        col[statj][co] = 0;
    }
    spiral[ro][co] = 0;
    countzero ++;
    if(countzero > (n * n - 3 * n)){

        countzero --;
        lastco = lastc;
        lastro = lastr;
        return false;
    }
    if(change){
            if(lastc != 0){
                if(row[0][ro] == 0 || row[1][ro] == 0 || row[2][ro] == 0){
                    lastco = lastc;
                    lastro = lastr;
                    countzero --;
                    return false;
                }
            }
            else if(lastr != 0){
                if(col[0][co] == 0 || col[1][co] == 0 || col[2][co] ==0 ){
                    lastco = lastc;
                    lastro = lastr;
                    countzero --;
                    return false;
                }
            }
    }
    if(dx[ro][co] ==0 && dy[ro][co] == 0){

        if(count[0] == n && count[1] == n && count[2] == n){

            return true;
        }
        else {
            lastco = lastr;
            lastro = lastr;
            countzero --;
            return false;

        }

    }

    if (dfs(ro + dx[ro][co],co + dy[ro][co])){
        return true;
    }
    else {
        countzero --;
        lastco = lastc;
        lastro = lastr;

        return false;
    }
}









int main(){

    int m;
    cin >> m;
    int k = (m - 5) % 5;
    int tim = (m - 5) / 5;
    k += 5;
    for(n = 5;n <= 9;n ++){
        initial();
        statj = 0;
        form();
        countzero = 0;
        lastco = 1;
        lastro = 0;
        dfs(1,1);
        for(int i = 1;i <= n;i ++){
            for(int j = 1;j <= n;j ++){
                all[n][i][j] = spiral[i][j];
            }
        }
    }
    int kk = k;
    k = 5;
    while(tim  --){

        int next = kk + 5;
        for(int i = 1;i <= kk;i ++){
            for(int j = 1;j <= kk;j ++){
                all[next][i][j] = all[kk][i][j];
            }
        }
        if(next % 2 == 0){
            int num = (next - 4)/2;
            for(int i = next;i > num + 5;i --){
                for(int j = 1;j <= next;j ++){
                    all[next][i][j] = all[next][i - 5][j];
                    all[next][i - 5][j] = 0;
                }
            }
            for(int i = 1;i <= next;i ++){
                for(int j = next;j > next - num;j --){
                    all[next][i][j] = all[next][i][j - 5];
                    all[next][i][j - 5] = 0;
                }
            }
            int ii = 5;
            for(int i = num + 1;i <= num + 5;i ++){
                int jj = 5;
                for(int j = next - num - 4;j <= next - num;j ++){
                    all[next][i][j] = all[5][ii][jj];
                    jj --;
                }
                ii --;
            }
        }
        else {
            int num = (next - 5) / 2;
            for(int i = next;i > num + 5;i --){
                for(int j = 1;j <= next;j ++){
                    all[next][i][j] = all[next][i - 5][j];
                    all[next][i - 5][j] = 0;
                }
            }
            for(int i = 1;i <= next;i ++){
                for(int j = next;j > next - num;j --){
                    all[next][i][j] = all[next][i][j - 5];
                    all[next][i][j - 5] = 0;
                }
            }
            int ii = 1;
            for(int i = num + 1;i <= num + 5;i ++){
                int jj = 1;
                for(int j = next - num - 4;j <= next - num;j ++){
                    all[next][i][j] = all[5][ii][jj];
                    jj ++ ;
                }
                ii ++;
            }
        }
        kk += 5;

    }

    for(int i = 1;i <= m;i ++){
        bool first = false;
        for(int j = 1;j <= m;j ++){
            if(first++) cout << " ";
            cout << all[m][i][j];

        }
        cout << endl;
    }
}                                 