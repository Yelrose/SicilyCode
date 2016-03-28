
// Problem#: 8845
// Submission#: 2270275
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <algorithm>
using namespace std;

string a[3000];
const long long md = 1000000007;

long long jie[3010];

long long dfs(int k,int beg,int end){
    long long calc = 1;
    if(beg == end)return 1;
    int last = beg;
    int countf = 0;
    for(int i = beg + 1;i <= end;i ++){
        if(a[i][k] == a[last][k] ){
            continue;
        }
        else {
            calc *= dfs(k + 1,last,i - 1);
            calc %= md;
            countf ++;
            last = i;
        }
    }
    calc *= dfs(k + 1,last,end);
    calc %= md;
    countf ++;

    return (jie[countf] * calc) % md;
}


int main() {
    jie[1] = 1;
    for(int i = 2;i <= 3010;i ++){
        jie[i] = (jie[i - 1] * i)%md;
    }
    ios::sync_with_stdio(0);
    int n;
    cin >> n;
    for(int i = 0;i < n;i ++){
        cin >> a[i];
    }
    sort(a,a + n);
    long long f = dfs(0,0,n - 1);
    cout << f << endl;
}                                 