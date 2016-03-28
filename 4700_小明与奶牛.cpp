
// Problem#: 4700
// Submission#: 1136775
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <cstring>
using namespace std;

int k[4];

void judge()
{
    int n;
    cin >> n;
    memset(k,0,sizeof(k));
    int a,b;
    for(int i = 0;i < n;i ++)
    {
        cin >> a >> b;
        if(k[a] < b)k[a] = b;
    }
    for(int i = 1;i <= 3;i ++)
    {
        if(k[i] != 0)cout << i<<" "<<k[i] << endl;
    }
}

int main(){
    int n;
    cin >> n;
    for(int i = 0;i < n;i ++)
    {
        judge();
    }
}                                 