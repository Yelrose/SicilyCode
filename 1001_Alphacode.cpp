
// Problem#: 1001
// Submission#: 888968
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include<iostream>
using namespace std;
long Fabo(long n)
{
    long i=1,j=1;
    if(n==1)return 1;
    else
    {
        for(long k=1;k<n;k++)
        {
            long c=i;
            i=j;
            j=c+j;
        }
        return (j);
    }

}

int main()
{   
    char a[10000];
    long n=0;
    long k[2000];
    while(1)
    {
        
        long g=1;
        long h=1;
        long num=0;
        
        cin>>a;
        if(a[0]=='0')break;
        for(;a[num]!='\0';num++);
        for(long i=1;i<num;i++)
        {
            
            if(a[(i-1)]=='1'&&a[i]!='0')
            {
                g=g+1;
                if(a[(i+1)]=='0')
                {   
                    g=g-1;
                    h=Fabo(g)*h;
                    g=1;
                }
                else if(a[(i+1)]=='\0')
                {
                    h=Fabo(g)*h;
                    g=1;
                }
            }
            else if(a[(i-1)]=='2'&&a[(i)]<='6'&&a[(i)]!='0')
            {
                g=g+1;
                if(a[(i+1)]=='0')
                {   
                    g=g-1;
                    h=Fabo(g)*h;
                    g=1;
                }
                else if(a[(i+1)]=='\0')
                {
                    h=Fabo(g)*h;
                    g=1;
                }
            }
            else 
            {
                h=Fabo(g)*h;
                g=1;
            }
        }
        k[n]=h;
        n++;
    }
    for(long i=0;i<n;i++)
        cout<<k[i]<<endl;
    return 0;

}                                 