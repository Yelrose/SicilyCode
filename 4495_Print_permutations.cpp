
// Problem#: 4495
// Submission#: 1099366
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <cstring>
using namespace std;

char a[8];
bool b[8];
char c[8];
int goal;
void print(int n)
{
     if(n == goal)
     {
          cout << a << endl;
          return;
     }
     for(int i = 0;i < goal;i ++)
     {
             if(!b[i]){
                       b[i] = true;
                       a[n] = c[i];
                       print(n + 1);
                       b[i] = false;
             }
     }     
}

int main()
{
    memset(b,0,sizeof(b));
    cin >> c;
    goal = strlen(c);
    print(0);
    //system("pause");
}                                 