
// Problem#: 2501
// Submission#: 1057757
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <cmath>
using namespace std;

int a[9902];

int fuck(int n)
{
    a[0] = n % 9901;
    int count = 1;
    while(a[count] = (a[count - 1] * n) % 9901)
    {
        //cout << a[count] << endl;
        if(a[count] == a[0])
        {
            return count;
        }
        count ++;
    }
}

int main()
{
    int n,k;
    cin >> n >> k;
    int T = fuck(n);
    long long c,d;
    c = k % T;
    d = k / T;
    int sum = 0;
    for(int i = 0;i < T;i ++)
    {
        sum += a[i];
    }
    long long kkk = sum * d;
    for(int i = 0;i < c;i ++)
    {
        kkk += a[i];
    }
    kkk %= 9901;
    cout << kkk << endl;
}                                 