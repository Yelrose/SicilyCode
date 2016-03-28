
// Problem#: 3913
// Submission#: 1024892
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <cmath>
using namespace std;

int a[26];

void span()
{
    int sum = 1;
    for(int i = 1;i <= 24;i ++)
    {
        sum *= i;
        sum %= 1000000;
        a[i] = sum;
    }
    /*for(int i = 1;i < 25;i ++)
    {
        cout << a[i]<< endl;
    }*/
}

int main()
{
    span();
    int n;
    cin >> n;
    int sum = 0;
    if(n < 25)
    {

        for(int i = 1;i <= n;i ++)
        {
            sum += a[i];
        }
        cout << sum % 1000000 << endl;
    }
    else
    {
        for(int i = 1;i <= 24;i ++)
        {
            sum += a[i];
        }
        cout << sum % 1000000 << endl;
    }
}                                 