
// Problem#: 4188
// Submission#: 1094758
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <string>
using namespace std;

void judge()
{
    int n;
    cin >> n;
    string a = "";
    string b = "0";
    if(n == 0)
    {
        cout << "0" << endl;
        return;
    }
    while(n > 0)
    {
        b[0] = n % 2 + '0';
        a = b + a;
        n /= 2;
    }
    cout << a << endl;
}

int main()
{
    int n;
    cin >> n;
    for(int i = 0;i < n; i++)
    {
        judge();
    }
}                                 