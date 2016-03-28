
// Problem#: 1510
// Submission#: 902440
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    char miss[1000][80];
    char all[80];
    int n;
    cin >> n;
    int k=0;
    int m;
    for(int i = 0;i < n;i++)
    {
        cin >> m;
        cin >> all;
        int j = 0;
        int o = j;
        while(!(j >= 80 && all[o] == '\0'))
        {
            if(j == m-1) o++;
            miss[k][j] = all[o];
            j++;
            o++;
        }
        k++;
    }
    for(int i = 0;i < k;i++)
        cout << (i+1) << ' ' << miss[i] << endl;
    return 0;
}                                 