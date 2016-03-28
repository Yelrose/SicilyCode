
// Problem#: 6345
// Submission#: 1651994
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
using namespace std;
int save[5] = {1,4,5,5,4};
int v[1000];
int w[1000];
int a[1000];
  int count;
  int n;
 int sum;
bool add(int i){
    if(i == n){

        return true;
    }
    a[i] ++;
    if(a[i] > w[i]){
        a[i] = v[i];
        sum -= (w[i] - v[i]);
        return add(i + 1);
    }
    else{
        sum ++;

        count += save[sum % 5];
    }
    return false;

}
int main(){

    cin >> n;
    sum = 0;
    count = 0;
    for(int i = 0;i < n;i ++){
        cin >> v[i] >> w[i];
        sum += v[i];
        a[i] = v[i];
    }
    count += save[sum % 5];

    while(!add(0)){}
    cout << count << endl;







}                                 