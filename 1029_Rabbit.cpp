
// Problem#: 1029
// Submission#: 937243
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
using namespace std;
int num[10][31];
void equal(int *a,const int *b)
{
    for(int i = 0;i < 31;i ++)
    {
        *(a + i) = *(b + i);
    }
}
void add(int *a,const int *b)
{
    for(int i = 30;i >= 0; i--)
    {
        if((*(a + i)+*(b + i)) >= 10)
        {
            *(a + i - 1) += 1;
            *(a + i) = (*(a + i)+*(b + i)) % 10;
        }
        else
        {
            *(a + i) = *(a + i)+*(b + i);
        }
    }
}
void judge(int m,int d)
{
    for(int i = 0;i <= 30 ;i ++)
    {
        num[0][i] = 0;
    }
    for(int i = 1;i < 10;i++)
        equal(num[i],num[0]);
    num[0][30] = 1;
    int temp[31];
    for(int i = 0;i < d;i ++)
    {
        equal(temp,num[m-1]);
        for(int j = m - 1; j > 0 ;j --)
        {
            equal(num[j],num[j - 1]);
        }
        add(num[0],temp);
    }
    for(int i = m - 1;i > 0;i --)
    {
        add(num[i - 1],num[i]);
    }
    for(int i = 0;i < 31 ;i ++)
    {
        if(num[0][i] != 0)
        {
            for(int j = i;j < 31;j ++)
                cout << num[0][j];
            cout << endl;
            break;
        }
    }
}
int main ()
{
    int m,d;
    while(cin >> m >>d && !(m == 0 && d == 0))
    {
        judge(m,d);
    }

}                                 