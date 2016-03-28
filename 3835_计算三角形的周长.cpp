
// Problem#: 3835
// Submission#: 1024955
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

double x[3];
double y[3];

void circle()
{
    double a = pow((x[0] - x[1]),2) +pow((y[0] - y[1]),2);
    double b = pow((x[1] - x[2]),2) +pow((y[1] - y[2]),2);
    double c = pow((x[0] - x[2]),2) +pow((y[0] - y[2]),2);
    cout << fixed << setprecision(5);
    cout << sqrt(a) + sqrt(b) + sqrt(c) << endl;
}

int main()
{
    int n;
    cin >> n;
    for(int i = 0;i < n;i ++)
    {
        for(int j = 0;j < 3;j ++)
        {
            cin >> x[j] >> y[j];
        }
        circle();
    }
}                                 