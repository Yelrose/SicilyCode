
// Problem#: 1815
// Submission#: 968979
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
int main()
{
    int n;
    cin >> n;
    for(int i = 0;i < n;i ++)
    {
        double x1,y1,x2,y2;
        cin >> x1 >> y1 >> x2 >> y2;
        cout << fixed << setprecision( 2 ) << sqrt((x2 - x1) * (x2 - x1)+(y2 - y1) * (y2 - y1)) << endl;
    }
}                                 