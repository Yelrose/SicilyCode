
// Problem#: 1341
// Submission#: 965956
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <algorithm>
using namespace std;
int state[1001];
void judge(int n)
{
    for(int i = 1;i <= 1000;i ++)
        state[i] = 0;
    int a[100];
    for(int i = 0;i < n;i ++)
    {
        cin >> a[i];
        if(state[a[i]] == a[i])
        {
            i --;
            n --;
        }
        else state[a[i]] = a[i];
    }
    sort(a,a + n);
    cout << n << endl;
    for(int i = 0;i < n;i ++)
    {
            if(i != n-1)cout << a[i] <<" ";
            else cout << a[i] << endl;
    }

}
int main()
{
    int n;
    while(cin >> n)
    {
        judge(n);
    }
}                                 