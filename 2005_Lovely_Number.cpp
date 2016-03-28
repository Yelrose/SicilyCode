
// Problem#: 2005
// Submission#: 925497
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include<iostream>
#include <algorithm>
using namespace std;
int n;
int num[10001];
int Case[1000];
int k=0;
int main()
{
    while(cin>>n)
    {
    
        for(int i=0;i<n;i++)
            cin>>num[i];
        sort(num,num+n);
        int oden=1;
        int i=0;
        for(;i<n-1;i++)
        {
            if(num[i]==num[i+1])oden++;
            else if(num[i]!=num[i+1]&&oden%2==1)break;
            else if(num[i]!=num[i+1]&&oden%2==0)oden=1;
        }
        Case[k]=num[i];
        k++;
    }
    for(int i=0;i<k;i++)
    {
        cout<<Case[i]<<endl;
    }
}                                 