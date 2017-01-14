#include "knapsack.h"
using namespace std;

int main()
{
    ifstream ksfile("ks.txt");
    Knapsack<double> ks(ksfile);
    ks.sortByValue();
    ks.BackTrack(0);
    ks.output();
    return 0;
}
