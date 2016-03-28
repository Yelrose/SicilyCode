
// Problem#: 3836
// Submission#: 1015405
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int n,m;
    while(cin >> n >> m && !(n == 0 && m == 0))
    {
        int sum = 1;
        int sum1 = 1;
        if(m == 0)cout << 1 << endl;
        else{
        for(int i = n;i > n - m;i --)
        {
            sum *= i;
        }
        for(int i = m;i >= 1;i --)
        {
            sum1 *= i;
        }
        //cout << sum << " " <<sum1;
        cout << sum / sum1 << endl;
        }
    }
}                                 