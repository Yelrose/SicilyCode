
// Problem#: 6769
// Submission#: 1758996
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <cstring>
#include <map>
#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;
int cross;
int down;
int n;
char vet[200][200];
pair<int ,int >Vector;
queue<int > bfs;
struct Bian{
    pair<int ,int > num;
    bool cross;
    int sum;
}All[200001];
int tot;
string fuck;
pair<int ,int >tmp;
map< pair<int ,int >,int > locat;
int main(){
    while(cin >> n && n != 0){
        while(!bfs.empty())bfs.pop();
        locat.clear();
        memset(vet,'#',sizeof(vet));
        cross = 0;
        down = 0;
        tot = 0;
        for(int i = 1;i <= n;i ++){
            for(int j = 1;j <= n;j ++){
                cin >> vet[i][j];
            }

        }
        for(int i = 1;i <= n;i ++){
            for(int j = 1;j <= n;j ++){
                if(vet[i][j] != '#' && vet[i][j + 1] != '#' && vet[i][j + 2] == '#')cross++;
            }
        }
        for(int i = 1;i <= n;i ++){
            for(int j = 1;j <= n;j ++){
                if(vet[i][j] != '#' && vet[i + 1][j] != '#' && vet[i + 2][j] == '#')down ++;
            }
        }
        cin >> fuck;
        for(int i = 0;i < cross;i ++){
            int sum;
            cin >> tmp.second >> tmp.first >> sum;
            All[tot].num = tmp;
            All[tot].cross = true;
            All[tot].sum = sum;
            locat[tmp] = tot;
            tot ++;
        }
        cin >> fuck;
        for(int i = 0;i < down;i ++){
            int sum;
            cin >> tmp.second >> tmp.first >> sum;
            All[tot].num = tmp;
            All[tot].cross = false;
            All[tot].sum = sum;
            locat[tmp] = tot;
            tot ++;
        }
        for(int i = 0;i < tot;i ++){
            tmp = All[i].num;
            pair<int ,int > tmp1 =  tmp;
            bool direct = All[i].cross;
            Vector = (direct)?pair<int ,int >(0,1):pair<int ,int >(1,0);
            int countf = 0;
            while(vet[tmp.first][tmp.second] != '#'){
                if(vet[tmp.first][tmp.second] =='.')countf ++;
                tmp.first += Vector.first;
                tmp.second += Vector.second;

            }
            if(countf == 1) bfs.push(i);

        }
        while(!bfs.empty()){
            int in = bfs.front();
            pair<int ,int > beg = All[in].num;
            bfs.pop();
            bool direct = All[in].cross;
            int sum = All[in].sum;
            pair<int ,int > change = pair<int ,int>(-1,-1);
            Vector = (All[in].cross)?pair<int ,int >(0,1):pair<int ,int >(1,0);
            int tog = 0;
            while(vet[beg.first][beg.second] != '#'){
                if(vet[beg.first][beg.second] =='.')change = beg;
                else {
                    tog += (vet[beg.first][beg.second] - '0');
                }
                beg.first += Vector.first;
                beg.second += Vector.second;

            }
            if(change == pair<int ,int > (-1,-1))continue;
            vet[change.first][change.second] = sum - tog + '0';
            pair<int ,int > leftdown = change;
            pair<int ,int > rightup = change;
            Vector = (All[in].cross)?pair<int ,int >(1,0):pair<int ,int >(0,1);
            int countf = 0;
            pair<int ,int > nextbeg = rightup;
            while(vet[rightup.first][rightup.second] != '#'){
                if(vet[rightup.first][rightup.second] =='.')countf ++;
                nextbeg = rightup;
                rightup.first -= Vector.first;
                rightup.second -= Vector.second;

            }
            while(vet[leftdown.first][leftdown.second] != '#'){
                if(vet[leftdown.first][leftdown.second] =='.')countf ++;
                leftdown.first += Vector.first;
                leftdown.second += Vector.second;

            }
            if(countf == 1){
                for(int i = 0;i < tot;i ++){
                    if(All[i].num == nextbeg && All[i].cross == !direct){
                        bfs.push(i);
                        break;
                    }
                }

            }

        }
        for(int i = 1;i <= n;i ++){
            for(int j = 1;j <= n;j ++){
                printf("%c",vet[i][j]);
            }
            printf("\n");
        }
        printf("\n");
    }

}                                 