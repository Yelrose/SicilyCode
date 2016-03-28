
// Problem#: 6767
// Submission#: 1759012
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
// Problem#: 6767
// Submission#: 1753731
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <string>
using namespace std;

int main()
{
    int t;cin>>t;
    for(int i=0;i<t;i++)
    {
        string s;
        cin>>s;
        int md=s.length()/2;
        if(s[md]==s[md-1])
        {

            cout<<"Do-it"<<endl;
        }
        else
        {
            cout<<"Do-it-Not"<<endl;
        }
    }
    return 0;
}                                 