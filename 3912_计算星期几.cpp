
// Problem#: 3912
// Submission#: 1094721
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
using namespace std;

int day[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
string week[7] = {"Friday","Saturday","Sunday","Monday","Tuesday","Wednesday","Thursday"};

void judge()
{
    int a,b;
    cin >> a >> b;
    int sum = 0;
    for(int i = 0;i < a;i ++)
    {
        sum += day[i];
    }
    sum += b;
    cout << week[sum % 7] << endl;
}

int main()
{
    int n;
    cin >> n;
    for(int i =0 ;i < n;i ++)
    {
        judge();
    }
}                                 