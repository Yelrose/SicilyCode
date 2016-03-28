
// Problem#: 4875
// Submission#: 1234757
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
// Problem#: 4875
// Submission#: 1234544
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
#include <cstring>
using namespace std;
int x_now[200001];
int y_now[200001];
int x_left[200001];
int x_right[200001];
int y_up[200001];
int y_down[200001];

long long sum;
int now_x;
int now_y;
int abs(int n){
    if(n < 0) return -n;
    return n;
}

void S(){
    sum =sum + y_down[now_y] + y_now[now_y] - y_up[now_y];
    printf("%lld\n",sum);
    now_y ++;
    if(y_down[now_y] == 0 && y_up[now_y] == 0){
        y_down[now_y] = y_down[now_y - 1] + y_now[now_y - 1];
        y_up[now_y] = y_up[now_y - 1] - y_now[now_y];
    }
}

void I(){
    sum = sum + x_left[now_x] + x_now[now_x] - x_right[now_x];
    printf("%lld\n",sum);
    now_x ++;
    if(x_left[now_x] == 0 && x_right[now_x] == 0){
        x_left[now_x] = x_left[now_x - 1] + x_now[now_x - 1];
        x_right[now_x] = x_right[now_x - 1] - x_now[now_x];
    }
}

void J(){
    sum = sum + y_up[now_y] + y_now[now_y] - y_down[now_y];
    printf("%lld\n",sum);
    now_y --;
    if(y_down[now_y] == 0 && y_up[now_y] == 0){
        y_down[now_y] = y_down[now_y + 1] - y_now[now_y + 1];
        y_up[now_y] = y_up[now_y + 1] + y_now[now_y];
    }

}

void Z(){
    sum = sum + x_right[now_x] + x_now[now_x] - x_left[now_x];
    printf("%lld\n",sum);
    now_x --;

    if(x_left[now_x] == 0 && x_right[now_x] == 0){
        x_left[now_x] = x_left[now_x + 1] - x_now[now_x + 1];
        x_right[now_x] = x_right[now_x + 1] + x_now[now_x];
    }
}



int main(){
    sum = 0;
    int sum_x = 0;
    int sum_y = 0;
    now_x = 100000;
    now_y = 100000;
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i = 0;i < n;i ++){
        int a,b;
        scanf("%d %d",&a,&b);
        if(a < 0)sum_x ++;
        if(b < 0)sum_y ++;
        x_now[a + 100000] ++;
        y_now[b + 100000] ++;
        sum += (abs(a) + abs(b));
    }
    x_left[100000] = sum_x;
    x_right[100000] = n - sum_x - x_now[100000];
    y_down[100000] = sum_y;
    y_up[100000] = n - sum_y - y_now[100000];
    char c;
    scanf("%c",&c);
    for(int i = 0;i < m;++ i){
        scanf("%c",&c);
        switch(c){
            case 'S': S();break;
            case 'I': I();break;
            case 'J': J();break;
            case 'Z': Z();break;
        }
    }

}                                 