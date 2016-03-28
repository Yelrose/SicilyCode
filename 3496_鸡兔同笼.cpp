
// Problem#: 3496
// Submission#: 976398
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
using namespace std;
void find(int m,int n)
{
        int k1 = 4 * m - n;
        int k2 = n - 2 * m;
        if(k1 % 2 != 0 || k1 < 0){
            cout << "No answer" << endl;
            return;
        }
        if(k2 % 2 != 0 || k2 < 0){
            cout << "No answer" << endl;
            return;
        }
        cout << k1 / 2 <<" "<<k2 /2<<endl;

}

int main()
{
    int m,n;
    while(cin >> m >> n && !(m == 0 && n == 0))
    {
              find(m,n);
    }
}                                 