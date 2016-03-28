
// Problem#: 1509
// Submission#: 967487
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
using namespace std;
int goal[1001];
int store[1001];
int start[1001];
void judge(int n)
{
    for(int i = 2; i <= n;i ++)
    {
        cin >> goal[i];
    }
    int num_store = 0;
    int position = 1;
    for(int i = 1;i <= n;i ++)
    {
        if(goal[i] == store[num_store])
        {
            num_store --;
        }
        else
        {
            while(goal[i] != start[position])
            {
                num_store ++;
                store[num_store] = start[position];
                position ++;
                if(position > n)
                {
                    cout << "No" << endl;
                    return;
                }
            }
            position ++;
        }
    }
    cout << "Yes" << endl;
}

void judge2(int n)
{
    while(cin >> goal[1] && goal[1] != 0)
    {
        judge(n);
    }
    cout << endl;
}
int main()
{
    for(int i = 0;i <= 1000; i ++)
    {
        start[i] = i;
    }
    int n;
    while(cin >> n && n != 0)
    {
        judge2(n);
    }
}                                 