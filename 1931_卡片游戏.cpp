
// Problem#: 1931
// Submission#: 1026824
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <queue>
using namespace std;

void judge(int n)
{
    queue<int> all;
    for(int i = 1;i <= n;i ++)
    {
        all.push(i);
    }
    while(all.size() > 1)
    {
        cout << all.front() << " ";
        all.pop();
        int b = all.front();
        all.pop();
        all.push(b);
    }
    cout << all.front() << " " << endl;
}

int main()
{
    int n;
    cin >> n;
    int k;
    for(int i = 0;i < n;i ++)
    {
        cin >> k;
        judge(k);
    }
    return 0;
}                                 