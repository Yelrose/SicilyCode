
// Problem#: 1147
// Submission#: 894880
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include<iostream>
using namespace std;
int n;
int g = 0;
int count = 0;
void judge(int i);
void sort();
int sum();
char name[100][20];
int sco1[100];
int sco2[100];
char leader[100];
char west[100];
int passage[100];
int money[100];
int main()
{
    cin >> n;
    for(int i = 0;i < n; i++)
    {
        cin >> name[i] >> sco1[i] >> sco2[i] >> leader[i] >> west[i] >> passage[i];
        judge(i);
    }

    
    sort();
    cout << name[g] <<endl;
    cout << money[g] << endl;
    cout << sum() << endl;
    return 0;
}
void judge(int i)
{
    money[i] = 0;
    if(sco1[i] > 80 && passage[i] >= 1) money[i] += 8000;
    if(sco1[i] > 85 && sco2[i] >80) money[i] += 4000;
    if(sco1[i] > 90) money[i] += 2000;
    if(sco1[i] > 85 && west[i] == 'Y') money[i] += 1000;
    if(sco2[i] > 80 && leader[i] == 'Y') money[i] += 850;
}
void sort()
{
    int ii=0;
    for(int i = 0; i < n; i++ )
    {
        if(money[ii] < money[i]) ii =i;
        

    }
    g=ii;
    
}
int sum()
{
    int Sum = 0;
    for(int i = 0;i < n;i++)
        Sum = Sum + money[i];
    return (Sum);
}                                 