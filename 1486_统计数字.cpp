
// Problem#: 1486
// Submission#: 1055109
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <cstring>
#include <stdio.h>
#include <map>
#include <algorithm>
#include <cstring>
using  namespace std;

int array[200000];

//bool a[200000];


void judge(int n)
{
    //memmet(a,0,sizeof(a));
    //memset(re,0,sizeof(re));
    for(int i = 0;i < n;i ++)
    {
        scanf("%d",&array[i]);
    }
    sort(array,array + n);
    printf("%d ",array[0]);
    int count = 1;
    for(int i = 1;i < n;i ++)
    {

        if(array[i] != array[i - 1])
        {
            printf("%d\n",count);
            printf("%d ",array[i]);
            count = 1;
        }
        else count ++;
    }
    printf("%d\n",count);

}
int main()
{
    int n;
    cin >> n;
    while(1)
    {

        judge(n);
        if(cin >> n)
        {
            cout << endl;
        }
        else{
            break;
        }
    }
}                                 