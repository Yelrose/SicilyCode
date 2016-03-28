
// Problem#: 2000
// Submission#: 888002
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include<iostream>
using namespace std;
double a[25000];
int j[25000];
int p[25000];
int b[25000];
void QuickSort(int s,int e);
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>j[i]>>p[i];
        a[i]=((double)j[i])/p[i];
        b[i]=i+1;
    }
    QuickSort(0,(n-1));
    int sum=p[0]+p[1]+p[2];
    cout<<sum<<endl;
    cout<<b[0]<<endl;
    cout<<b[1]<<endl;
    cout<<b[2]<<endl;
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
        double key=a[l];
        while(l<r)
        {
            while(l<r)
            {
                if(a[r]>key)
                {
                    double copy=a[r];
                    a[r]=a[l];
                    a[l]=copy;
                    int Co=b[r];
                    b[r]=b[l];
                    b[l]=Co;
                    Co=p[r];
                    p[r]=p[l];
                    p[l]=Co;
                    l++;
                    break;
                }
                else r--;
            }
            while(l<r)
            {
                if(a[l]<key)
                {
                    double copy=a[r];
                    a[r]=a[l];
                    a[l]=copy;
                    int Co=b[r];
                    b[r]=b[l];
                    b[l]=Co;
                    Co=p[r];
                    p[r]=p[l];
                    p[l]=Co;
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