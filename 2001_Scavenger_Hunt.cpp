
// Problem#: 2001
// Submission#: 918439
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include<iostream>
using namespace std;
int P[6000],Q[6000];
int p,q;
int main()
{
    cin>>p>>q;
    int n=1;
    int i=0;
    while(n<=p)
    {
        if(p%n==0)
        {
            P[i]=n;
            i++;
        }
        n++;        
    }
    n=1;
    int j=0;
    while(n<=q)
    {
        if(q%n==0)
        {
            Q[j]=n;
            j++;
        }
        n++;        
    }
    for(int k=0;k<i;k++)
    {
        for(int l=0;l<j;l++)
        {
            cout<<P[k]<<" "<<Q[l]<<endl;
        }
    }
}                                 