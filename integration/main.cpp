#include "integration.h"
using namespace std;

int main()
{
    SinFun f;
    RandPointMethod rpm(f);
    rpm.getIntegral();
    rpm.ouput();
    return 0;
}
