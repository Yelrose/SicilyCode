
// Problem#: 1561
// Submission#: 901421
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <cmath>
using namespace std;
int prime = 2;
int post = 1;

int main()
{
    int n;
    cin >> n;
    for(;post<n;post++)
    {
        while(1)
        {
            prime++;
            bool k=0;
            for(int i=2;i <= sqrt(prime); i++)
            {
                if(prime % i == 0)
                {
                    k=1;
                    break;
                }   

            }
            if(k == 0)break;



        }   

    }
    cout << prime << endl;
}                                 