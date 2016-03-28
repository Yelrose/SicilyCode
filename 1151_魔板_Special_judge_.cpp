
// Problem#: 1151
// Submission#: 936434
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <string>
#include <cstring>
using namespace std;
bool judge[50000];
int fact[] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320}; 
int encode(int n);  
struct State
{
    char state[9];
    string path;
}pro[100000];
char begin[9]="12348765";
char goal[9];
int next;
void A(int i)
{
    char temp[9];
    for(int j=0;j<4;j++)
    {
        temp[j]=pro[i].state[j+4];
        temp[j+4]=pro[i].state[j];
    }
    temp[8]='\0';
    int num=encode((temp[0]-48)*10000000+(temp[1]-48)*1000000+(temp[2]-48)*100000+(temp[3]-48)*10000+(temp[4]-48)*1000+(temp[5]-48)*100+(temp[6]-48)*10+(temp[7]-48));
    if(judge[num])return;
    judge[num]=true;
    strcpy(pro[next].state,temp);
    pro[next].path = pro[i].path;
    pro[next].path += 'A';
    next++;
}
void B(int i)
{
    char temp[9];
    temp[8]='\0';
    temp[0]=pro[i].state[3];
    temp[4]=pro[i].state[7];
    for(int j=1;j<4;j++)
    {
        temp[j]=pro[i].state[j-1];
        temp[j+4]=pro[i].state[j+3];
    }
    int num=encode((temp[0]-48)*10000000+(temp[1]-48)*1000000+(temp[2]-48)*100000+(temp[3]-48)*10000+(temp[4]-48)*1000+(temp[5]-48)*100+(temp[6]-48)*10+(temp[7]-48));
    if(judge[num])return;
    judge[num]=true;strcpy(pro[next].state,temp);
    pro[next].path = pro[i].path;
    pro[next].path += 'B';
    next++;
}
int encode(int n)  
{  
    int tmp[8];  
    int cnt;  
    for (int i = 7; i >= 0; i--)  
    {  
        tmp[i] = n%10;  
        n /= 10;  
    }  
    for (int i = 0; i < 7; i++)  
    {  
        cnt = 0;  
        for (int j = i+1; j < 8; j++)  
            if (tmp[i] > tmp[j]) cnt++;  
        n += fact[8-i-1] * cnt;  
    }  
    return n;  
}  


void C(int i)
{
    char temp[9];
    temp[8]='\0';
    strcpy(temp,pro[i].state);
    temp[1]=pro[i].state[5];
    temp[2]=pro[i].state[1];
    temp[5]=pro[i].state[6];
    temp[6]=pro[i].state[2];
    int num=encode((temp[0]-48)*10000000+(temp[1]-48)*1000000+(temp[2]-48)*100000+(temp[3]-48)*10000+(temp[4]-48)*1000+(temp[5]-48)*100+(temp[6]-48)*10+(temp[7]-48));
    if(judge[num])return;
    judge[num]=true;
    strcpy(pro[next].state,temp);
    pro[next].path = pro[i].path;
    pro[next].path += 'C';
    next++;
}
void bfs()
{
    next=1;
    strcpy(pro[0].state,begin);
    pro[0].path="";
    int mm;
    int m=0;
    int num=encode((begin[0]-48)*10000000+(begin[1]-48)*1000000+(begin[2]-48)*100000+(begin[3]-48)*10000+(begin[4]-48)*1000+(begin[5]-48)*100+(begin[6]-48)*10+(begin[7]-48));
    judge[num]=true;
    while(next<40320)
    {
        mm=m;
        m=next;
        for(int i=mm;i<m;i++)
        {
            A(i);
            B(i);
            C(i);
        }
    }
}
int main()
{
    bfs();
    int n;
    while(cin>>n)
    {
        if(n==-1)break;
        for(int i=0;i<8;i++)
            cin>>goal[i];
        bool Findle=false;
        for(int i=0;i<40320;i++)
        {
            if(strcmp(goal,pro[i].state)==0)
            {
                Findle=true;
                if(pro[i].path.length() > n)cout<< "-1"<<endl;
                else cout<<pro[i].path.length()<<" "<<pro[i].path<<endl;
            }
        }
        if(!Findle)cout<<"-1"<<endl;
    }
}                                 