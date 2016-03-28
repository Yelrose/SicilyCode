
// Problem#: 1154
// Submission#: 887358
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include<iostream>
using namespace std;
int a[2000][1001];
int t;
int main()
{   
    void Sort(int n);
    cin>>t;
    for(int i=0;i<t;i++)
    {
        cin>>a[i][0];
        for(int j=1;j<=a[i][0];j++)
            cin>>a[i][j];
        Sort(i);

    }
    for(int i=0;i<t;i++)
    {
        for(int j=1;j<=a[i][0];j++)
            cout<<a[i][j]<<endl;
    }
    return 0;

}
void Sort(int n)
{
    int j=a[n][0];
    for(int i=1;i<j;)
    {
        for(int k=1;k<j;k++)
        {
            if(a[n][k]>a[n][(k+1)])
            {
                int c=a[n][k];
                a[n][k]=a[n][(k+1)];
                a[n][(k+1)]=c;
            }
            
        }
        j--;
    }
}                                 