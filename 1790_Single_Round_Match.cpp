
// Problem#: 1790
// Submission#: 1049471
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <string>
using namespace std;

void judge(string & a,string & b)
{
    if(a == "0" && b == "0")
    {
        cout << "YES" <<endl;
        return;
    }
    if(a != b || a.length() < 2)
    {
        cout << "NO" <<endl;
        return;
    }

    char c = a[a.length() - 1];

    for(int i = a.length() - 2;i > 0;i --)
    {
        if((a[i] - c) >= 0){
            c = a[i] - c + '0';
        }
        else
        {
            c = a[i] - c + '0' + 10;
            a[i - 1] --;
        }
    }
    if(c == a[0])
    {
        cout << "YES" << endl;
        return;
    }
    else
    {
        cout << "NO" << endl;
        return;
    }
}

int main()
{
    int n;
    cin >> n;
    string a,b;
    for(int i = 0;i <n;i ++)
    {
        cin >> a >> b;
        judge(a,b);
    }
}                                 