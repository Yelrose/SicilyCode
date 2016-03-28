
// Problem#: 1194
// Submission#: 888291
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include<iostream>
#include<cstring>
using namespace std;
int n,m;
char a[20000][10];
char b[20000][10];
int c[1000];
int d=0;
void QuickSort(int s,int e);
void MakeLower(char k[10]);
int Find();
int main()
{
    while(1)
    {
        cin>>n;
        if(n==0)break;
        cin>>m;
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            MakeLower(a[i]);
        }
        for(int i=0;i<m;i++)
        {
            cin>>b[i];
            MakeLower(b[i]);
        }
        QuickSort(0,(m-1));
            c[d]=Find();
        c[d]=n-c[d];
        d++;
    }
    for(int i=0;i<d;i++)
        cout<<c[i]<<endl;
    return 0;

}
void QuickSort(int s,int e)
{   
    if(s>=e){
        return;
    }
    else
    {
        int l=s,r=e;
        char key[10];
        strcpy(key,b[l]);
        while(l<r)
        {
            while(l<r)
            {
                if(strcmp(b[r],key)<0)
                {
                    char copy[10];
                    strcpy(copy,b[r]);
                    strcpy(b[r],b[l]);
                    strcpy(b[l],copy);
                    l++;
                    break;
                }
                else r--;
            }
            while(l<r)
            {
                if(strcmp(b[l],key)>0)
                {
                    char copy[10];
                    strcpy(copy,b[r]);
                    strcpy(b[r],b[l]);
                    strcpy(b[l],copy);
                    r--;
                    break;
                }
                else l++;
            }   
        }
        
        QuickSort(s,(l-1));
        QuickSort((r+1),e);
    }

}
int Find()
{
    int count=0;
    for(int i=0;i<n;i++)
    {
        int s=0,e=m-1;
        while(s<=e)
        {
            int mid=(s+e)/2;
            if(strcmp(a[i],b[mid])==0)
            {
                count++;
                break;
            }
            else if(strcmp(a[i],b[mid])<0) e=mid-1;
            else if(strcmp(a[i],b[mid])>0) s=mid+1;
            
        }
    }

    return (count);

}
void MakeLower(char k[10])
{
    for(int i=0;i<10;i++)
    {
        if(k[i]>=65&&k[i]<=90)
            k[i]=k[i]+32;
    }
}                                 