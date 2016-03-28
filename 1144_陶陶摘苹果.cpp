
// Problem#: 1144
// Submission#: 863993
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include<iostream>
using namespace std;
int main()
{
    int apple[10];
    for(int i=0;i<10;i++)
        cin>>apple[i];
    int n;
    cin>>n;
    n=n+30;
    int c=0;
    for(int k=0;k<10;k++)
    {
        if(n>=apple[k])
            c++;
    }
    cout<<c<<endl;
    return 0;

}                                 