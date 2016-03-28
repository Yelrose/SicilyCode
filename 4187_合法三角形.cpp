
// Problem#: 4187
// Submission#: 1094700
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
using namespace std;

void judge()
{
    int a,b,c;
    cin >> a>> b >> c;
    if(a + b <= c || a + c <= b || b + c <= a)
    {
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
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