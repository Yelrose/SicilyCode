
// Problem#: 1157
// Submission#: 898555
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include<iostream>
using namespace std;
int b[10];
int k=0;
int main()
{
    int a[4];
    int n;
    while(cin>>n)
    {
        if(n==0)break;
        for(int i=0;i<n;i++)
            cin>>a[i];
        for(int i=0;i<(n-1);i++)
        {
            if(a[i]>a[(i+1)])a[(i+1)]=a[i];
        }
        b[k]=a[(n-1)];
        k++;
    }
    for(int i=0;i<k;i++)
        cout<<b[i]<<endl;
}                                 