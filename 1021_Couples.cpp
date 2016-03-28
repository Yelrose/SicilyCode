
// Problem#: 1021
// Submission#: 949321
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
using namespace std;
int couple_all[200001];
int count;
int series[200001];
void hash_couple()
{
    int a,b;
    cin >> a;
    cin >> b;
    couple_all[a] = b;
    couple_all[b] = a;
}
bool judge_couple(int &a,int &b)
{
    while(series[a] == 0)
    {
        a--;
        if(a == 0)return false;
    }
    while(series[b] == 0)
    {
        b++;
        if(b > count)return false;
    }

    return (couple_all[a] == b && couple_all[b] == a);
}
void judge(int n)
{
    count = 2 * n;
    for(int i = 1;i <= 2*n; i ++)
    {
        couple_all[i] = i;
    }
    for(int i = 1;i <= n;i ++)
        hash_couple();
    for(int i = 1;i <= 2*n; i++)
        series[i] = 1;
    int z = count;
    int k = 0;
    while(z != 0)
    {
        if(k == z)
        {
            cout << "No" << endl;
            return;
        }
        k = z;
        for(int i = 1;i <= count;i ++)
        {
            while(series[i] == 0)
            {
                i++;
                if(i > count)break;
            }
            if(i > count)break;
            if(i == count)
            {
                int ii = i;
                int j = 1;
                while(judge_couple(ii,j))
                {

                    series[j] = 0;
                    series[ii] = 0;
                    z -= 2;
                    if(z == 0)break;
                }
            }
            else
            {
                int ii = i;
                int j = i + 1;
                while(judge_couple(ii , j))
                {
                    series[ii] = 0;
                    series[j] = 0;
                    z -= 2;
                    if(z == 0)break;
                }
            }
        }
    }
    cout << "Yes" << endl;
}
int main()
{
    int n;
    while(cin >> n && n != 0)
    {
        judge(n);
    }
}                                 