
// Problem#: 1082
// Submission#: 1803216
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <set>
using namespace std;


int q[10001];
int rq[10001];
bool first;


int main()
{
    int Max;
    first = false;
    while(cin >> Max)
    {
        int len;
        cin >> len;
        for(int i = 0; i < len; i++)
            cin >> q[i];
        char ch;
        set<int> s;
        int flag = 1;
        int position = 1;
        while(cin >> ch && ch != 'e')
        {
            if(ch == 'a')
            {
                int tmp;
                cin >> tmp;
                s.insert(tmp);
            }
            else if(ch == 'p')
            {
                cin >> flag;
            }
            else if(ch == 'r')
            {
                if(flag == 1)
                {
                    rq[position++] = *s.begin();
                    s.erase(s.begin());
                }
                else
                {
                    rq[position++] = *(--s.end());
                    s.erase(--s.end());
                }
            }

        }


        if(!first)
            first = true;
        else
            cout << endl;
        for(int i = 0; i < len; i++)
        {
            cout << rq[q[i]] << endl;
        }
    }
    return 0;
}                                 