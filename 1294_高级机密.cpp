
// Problem#: 1294
// Submission#: 966020
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <cmath>
using namespace std;
int main()
{

    long a,b,c;
    cin >> a >> b >> c;
    int d = a % c;
    int k = d;
    if(k != 0)
    {
        for(int i = 0;i < b - 1; i ++)
        {

            k *= d;
            if(k >= c) k %= c;
        }
    }
    cout << k << endl;
}                                 