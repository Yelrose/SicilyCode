
// Problem#: 11350
// Submission#: 2975616
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
using namespace std;
int N;
double pw;
double vwi[100010];
double pfi[100010];
double vfi[100010];
double thi[100010];
struct node{
  double A;
  double B;
  double W;
  int direct;
}all[100010];
bool cmp(const node a,const node b) {
  return a.W < b.W;
}
int main() {
  while(~scanf("%d",&N) ) {
    int sz = 0;
    if(N == 0) break;
    scanf("%lf",&pw);
    double A = pw;
    double B = 0;
    for(int i = 0;i < N;i ++ ) {
      scanf("%lf%lf%lf%lf",&vwi[i],&pfi[i],&vfi[i],&thi[i]);
      
      if(vwi[i] ==0) {
     double aaa = max(0.0,pfi[i] *thi[i] / vfi[i]);
    B += aaa;
     
    continue; 

      }
      double xequ0 = thi[i] / vwi[i];
      if(xequ0 < 0) {
    if(-vwi[i] < 0) {
    }
    else {
        A += pfi[i] * (-vwi[i]/vfi[i]);
        B += pfi[i] * thi[i] /vfi[i];
    }
    xequ0 = 0;
    continue;
      }
      all[sz].A =  pfi[i] * ( -vwi[i]/vfi[i]);
      all[sz].B = pfi[i] * thi[i] / vfi[i];
      all[sz].W = xequ0;
      all[sz].direct = ((-vwi[i]) > 0)?1: -1; 
      if(all[sz].direct == -1) {
    A += all[sz].A;
    B += all[sz].B;
      }
      sz ++;
    } 
    double minf = A*0 + B;
    sort(all,all + sz,cmp);
    for(int i = 0; i< sz;i ++) {
      A += all[i].A * all[i].direct;
      B += all[i].B * all[i].direct;
      minf = min(minf,A* all[i].W + B);
    }
    printf("%.4lf\n",minf); 

    
  }  
}                                 