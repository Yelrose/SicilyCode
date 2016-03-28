
// Problem#: 6346
// Submission#: 1662680
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <map>
#include <cstring>
#include <queue>
#include <stdio.h>
#include <algorithm>
using namespace std;

string temp;
int vis[9][40321];
int jie[9] = {0,1,2,6,24,120,720,5040,40320};
queue<string> BFS;
int conor(string a){
    int n = a.length();
    int sum =0;
    for(int i = 0;i < n;i ++){
        int count = 0;
        for(int j =0;j < i;j ++){
            if(a[j] < a[i]){
                count ++;
            }
        }
        int te = a[i] - '1';
        sum += jie[n -1 - i] * (te - count);
    }
    return sum;
}

void bfs(string a){

    int n = a.length();
    BFS.push(a);
    while(!BFS.empty()){
        string temp = BFS.front();
        int ta = conor(temp);
        BFS.pop();
        string b ;
        for(int i = 0;i < n;i ++){
            b=temp;
            for(int j = i;j < n;j ++){
                b[j] = temp[n - 1 - (j - i)];
            }
            int tb = conor(b);

            if(vis[n][tb] == 0){
                vis[n][tb] = vis[n][ta] + 1;
                BFS.push(b);
            }
        }
    }

}
struct A{
    int key;
    int locat;
}array[8];
bool cmp(const A a,const A b){
    return a.key < b.key;
}
void go(){
    int n;
    scanf("%d",&n);
    string met ="";
    for(int i = 0;i < n;i ++){
        met += "0";
    }
    for(int i = 0;i  < n;i ++){
        scanf("%d",&array[i].key);
        array[i].locat = i;
    }
    sort(array,array + n,cmp);
    for(int i = 0;i < n;i ++){
        met[array[i].locat] = i + 1 + '0';
    }
    int fu = vis[n][conor(met)];
    fu--;
    printf("%d\n",fu);
}
int main(){

    temp = "";
    string  temp1= "0";
    for(int i = 1;i <= 8;i ++){
        temp1[0] = i + '0';
        temp = temp1 + temp;
        vis[i][conor(temp)] = 1;
        bfs(temp);
    }
    int T;
    scanf("%d",&T);
    while(T --){
        go();
    }



}                                 