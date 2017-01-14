#include "lcs.h"
using namespace std;

 int main()
 {
     LCS lcs;
     lcs.getLCS();
     lcs.getLCSLength();
     cout << "The LCS is:";
     lcs.printLCS();
     cout << endl;     
 }