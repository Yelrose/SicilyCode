
// Problem#: 1306
// Submission#: 985229
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
string array[100000];
bool cmp(string a,string b)
{
    if(a.length() != b.length())return(a.length() < b.length());
    else return(a < b);
}
void input(int n,int m)
{
    for(int i = 0;i < n;i ++)
    {
        cin >> array[i];
    }
    sort(array,array + n,cmp);
    for(int i = 0;i < n;i +=m)
    {
        if(i + m < n)cout << array[i] << " ";
        else cout << array[i] << endl;
    }
}

int main()
{
    int n,m;
    while(cin >> n >> m && !(n==0 && m == 0))
    {
        input(n,m);
    }
}                                 