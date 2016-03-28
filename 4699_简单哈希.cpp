
// Problem#: 4699
// Submission#: 1136725
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;

bool hash[10000];
int all[10000];

void judge()
{
    memset(hash,0,sizeof(hash));
    int n,m;
    cin >> n >> m;
    int temp;
    int id;
    for(int i = 0;i < n;i ++)
    {
        cin >> temp;
        id = temp % m;
        if(hash[id] == false)
        {
            all[id] = temp;
            hash[id] = true;
        }
        else if(hash[id] == true)
        {
            while(hash[id])
            {
                id ++;
                if(id >= m)
                {
                    id = 0;
                }
            }
            all[id] = temp;
            hash[id] = true;
        }

    }
    for(int i = 0;i < m;i ++)
    {
        cout << i << "#";
        if(hash[i])
        {
            cout << all[i] << endl;
        }
        else cout << "NULL" << endl;
    }
}

int main()
{
    judge();
}                                 