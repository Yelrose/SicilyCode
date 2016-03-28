
// Problem#: 1006
// Submission#: 1008485
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <ctime>
#include <algorithm>
#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
using namespace std;

string judge[100];
string all[120] = {"ABCDE","ABCED","ABDCE","ABDEC","ABECD","ABEDC","ACBDE","ACBED","ACDBE","ACDEB",
"ACEBD","ACEDB","ADBCE","ADBEC","ADCBE","ADCEB","ADEBC","ADECB","AEBCD","AEBDC",
"AECBD","AECDB","AEDBC","AEDCB","BACDE","BACED","BADCE","BADEC","BAECD","BAEDC",
"BCADE","BCAED","BCDAE","BCDEA","BCEAD","BCEDA","BDACE","BDAEC","BDCAE","BDCEA",
"BDEAC","BDECA","BEACD","BEADC","BECAD","BECDA","BEDAC","BEDCA","CABDE","CABED",
"CADBE","CADEB","CAEBD","CAEDB","CBADE","CBAED","CBDAE","CBDEA","CBEAD","CBEDA",
"CDABE","CDAEB","CDBAE","CDBEA","CDEAB","CDEBA","CEABD","CEADB","CEBAD","CEBDA",
"CEDAB","CEDBA","DABCE","DABEC","DACBE","DACEB","DAEBC","DAECB","DBACE","DBAEC",
"DBCAE","DBCEA","DBEAC","DBECA","DCABE","DCAEB","DCBAE","DCBEA","DCEAB","DCEBA",
"DEABC","DEACB","DEBAC","DEBCA","DECAB","DECBA","EABCD","EABDC","EACBD","EACDB",
"EADBC","EADCB","EBACD","EBADC","EBCAD","EBCDA","EBDAC","EBDCA","ECABD","ECADB",
"ECBAD","ECBDA","ECDAB","ECDBA","EDABC","EDACB","EDBAC","EDBCA","EDCAB","EDCBA",
};
int sum[120];
int distanc(int n,int m)
{
    int c[5];
    for(int i = 0;i < 5;i ++)
    {
        for(int j = 0;j < 5;j ++)
        {
            if(all[n][i] == judge[m][j])
            {
                c[i] = j;
                break;
            }
        }
    }
    int count = 0;
    for(int i = 0;i < 5;i ++)
    {
        for(int j = 0;j < i;j ++)
        {
            if(c[j] > c[i])count ++;
        }
    }
    return count;
}

int main()
{
    int n;
    int min_num = 0;
    int sum1 = 99999;

       while( cin >> n && n!= 0){
        min_num = 0;
        sum1 = 99999;



        for(int i = 0;i < n;i ++)
        {
            cin >> judge[i];
            //cout << distanc(0,0);
        }

        for(int i = 0;i < 120;i ++)
        {
            //cout << "x";
            sum[i] = 0;
            for(int j = 0;j < n;j ++)
            {
                //cout << sum[i] << endl;
                //cout << "i  "<< i <<" j  " << j << " "<< distanc(i,j) << endl;
                sum[i] += distanc(i,j);
            }
            //cout << sum[i] << " " << i << endl;
            //cout << "k";
            if(sum[i] < sum1)
            {
                sum1 = sum[i];
                min_num = i;
            }
        }
        cout << all[min_num] << " is the median ranking with value " << sum1 << "." << endl;

       }
       return 0;
}                                 