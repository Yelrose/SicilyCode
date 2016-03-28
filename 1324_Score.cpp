
// Problem#: 1324
// Submission#: 963483
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <string>
using namespace std;
void judge()
{
    string score;
    cin >> score;
    int a = score.length();
    int count = 0;
    int sum = 0;
    for(int i = 0; i < a;i ++)
    {
        if(score[i] == 'O')count ++;
        if(score[i] == 'X')count = 0;
        sum += count;
    }
    cout << sum << endl;
}
int main()
{
    int n;
    cin >> n;
    for(int i = 0;i < n;i ++)
    {
        judge();
    }
}                                 