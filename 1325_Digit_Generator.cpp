
// Problem#: 1325
// Submission#: 985186
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <cmath>
#include <string>
using namespace std;


bool generator(int a ,int i);

void find(int i)
{
    int a;
    if(i == 100000)a = i -54;
    else if(i >= 10000)a = i - 45;
    else if(i >= 1000)a = i - 36;
    else if(i >= 100)a = i -27;
    else if(i >= 10)a = i - 18;
    else a = 1;
    while(a < i)
    {
        if(generator(a,i))
        {
            cout << a << endl;
            return;
        }
        else a++;
    }
    cout << 0 <<endl;
}

bool generator(int a ,int i)
{
    int k = a;
    int sum = 0;
    while(k != 0)
    {
        sum += k % 10;
        k /= 10;
    }
    sum += a;
    //cout << sum << " ";
    return (sum == i);
}

int main()
{
    int n;
    cin >> n;
    int m;
    for(int i = 0;i < n; i++)
    {
        cin >> m;
        find(m);
    }
}                                 