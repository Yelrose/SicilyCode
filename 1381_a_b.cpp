
// Problem#: 1381
// Submission#: 994802
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <string>
using namespace std;
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

void tim(string & a,string & b)
{
    if(a.length() > b.length())
    {
        string temp = b;
        b = a;
        a = temp;
    }
    int up = 0;
    int down = 0;
    string c = "",d = "0";
    string k;
    int la = a.length();
    int lb = b.length();
    for(int i = la - 1;i >= 0;i --)
    {
        up = 0;
        c = "";
        if(a[i] == '0') c = "0";//cout << " 1";
        else
        {
            for(int j = i;j < la - 1;j ++)
            {
            //cout << "2";
                c += "0";
            }
            for(int j = lb - 1;j >= 0;j --)
            {
            //cout << a[i] << " " << b[j] <<endl;//cout << c << endl;
                down = ((a[i] - '0') * (b[j] - '0') + up) % 10;
           // cout  << down << endl;
                up = ((a[i] - '0') * (b[j] - '0') + up) / 10;
                k = "0";
                k[0] = down + '0';

                //cout << k << endl;
                c = k + c;
                //cout  << c << "  kjkj"<<endl;
            }
            if(up > 0)
            {
                k = "0";
                k[0] = up + '0';
                c = k + c;
            }
        }
        //cout << c << " aftre" <<endl;
        plu(c,d);
    }
    b = d;
}

int main()
{
    string a,b;
    int n;
    cin >> n;
    for(int i = 0; i < n;i ++)
    {
        cin >> a >> b;
        tim(a,b);
        cout << b << endl;
    }
}                                 