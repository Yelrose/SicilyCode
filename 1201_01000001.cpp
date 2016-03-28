
// Problem#: 1201
// Submission#: 952691
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <string>
#include <iostream>
using namespace std;
int length_a;
int length_b;
string a;
string b;
void plu(string & a,int n,char b);
void shit(int z)
{
    cin >> a >> b;
    int o = 0;
    while(a[o]=='0' && b!="")
    {
        a.erase(0,1);
    }
    o = 0;
    while(b[o]=='0' && b != "")
    {
            b.erase(0,1);
    }
    if(a == "") a = "0";
    if(b == "") b = "0";
    if(a == "0")
    {
        cout << z <<" "<<b<<endl;
        return;
    }
    else if(b == "0")
    {
        cout << z <<" "<<a<<endl;
        return;
    }
    if(a.length() < b.length())swap(a,b);
    if(a.length() == b.length()) a = "0" + a;
    length_a = a.length();
    length_b = b.length();
    for(int i = length_b - 1; i >= 0;i --)
    {
        char k = b[i];
        plu(a,length_a - 1,k);
        length_a -- ;
        if(length_a < 0)break;
    }
    cout << z << " " << a << endl;
}

void plu(string & a,int n,char b)
{

    if(n < 0)
    {
        a = "1" + a;
        length_a++;
        return;
    }
    if(b == '0')return;
    else if(b == '1')
    {
        if(a[n] == '0')
        {
            a[n] = '1';
            return;
        }
        else
        {

            a[n] = '0';
            plu(a,n-1,'1');
        }
    }
}

int main()
{
    string a;
    string b;
    int n;
    cin >> n;
    for(int i = 1 ;i <= n ;i ++)
    {
        shit(i);
    }
}                                 