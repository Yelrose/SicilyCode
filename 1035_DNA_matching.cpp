
// Problem#: 1035
// Submission#: 953795
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
string Dnastring[100];
bool stata[100];
bool cmp(string a,string b)
{
    return (a > b);
}
bool match(string a,string b)
{
    if(a.length() != b.length())return false;
    for(int i = a.length() - 1;i >= 0;i --)
    {
        if(a[i] == 'T' && ! (b[i] == 'A'))return false;
        if(a[i] == 'A' && ! (b[i] == 'T'))return false;
        if(a[i] == 'G' && ! (b[i] == 'C'))return false;
        if(a[i] == 'C' && ! (b[i] == 'G'))return false;
    }
    return true;
}
void judge()
{

    int n;
    cin >> n;
    int count = 0;
    for(int i = 0;i < n;i ++)

    {
        cin >> Dnastring[i];
        stata[i] = false;

    }
    sort(Dnastring,Dnastring + n,cmp);
    for(int i = 0;i < n;i ++)
    {
        if(stata[i] == true)
        {
            i++;
            continue;
        }
        for(int j = i;j < n;j ++)
        {
            if(stata[j] == true)
            {
                j++;
                continue;
            }
            else if(match(Dnastring[i],Dnastring[j]))
            {
                stata[i] = true;
                stata[j] = true;
                count ++;
                break;
            }
        }
    }
    cout << count << endl;
}
int main()
{
    int n;
    cin >> n;
    for(int i = 0;i < n;i ++)
    {
        judge();
    }
}                                 