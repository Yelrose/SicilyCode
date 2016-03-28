
// Problem#: 4189
// Submission#: 1054130
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <cstring>
#include <stdio.h>
#include <map>
using  namespace std;

int array[200000];


void judge(int n)
{
    map<int,int>all;
    int count = 0;
    for(int i = 0;i < n;i ++)
    {
        scanf("%d",&array[i]);
        if(all[array[i]] == 0)
        {
            count ++;
            all[array[i]] ++;
        }
    }

    cout << count << endl;
}
int main()
{
    int n;
    while(cin >> n && n != 0)
    {
        judge(n);
    }
}                                 