
// Problem#: 1963
// Submission#: 1010645
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a;
    int max;
    cin >> a;
    max = a;
    for(int i = 1;i < n;i ++)
    {
        cin >> a;
        if(a > max)max = a;
    }
    cout << max << endl;
}                                 