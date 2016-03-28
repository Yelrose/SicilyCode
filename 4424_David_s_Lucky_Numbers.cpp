
// Problem#: 4424
// Submission#: 1067097
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <string>
#include <cmath>
#include <vector>
using namespace std;
vector<long long>k;
string plu(string a)
{
    int n = a.length() - 1;
    while(n >= 0)
    {
        if(a[n] - '0' + 1 > 1)
        {
            a[n] = '0';
            n --;
        }
        else{
            a[n] = '1';
            break;
        }
    }
    if(n < 0)
    {
        a = "1" + a;
    }
    return a;
}

void judge()
{
    string temp = "0";
    while(temp.length() < 11)
    {
        temp = plu(temp);
        int one =0;
        int zero = 0;
        for(int i = 0;i < temp.length();i ++)
        {
            if(temp[i] == '0')zero++;
            else one ++;
        }
        if(one == zero)
        {
            long long Temp = 0;
            for(int i = 0;i < temp.length();i ++)
            {
                if(temp[i] == '0')Temp += 4 * (pow(10,i)) ;
                else Temp += 7 * (pow(10,i));
            }
            k.push_back(Temp);
            Temp = 0;
            for(int i = 0;i < temp.length();i ++)
            {
                if(temp[i] == '0')Temp += 7 * (pow(10,i)) ;
                else Temp += 4 * (pow(10,i));
            }
            k.push_back(Temp);
        }
    }

}

void judge2()
{
    long long n;
    cin >> n;
    long long min = 7777744444;
    vector<long long>::iterator it;
    it = k.begin();
    /*for(int i = 0;i < z;i ++)
    {
        if(k[i]=4444477777)cout << " YES" << endl;
    }*/
    for(;it <= k.end();it ++)
    {
        //if(*it == 4444477777)cout << *it <<"nimei"<< endl;
        if(*it >= n && *it < min)
        min = * it;
        //cout << *it << " ||";
    }
    cout << min << endl;

}

int main()
{
    judge();
    int n;
    cin >> n;
    for(int i = 0;i < n;i ++)
    {
        judge2();
    }

}                                 