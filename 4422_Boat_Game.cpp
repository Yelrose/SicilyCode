
// Problem#: 4422
// Submission#: 1066838
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <cmath>
#include <string>
#include <stdio.h>
using namespace std;

void judge()
{
    int n,m;
    cin >> n >> m;
    int l = 1;
    int r = m;
    int count = 0;
    int j ;
    cin >> j;
    for(int i = 0;i < j;i ++)
    {
        int col;
        cin >> col;
        if(col > r)
        {
            //cout << " r - col" << r-col << endl;
            int xx = col - r;
            count += xx;
            r = col;
            l = l + xx;
        }
        else if(col < l)
        {
            int xx =  l - col;
            count += xx;
            l = col;
            r =r - xx;
        }
        //cout << count << " xxx" << endl;
    }
    cout << count << endl;
}

int main()
{
    int n;
    cin >> n;
    for(int i = 0;i < n;i ++)
    {
        judge();
    }
}                                 