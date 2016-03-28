
// Problem#: 1031
// Submission#: 1202371
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <string>
#include <map>
#include <queue>
using namespace std;

struct road{
    string Si;
    string Ti;
    int d;
};
int n;
road All[100];
map<string , int > color;
map<string , int > distant;
void inputroad(){

    cin >> n;
    string temp;
    color.clear();
    distant.clear();
    for(int i = 0;i < n;i ++)
    {
        cin >> temp;
        color[temp] = 0;
        distant[temp] = 99999999;
        All[i].Si = temp;
        cin >> temp;
        color[temp] = 0;
        distant[temp] = 99999999;
        All[i].Ti = temp;
        int d;
        cin >> d;
        All[i].d = d;
    }
}

void minroad()
{
    string start;
    string termin;
    cin >> start >> termin;
    if(color.count(start) == 0 && start == termin){
        cout << "0" << endl;
        return;
    }
    else if(color.count(start) == 0){
        cout << "-1" << endl;
        return;
    }
    color[start] = 1;
    distant[start] = 0;
     while(1)
     {
        // cout << "k" << endl;
        map<string ,int >::iterator it = color.begin();
        bool find = false;
        while(it != color.end())
        {
            //cout << it -> first << " " << it -> second << endl;
            if(it -> second == 1)
            {
                find = true;
                break;
            }
            it ++;
        }
        //cout << "color" << color[start] << endl;
        //cout << find << endl;
        if(find == false)break;
        it -> second = 2;
        for(int i = 0;i < n;i ++)
        {
            if(All[i].Si == it -> first)
            {
                if(color[All[i].Ti] == 0)
                {
                    if(distant[All[i].Ti] > distant[it -> first] + All[i].d)
                    {
                        distant[All[i].Ti] = distant[it -> first] + All[i].d;
                    }
                }
            }
            if(All[i].Ti == it -> first)
            {
                if(color[All[i].Si] == 0)
                {
                    if(distant[All[i].Si] > distant[it -> first] + All[i].d)
                    {
                        distant[All[i].Si] = distant[it -> first] + All[i].d;
                    }
                }
            }
        }
        string minstr = "012";
        int min = 99999999;
        map<string ,int >::iterator begin = distant.begin();
        while(begin != distant.end())
        {
            if(begin -> second < min)
            {
                if(color[begin -> first] == 0)
                {
                    minstr = begin -> first;
                    min = begin -> second;
                }
            }
            begin ++;
        }
         //cout << minstr << endl;
        if(minstr != "012")
        {
           // cout << minstr << endl;
            color[minstr] = 1;
        }
    }
    if(distant[termin] == 99999999)cout << "-1" << endl;
    else if(color.count(termin) == 0)cout << "-1" << endl;
    else cout << distant[termin] << endl;
    /*map<string ,int >::iterator it = distant.begin();

        while(it != distant.end())
        {
            cout << it -> first << "  " << it -> second << endl;
            it ++;
        }*/
}

int main(){
    int N;
    cin >> N;
    for(int i = 0;i < N;i ++){
    inputroad();
    minroad();
    }
}                                 