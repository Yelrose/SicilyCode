
// Problem#: 4086
// Submission#: 1015087
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <string>
#include <map>
#include <cmath>
using namespace std;



void judge()
{
    int a,b,c;
    cin >>  a >> b >> c;
    for(int i = 10;i <= 100;i ++)
    {
        if((i - a) % 3 == 0 && (i - b) % 5 == 0 && (i - c) % 7 == 0)
        {
            cout << i << endl;
            return;
        }
    }
    cout << "No answer" << endl;
}

int main()
{
    int t;
    cin >> t;
    for(int i = 0;i < t; i ++)
    {
        judge();
    }
    return 0;
}                                 