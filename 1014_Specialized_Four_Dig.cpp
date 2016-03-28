
// Problem#: 1014
// Submission#: 891600
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include<iostream>
using namespace std;
int n=2992;
int k;
int a1,b1,c1,d1;
int a2,b2,c2,d2;
void judge();
int main(){
    while(n<10000)
    {
        k=n%10+(n/10)%10+(n/100)%10+n/1000;
        judge();
        n++;
    }
    return 0;

}
void judge()
{
    a1=n/1728;
    b1=n%1728/144;
    c1=n%1728%144/12;
    d1=n%12;
    a2=n/4096;
    b2=n%4096/256;
    c2=n%4096%256/16;
    d2=n%16;
    if((a1+b1+c1+d1)==k)
    {
        if((a2+b2+c2+d2)==k)
            cout<<n<<endl;

    }
}                                 