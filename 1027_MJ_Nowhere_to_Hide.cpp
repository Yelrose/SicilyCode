
// Problem#: 1027
// Submission#: 898916
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include<iostream>
#include<string>

using namespace std;
string real[100][10];
string ip[20];
string mj[100][10];
void sort();
string all[20];
int k=0;
int n[100];
int main()
{

    
    while(cin>>n[k])
    {
        if(n[k]==0)break;
        for(int i=0;i<n[k];i++)
            cin>>all[i]>>ip[i];
        int c=0;
        for(int i=0;i<n[k]-1;i++)
        {
            for(int j=i+1;j<n[k];j++)
                if(ip[i]==ip[j])
                {
                    real[k][c]=all[i];
                    mj[k][c]=all[j];
                    c++;
                }
        }
        sort();
    
        k++;
    }
    for(int i=0;i<(k);i++)
    {
        for(int j=0;j<(n[i]/2);j++)
            cout<<mj[i][j]<<" is the MaJia of "<<real[i][j]<<endl;
        cout<<endl;
    }


}
void sort()
{
    for(int i=(n[k]/2)-1;i>=0;i--)
    {
        for(int j=0;j<i;j++)
            if(real[k][j]>real[k][(j+1)])
            {
                string temp=mj[k][j];
                mj[k][j]=mj[k][(j+1)];
                mj[k][(j+1)]=temp;
                temp=real[k][j];
                real[k][j]=real[k][(j+1)];
                real[k][(j+1)]=temp;
            }
    }
}                                 