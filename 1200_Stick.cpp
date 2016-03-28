
// Problem#: 1200
// Submission#: 955985
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <algorithm>
using namespace std;
int a[101];
void judge(int n)
{
    for(int i = 0;i < n;i ++)
    {
        cin >> a[i];
    }
    sort(a,a + n);
    for(int i = 0;i < n;i ++)
    {
        if(a[i] == a[i + 1]) i++;
        else
        {
            cout << a[i] << endl;
            break;
        }
    }
}
int main()
{
    int n;
    while(cin >> n && n != 0)
    {
        judge(n);
    }
}                                 