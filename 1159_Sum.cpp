
// Problem#: 1159
// Submission#: 994650
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
void plu(string & a,string & b)
{
    if(a.length() > b.length())
    {
        string temp = b;
        b = a;
        a = temp;
    }
    b = "0" + b;
    int la = a.length();
    int lb = b.length();
    int up = 0;
    int down;
    while(la > 0 || up != 0)
    {
        if(la != 0)
        {
            down = (a[la - 1] - '0' + b[lb - 1] - '0' + up) % 10;
            up = (a[la - 1] - '0' + b[lb - 1] - '0' + up) / 10;
            b[lb - 1] = down + '0';
            la --;
            lb --;
        }
        else
        {
            down = (b[lb - 1] - '0' + up) % 10;
            up = (b[lb - 1] - '0' + up) / 10;
            b[lb - 1] = down + '0';
            lb --;
        }
    }
    while(b[0] == '0' && b.length() != 1)
    {
        b.erase(0,1);
    }
    return;
}
int main()
{
    string a,b;
    b = "0";
    int n;
    while(cin >> n)
    {
        cin >> b;
        for(int i = 1;i < n;i ++)
        {
            cin >> a;
            plu(a,b);
        }
        while(b[0] == '0' && b.length() != 1)
        {
            b.erase(0,1);
        }
        cout << b <<endl;
    }
    return 0;
}                                 