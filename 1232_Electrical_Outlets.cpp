
// Problem#: 1232
// Submission#: 985193
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <cmath>
using namespace std;

void input(int n)
{
    int sum = 0;
    int a;
    for(int i = 0;i < n;i ++)
    {
        cin >> a;
        sum += a;
    }
    cout << sum - n + 1<<endl;
}

int main()
{
    int n;
    cin >> n;
    int k;
    for(int i =0;i < n;i++)
    {
        cin >> k;
        input(k);
    }
}                                 