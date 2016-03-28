
// Problem#: 1959
// Submission#: 1026786
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <cmath>
using namespace std;

long abs(long n)
{
    if(n >= 0)return n;
    else return (-n);
}

int main()
{
    long x1,x2,y1,y2;
    cin >> x1 >> y1 >> x2 >> y2;
    long d1 = abs(x1 - x2);
    long d2 = abs(y1 - y2);
    cout << d1 + d2 << endl;
}                                 