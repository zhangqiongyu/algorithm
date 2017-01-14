#ifndef INTEGRATION_H
#define INTEGRATION_H

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>

class Function
{
public:
    virtual double operator()(double x) const = 0;
    virtual ~Function(){}
};

class SinFun: public Function
{
public:
    double operator()(double x) const;
};

class Integration
{
public:
    virtual double getIntegral() const = 0;
    virtual ~Integration(){}
};

class RandPointMethod: public Integration
{
private:
    double a;//积分区间为[a, b]
    double b;
    int frequency;//投点次数
    const Function &f;//函数引用
protected:
    double getIntegral(double low, double hight) const;
public:
    RandPointMethod(const Function &f);
    virtual double getIntegral() const;
    void ouput() const;
};

#endif
