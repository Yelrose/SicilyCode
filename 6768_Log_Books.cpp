
// Problem#: 6768
// Submission#: 1759014
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
// Problem#: 6768
// Submission#: 1754812
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <string>
#include <algorithm>
#include <iomanip>
#include <fstream>
#define maxn 110
using namespace std;
//ofstream out("")
int toInt(string s)
{
    int h=(s[0]-'0')*10+s[1]-'0';
    int m=(s[3]-'0')*10+s[4]-'0';
    return h*60+m;
}
int main()
{
    int n;
    int a[4];
    while(cin>>n && n)
    {
        //cout<<"n="<<n<<endl;
        int dt=0,nt=0;
        bool pass=1;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<4;j++)
            {
                string s;cin>>s;a[j]=toInt(s);
            }
            if(a[3]-a[2]>120)
            {
                pass=0;
            }
            else
            {
                if(a[3]<=a[0] || a[2]>=a[1])
                {
                    nt+=(a[3]-a[2]);
                }
                else if(a[0]<=a[2] && a[3]<=a[1])
                {
                    dt+=(a[3]-a[2]);
                }
                else if(a[2]<a[0] && a[1]<a[3])
                {
                    if(2*(a[0]-a[2])+(a[3]-a[1]) >= (a[3]-a[2]))
                    {
                        nt+=(a[3]-a[2]);
                    }
                    else
                    {
                        dt +=(a[3]-a[2]);
                    }
                }
                else
                {
                    if(a[3]<=a[1])
                    {
                        if(a[0]-a[2] >= a[3]-a[2])
                        {
                            nt+=(a[3]-a[2]);
                        }
                        else
                        {
                            dt+=(a[3]-a[2]);
                        }
                    }
                    else if(a[2]>=a[0])
                    {
                        if(a[3]-a[1] >= a[1]-a[0])
                        {
                            nt+=(a[3]-a[2]);
                        }
                        else
                        {
                            dt+=(a[3]-a[2]);
                        }
                    }
                }
            }
            //cout<<endl<<"i="<<i<<endl;
        }
        if(dt < 3000 || nt < 600)pass = 0;
        if(pass) cout<<"PASS"<<endl;
        else cout<<"NON"<<endl;
    }
    //cin>>n;
    return 0;
}                                 