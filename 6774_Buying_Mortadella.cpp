
// Problem#: 6774
// Submission#: 1759022
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
// Problem#: 6774
// Submission#: 1753776
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <string>
#include <algorithm>
#include <iomanip>
#define maxn 110
using namespace std;
double a[maxn];
int main()
{
    int x,y;cin>>x>>y;
    a[0]=1.0*x/y;
    int n;cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>x >>y;
        a[i]=1.0*x/y;
    }
    sort(a,a+n+1);
    cout<<fixed<<setprecision(2)<<a[0]*1000<<endl;
    return 0;
}                                 