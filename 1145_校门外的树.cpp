
// Problem#: 1145
// Submission#: 886345
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include<iostream>
using namespace std;
int a[100],b[100];
bool c[10001];
int main()
{
    int l,m;
    
    cin>>l>>m;
    int total=l+1;
    for(int i=0;i<m;i++)
        cin>>a[i]>>b[i];
    
    for(int i=0;i<=l;i++)
    {
        c[i]=0;
        for(int k=0;k<m;k++)
            if(i<=b[k]&&i>=a[k])
            {
                c[i]=true;
                break;
            }
    
    }
    int count=0;
    for(int i=0;i<=l;i++)
    {
        if(c[i])count++;
    }
    total=total-count;
    cout<<total<<endl;
    
}                                 