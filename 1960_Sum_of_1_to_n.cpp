
// Problem#: 1960
// Submission#: 997145
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int k;
    for(int i = 0;i < n;i ++)
    {
        cin >> k;
        int sum = 0;
        for(int j = 1;j <= k;j ++)
        {
            sum += j;
        }
        cout << sum << endl;
    }        
}                                 