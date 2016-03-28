
// Problem#: 1962
// Submission#: 1026864
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <queue>
#include <string>
using namespace std;

string a;
int main()
{
    cin >> a;
    if(a[0] < 'A' || (a[0] > 'Z' && a[0] < 'a') || a[0] > 'z')
    {
        cout << "Invalid" << endl;
        return 0;
    }
    if(a.length() > 10 || a.length() < 6)
    {
        cout << "Invalid" << endl;
        return 0;
    }
    for(int i = 0;i < a.length();i ++)
    {
        if(a[i] < '0' || (a[i] > '9' && a[i] < 'A') || (a[i] > 'Z' && a[i] < 'a') || a[i] > 'z')
        {
        cout << "Invalid" << endl;
        return 0;
        }
    }
    cout << "Valid" << endl;
    return 0;
}                                 