
// Problem#: 1020
// Submission#: 941777
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <string>
#include <cstring>
using namespace std;
char Bigint[401];
char b[401];
int divide[101];
void Divide(char *a,int i)
{
    if(i < 10)
    {
        int k = 1;
        while(*(a + k) != '\0')
        {
            int b = (*(a + k - 1) - '0') * 10 +*(a + k) - '0';
            *(a + k) = b % i + '0';
            k ++;
        }
        cout << (*(a + k - 1));
    }
    else if(10 <= i && i < 100)
    {
        int k = 2;
        while(*(a + k) != '\0')
        {
            int b = (*(a + k - 2) - '0') * 100 + (*(a + k -1) - '0') * 10 + (*(a + k) -'0');
            *(a + k) = (b % i)  % 10 + '0';
            *(a + k - 1) = (b % i) / 10 + '0';
            k ++;
        }
        if(*(a + k - 2) == '0')
            cout << *(a + k - 1);
        else cout << *(a + k - 2) << *(a + k - 1);
    }
    else if(i >= 100 && i < 1000)
    {
        int k = 3;
         while(*(a + k) != '\0')
        {
            int b = (*(a + k - 3) - '0') * 1000 + (*(a + k - 2) - '0') * 100 + (*(a + k -1) - '0') * 10 + (*(a + k) -'0');
            *(a + k) = (b % i)  % 10 + '0';
            *(a + k - 1) = ((b % i) / 10) % 10 + '0';
            *(a + k - 2) = (b % i) / 100 + '0';
            k ++;
        }
        if(*(a + k - 3) == '0')
        {
                if(*(a + k - 2) == '0')
                    cout << *(a + k - 1);
                else cout << *(a + k - 2) << *(a + k - 1);
        }
        else cout << *(a + k - 3) << *(a + k - 2) << *(a + k - 1);

    }
    else cout << a[strlen(a) - 3] << a[strlen(a) - 2] << a[strlen(a) - 1];
}
void judge()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i ++)
   {
       cin >> divide[i];
   }
    cin >> Bigint;
    cout << "(" ;
    for(int i = 0; i < n; i ++)
    {
        strcpy( b , Bigint);
        Divide(b , divide[i]);
        if(i == n - 1);
        else cout << ",";
    }
    cout << ")";
    cout << endl;

}
int main()
{
    int n;
    cin >> n;
    for(int i = 0;i < n; i++ )
    {
        judge();
    }
}                                 