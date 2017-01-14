#ifndef LCS_H
#define LCS_H

#include <iostream>
#include <string>

class LCS
{
private:
    std::string str1;//字符串2
    std::string str2;//字符串1
    int len1;//字符串1的长度
    int len2;//字符串2的长度
    int **b;//记录指示c[i,j]的值是哪一个子问题的解得到
    int **c;//c[i,j]存储str1前i个字符构成的子串与str2前j个字符构成的子串的LCS的长度
    int LCSLength;//最长公共子序列的长度
protected:
    void printLCS(int i, int j) const;//递归地打印出LCS
public:
    LCS();//构造函数，读取字符串，分配内存
    ~LCS();//析构函数，释放内存
    void getLCS();//获取LCS
    void getLCSLength() const;//返回LCS的长度
    void printLCS() const;//输出LCS
};

#endif