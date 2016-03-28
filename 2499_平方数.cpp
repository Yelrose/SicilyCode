
// Problem#: 2499
// Submission#: 1024857
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <cmath>
using namespace std;

int all[60001];

void span()
{
    for(int i = 1;i <= 60000;i ++)
    {
        all[i] = 4;
    }
    for(int i = 1;i <= sqrt(60000);i ++)
    {
        int ii = pow(i,2);
        all[ii] = 1;
        for(int j = 1;j <= sqrt(60000);j ++)
        {
            int jj = pow(j,2);
            if(ii + jj > 60000)break;
            else
            {
                if(all[ii + jj] > 2)all[ii + jj] = 2;
            }
            for(int k = 1;k <= sqrt(60000);k ++)
            {
                int kk = pow(k,2);
                if(ii + jj + kk > 60000)break;
                else
                {
                    if(all[ii + jj + kk] > 3)all[ii + jj + kk] = 3;
                }
            }
        }
    }
}

int main()
{
    span();
    int n;
    cin >> n;
    int k;
    for(int i = 0;i < n;i ++)
    {
        cin >> k;
        cout << all[k] << endl;
    }
}                                 