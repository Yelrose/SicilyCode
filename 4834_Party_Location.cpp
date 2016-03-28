
// Problem#: 4834
// Submission#: 1224287
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
// Problem#: 4834
// Submission#: 1222028
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <cmath>
#define R 2.500
using namespace std;

struct point{
    double x;
    double y;
}All[1000];

void find(point & A,point & B,point & C,point & D){
    double mid_x = (A.x + B.x) / 2;
    //cout << "mid_x=" << mid_x <<endl;
    double mid_y =(A.y + B.y) / 2;
     //cout << "mid_y=" << mid_y <<endl;
    double dis = pow((A.x - B.x),2) + pow((A.y - B.y) , 2);
    dis = sqrt(dis);
    dis /= 2;
    dis = pow(dis,2);
    double bian = pow(R,2) - dis;
    bian = sqrt(bian);
    double di = pow((A.x - B.x),2) + pow((A.y - B.y) , 2);
    di = sqrt(di);
    if(di > 0){
        double si =  (A.x - B.x) / di;
        double co = (B.y - A.y) / di;
        double y = bian * si;
        double x = bian * co;

    C.x = mid_x  + x;
    C.y = mid_y + y;
    D.x =mid_x - x;
    D.y = mid_y - y;

     }
  else {
    C.x = mid_x ;
    C.y = mid_y ;
    D.x = mid_x ;
    D.y = mid_y ;

    }

}



int main(){
        int n = 0;
        while(cin >> All[n].x >> All[n].y){
          
            n ++;
        }

        int max = 0;
        for(int i = 0;i < n;i ++){
            for(int j = 0;j < n;j ++){
                if(sqrt(pow((All[i].x - All[j].x),2) + pow((All[i].y - All[j].y) , 2)) <= 5.000001){

                    point C;
                    point D;
                    find(All[i],All[j],C,D);
                    //cout << C.x << " " << C.y << endl;
                    int count  = 0;

                        for(int k = 0;k < n;k ++){
                            if(sqrt(pow(All[k].x - C.x,2) + pow(All[k].y - C.y,2)) <= 2.500001)
                            {
                            count  ++;
                            }
                        }

                    if(count > max) max = count;
                    count  = 0;

                        for(int k = 0;k < n;k ++){
                            if(sqrt(pow(All[k].x - D.x,2) + pow(All[k].y - D.y,2)) <= 2.500001)
                            { 
                                count  ++;
                            }
                        }

                    if(count > max) max = count;
                }
            }
        }
        cout << max << endl;
       // system("pause");

}                                 