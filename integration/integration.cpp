#include "integration.h"
using namespace std;

double SinFun::operator()(double x) const
{
    return sin(x);
}

RandPointMethod::RandPointMethod(const Function &f): f(f)
{
    cout << "Please enter the lower limit of integral:";
    cin >> a;
    cout << "Please enter the upper limit of integral:";
    cin >> b;
    cout << "Please enter the frequency of throwing points:";
    cin >> frequency;
}

double RandPointMethod::getIntegral(double low, double high) const
{
    long int count = 0;
	srand((unsigned int)time(NULL));//生成随机数种子
    for (int i = 0; i < frequency; i++)
	{
		double x = low + (high - low)*(double)rand() / double(RAND_MAX);//生成[a,b]之间的随机数作为x坐标
        double y = -1 + 2 * (double)rand() / double(RAND_MAX);//生成[-1,1]之间的随机数作为y坐标
        
        if (f(x) >= 0 && y >= 0 && y <= f(x))
			count++;
		else if (f(x) <= 0 && y <= 0 && y >= f(x))
			count--;
	}
	double integral = 2 * (high - low)*count / frequency;
	return integral;
}

double RandPointMethod::getIntegral() const
{
    if(a < b)
        return getIntegral(a, b);
    else if(a > b)
        return -getIntegral(b, a);
    else
        return 0;
}

void RandPointMethod::ouput() const
{
    cout << "The result is: " << getIntegral() << endl;
}
