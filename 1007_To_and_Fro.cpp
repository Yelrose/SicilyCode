
// Problem#: 1007
// Submission#: 888957
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include<iostream>
using namespace std;
char str[100][20];
char a[1000][200];
int main()
{
    int b=0;
    int cow;
    int row;
    while(cin>>cow)
    {
        if(cow==0)break;
        cin>>a[b];
        int f=0;
        while(a[b][f]!='\0')
            f++;
        row=f/cow;
        int go=0;
        for(int i=0;i<row;i++)
        {
            if((i%2)==0){
            for(int j=0;j<cow;j++)
            {
            str[i][j]=a[b][go];
                go++;
            }
            }
            else if((i%2)==1)
            {
                int j=cow-1;
                for(;j>=0;j--)
                    {
                        str[i][j]=a[b][go];
                        go++;
                    }       

            }
        }
        go=0;
        for(int i=0;i<cow;i++)
        {
            for(int j=0;j<row;j++)  
            {
                a[b][go]=str[j][i];
                go++;
            }
        }
        b++;
    }
    for(int i=0;i<b;i++)
    {
        cout<<a[i]<<endl;
    }
    return 0;

}                                 