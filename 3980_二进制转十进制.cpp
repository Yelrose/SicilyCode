
// Problem#: 3980
// Submission#: 1015673
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <cmath>
#include <string>
using namespace std;

void judge()
{
    string n;
    cin >> n;
    while(n[0] == '0' && n.length() > 1)n.erase(0,1);
    int k = 0;
    int g = 0;
    for(int i = n.length() - 1;i >=0;i --)
    {
        k = k + (int)(n[i]-'0')*pow(2,g);
        g ++;
    }
    cout << k << endl;

}

int main()
{
    int n;
    cin >> n;
    for(int i = 0;i < n; i ++)
    judge();
    return 0;
}                                 