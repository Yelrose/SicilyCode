
// Problem#: 1036
// Submission#: 940069
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <string>
using namespace std;
string keyword;
string code;
char colum[101][101];
void judge ()
{
    int length = keyword.length();
    int codeleg = code.length();
    int numcol = codeleg / length;
    int count = 0;
    for(int i = 'A';i <= 'Z';i ++)
    {
        for(int col = 0;col < length;col ++)
        {
            if(keyword[col] == i)
            {
                for(int j = 0;j < numcol;j ++)
                {
                    colum[col][j] = code[count];
                    count ++;
                }
            }
        }
    }
    for(int i = 0;i < numcol;i ++)
    {
        for(int j = 0;j < length;j ++ )
            cout << colum[j][i];
    }
    cout << endl;
}
int main()
{
    while (cin >> keyword && keyword != "THEEND")
    {
        cin >> code;
        judge();
    }
}                                 