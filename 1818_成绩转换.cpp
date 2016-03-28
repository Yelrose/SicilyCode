
// Problem#: 1818
// Submission#: 980079
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

map<string,int>stu;

void output(int i)
{
    if(i > 100 || i < 0)
    {
        cout << "Score is error!"<<endl;
    }
    else if(i >= 90)
    {
        cout << "A" <<endl;
                //cout << stu[i].score;
    }
    else if(i >= 80)
    {
        cout << "B" <<endl;
    }
    else if(i >= 70)
    {
        cout << "C" << endl;
    }
    else if(i >= 60)
    {
         cout << "D" <<endl;
    }
    else
    {
        cout << "E" <<endl;
    }
}

void input()
{
    int n,m;
    cin >> n >> m;
    string a;
    int b;
    for(int i = 0;i < n; i ++)
    {
        cin >> a >> b;
        stu[a] = b;
    }
    for(int i = 0;i < m; i ++)
    {
        cin >> a;
        output(stu[a]);
    }
    return;
}

int main()
{
    int n;
    cin >> n;
    for(int i = 0;i < n;i ++)
    {
        input();
    }
}                                 