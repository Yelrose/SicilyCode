
// Problem#: 1198
// Submission#: 891865
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include<iostream>
#include<cstring>
using namespace std;
int t,n;
char str[100][100];
char outp[1000][100];
void sort();
int main()
{
    cin>>t;
    int k=0;
    while(k<t)
    {
        cin>>n;
        for(int i=0;i<n;i++)
            cin>>str[i];
        sort();
        int j=0;
        for(int i=0;i<n;i++)
        {
            int ii=0;
            while(str[i][ii]!='\0')
            {
                outp[k][j]=str[i][ii];
                ii++;
                j++;
            }
        }
        k++;
        

    }
    for(k=0;k<t;k++)
        cout<<outp[k]<<endl;
    return 0;

}
void sort()
{
    for(int i=n-1;i>=0;i--)
    {
        for(int j=0;j<i;j++)
        {
            char c[100],d[100],e[100];
            strcpy(c,str[j]);
            strcpy(d,str[(j+1)]);
            strcpy(e,c);
            strcat(c,d);
            strcat(d,e);
            if(strcmp(c,d)>0)
            {
                char temp[100];
                strcpy(temp,str[j]);
                strcpy(str[j],str[(j+1)]);
                strcpy(str[(j+1)],temp);
            }
        }

    }
}                                 