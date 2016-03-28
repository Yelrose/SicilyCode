
// Problem#: 3498
// Submission#: 1024941
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <cmath>
using namespace std;

void find(int n)
{
    int i = 2;
    while(n != 1)
    {
        if(n % i == 0)
        {
            cout << i << " ";
                n /= i;

        }
        else i ++;
    }
    cout << endl;
}

int main()
{
    int n;
    cin >> n;
    int k;
    for(int i = 0;i < n;i ++)
    {
        cin >> k;
        find(k);
    }
}                                 