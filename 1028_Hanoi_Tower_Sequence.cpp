
// Problem#: 1028
// Submission#: 1094648
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <string>
using namespace std;

string a;
int target;
void judge(int aa)
{
    cin >> a;
    int length = a.length();
    int count = 0;
    int mod = 0;
    int z = 0;
    while(z == 0){
    for(int i = 0;i < length;i ++)
    {
        int k = (a[i] - '0' + z * 10) / 2;
        z = (a[i] - '0' + z * 10) % 2;
        a[i] = k + '0';
    }
    count ++;
    if(z == 1)
    {
        if(aa > 1)cout << endl;
        cout << "Case " << aa << ": "<<count << endl;
        
        return ;
    }
    }
}

int main(){
    
    cin >> target;
    for(int i = 1;i <= target;i ++ )
    {
        judge(i);
    }
}                                 