
// Problem#: 2010
// Submission#: 1020332
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <cmath>
using namespace std;

int a[7];

bool judge(int length)
{
    for(int i = 1;i < length - 1;i ++)
    {
        if(!(a[i] == a[i - 1] + a[i + 1]) && !(a[i] == a[i - 1] - a[i + 1] )&& !(a[i] == a[i + 1] - a[i - 1]) ){
            return false;
        }
    }
    return true;
}

int main()
{
    int n;
    cin >> n;
    int count  = 99;
    if(n < 100)
    {
        cout << n << endl;
        return 0;
    }
    for(int i = 100;i <= n;i ++)
    {
        int k = i;
        int length = 0;
        while(k != 0)
        {
            a[length] = k % 10;
            k /= 10;
            length ++;
        }
        if(judge(length))count ++;
    }
    cout << count << endl;
}                                 