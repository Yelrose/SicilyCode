
// Problem#: 1793
// Submission#: 1053896
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <cmath>
using namespace std;

/*bool gcd(long a,long b)
{
    if(b == 1)return true;
    if(a % b == 0)return false;
    return gcd(b,a % b);
}*/
int gcd(int a, int b)
{
    return b==0?a:gcd(b,a%b);
}
void judge(int a,int b)
{
    if(b == a)
    {
        cout << '0' << " " << a << " "<< b << endl;
        return;
    }
    int c = b / a;
    int k = c - 1;
    int aa,bb;
    aa = 1;bb = c;
    for(int i = 2;i <= sqrt(c);i ++)
    {
        int z = c / i;
        if(z * i != c || gcd(z,i) != 1)
        {
            continue;
        }
        if(z - i < k)
        {
            k = z - i;
            aa = i;
            bb = z;
        }
        else
        {
            break;
        }
    }
    cout << k * a << " " << aa * a << " " << bb * a << endl;
}


int main()
{
    int a;
    int b;
    while(cin >> a >> b && !(a == 0 && b == 0))
    {
        judge(a,b);
    }
}                                 