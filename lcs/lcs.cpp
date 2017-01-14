#include "lcs.h"
using namespace std;

LCS::LCS():LCSLength(0)
{
    cout << "Please enter the 1st string:";
    cin >> str1;
    len1 = str1.length();
    cout << "Please enter the 2ed string:";
    cin >> str2;
    len2 = str2.length();
    b = new int*[len1 + 1];
    c = new int*[len1 + 1];
    for(int i = 0; i < len1 + 1; i++)
    {
        b[i] = new int[len2 + 1];
        c[i] = new int[len2 + 1];
    }
}

void LCS::getLCS()
{
    for(int i = 0; i < len1 + 1; i++)
        c[i][0] = 0;
    for(int i = 0; i < len2 + 1; i++)
        c[0][i] = 0;
    for(int i = 1; i < len1 + 1; i++)
        for(int j = 1; j < len2 + 1; j++)
        {
            if(str1[i - 1] == str2[j - 1])
            {
                c[i][j] = c[i - 1][j - 1] + 1;
                b[i][j] = 0;
            }
            else if(c[i - 1][j] > c[i][j - 1])
            {
                c[i][j] = c[i - 1][j];
                b[i][j] = 1;
            }
            else
            {
                c[i][j] = c[i][j - 1];
                b[i][j] = -1;
            }
        }
    LCSLength = c[len1][len2];
}

void LCS::getLCSLength() const
{
    cout << "The length of LCS is:" << LCSLength << endl;
}

void LCS::printLCS(int i, int j) const
{
    if(i == 0 || j == 0)
        return;
    if(b[i][j] == 0)
    {
        printLCS(i - 1, j - 1);
        cout << str1[i - 1];
    }
    else if(b[i][j] == 1)
        printLCS(i - 1, j);
    else
        printLCS(i, j - 1);
}

void LCS::printLCS() const
{
    printLCS(len1, len2);
}

LCS::~LCS()
{
    for(int i = 0; i < len1 + 1; i++)
    {
        delete [] b[i];
        delete [] c[i];
    }
    delete b;
    delete c;
}