
// Problem#: 1926
// Submission#: 1095845
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
class NumCal {
    int *p;    // 数组首地址
    int size; // 数组size
public:
    NumCal() // 构造函数
    {
        size = 0;
    }
    NumCal(int *new_p, int new_size) // 构造函数
    {
        p = new_p;
        size = new_size;
    }
    int sum(){
        int a = 0;
        for(int i = 0;i < size;i ++)
        {
            a += *(p + i);
        }
        return a;
    }
};                                 