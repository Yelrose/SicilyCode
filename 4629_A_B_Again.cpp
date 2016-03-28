
// Problem#: 4629
// Submission#: 1119565
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
using namespace std;

void judge()
{
    int a,b,c,d;
    cin >> a>> b >> c>> d;
    //(a/b) + c/d
    int z = a * d + b * c;
    int m = b * d;
    int i = 2;
    while(i <= z)
    {
        if((z % i == 0) && (m % i ==0))
        {
            z /= i;
            m /= i;
        }
        else i ++;
    }
    if(m == 1 || z == 0)cout << z << endl;
    else cout << z <<"/" << m << endl;
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