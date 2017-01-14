#include "MaxLoad.h"
using namespace std;

int main()
{
    ifstream load("maxload.txt");
    MaxLoad maxload(load);
    maxload.getBestLoad();
    maxload.output();
    return 0;
}
