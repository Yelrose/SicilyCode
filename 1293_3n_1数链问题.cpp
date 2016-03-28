
// Problem#: 1293
// Submission#: 956048
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
using namespace std;
int a[10001];
void judge(int n,int & count)
{
    while(n != 1)
    {
        if(n % 2 == 0)
        {
            n /= 2;
            count  ++;
        }
        else
        {
            n = 3 * n +1;
            count ++;
        }
    }
}
int main()
{
    int i,j;
    cin >> i >> j;
    for(int k = i;k <= j ;k ++)
    {
        a[k] = 1;
        judge(k,a[k]);
    }
    int max = 0;
    for(int k = i;k <= j;k ++)
    {
        if(max < a[k])max = a[k];
    }
    cout << max << endl;
}                                 