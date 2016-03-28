
// Problem#: 4628
// Submission#: 1108678
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
using namespace std;

void judge()
{
    int a,b;
    cin >> a>> b;
    for(int i = 1;i <= b;i ++)
    {
        if(i == 1 || i == b)
        {
            for(int j = 0;j < a;j ++)
            {
                cout << "*";
            }
            cout << endl;
        }
        else
        {
            for(int j = 1;j <= a;j ++)
            {
                if(j == 1 || j == a)
                {
                    cout << "*";
                }
                else cout << " ";
            }
            cout << endl;
        }
    }
}

int main()
{
    int n;
    cin >> n;
    for(int i = 0;i < n;i ++)
    {
        judge();
        cout << endl;
    }
}                                 