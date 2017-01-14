#ifndef KNAPSACK_H
#define KNAPSACK_H

#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <iomanip>

template<class T>
struct DataType
{
    int id; //物品编号
    T weight;//物品重量
    T value;//物品价值
    DataType(int id, T weight, T value):id(id), weight(weight), value(value) {}
};

template<class T>
struct KnapsackType
{
    T currentWeight;//当前装入物品重量
    T currentValue;//当前装入物品价值
    T currentBestValue;//当前最有价值
    KnapsackType(T crtWeight = 0, T crtValue = 0, T crtBestValue = 0):
        currentWeight(crtWeight), currentValue(crtValue), currentBestValue(crtBestValue) {}
};

template<class T>
class Knapsack
{
private:
    T capacity;//背包容量
    KnapsackType<T> knapsack;//用来存储物品
    int count;//物品总数
    std::vector<DataType<T> > ks;//所有物品的数据
    std::vector<bool> putFlag;//标识被添加的背包，true则被添加，false则未被添加
public:
    Knapsack(std::ifstream &infile);
    void sortByValue();//按单位重量价值将背包排序
    T bound(int i); 
    void BackTrack(int i);
    void output() const;
};

//构造函数，读取文件并输出背包和物品数据
template<class T>
Knapsack<T>::Knapsack(std::ifstream &infile):count(0)
{
    if(!infile)
    {
        std::cerr << "Error opening file!";
        exit(EXIT_FAILURE);
    }
    infile >> capacity;//读取背包容量
    std::cout << "The capacity of the knapsack is:" << capacity << std::endl;
    std::cout << "The infomation of the goods is：" << std::endl;
    int width = 7;
    std::cout << std::setiosflags(std::ios_base::left) 
        << std::setw(width) << "id" 
        << std::setw(width) << "weight" 
        <<  std::setw(width) << "value" 
        << std::resetiosflags(std::ios_base::left) << std::endl;
    while(true)//读取数据
    {
        int id;
        T weight, value;
        infile >> id >> weight >> value;
        if(infile.eof())
            break;
        DataType<T> good(id, weight, value);
        ks.push_back(good);
        putFlag.push_back(false);
        count++;
        std::cout << std::setiosflags(std::ios_base::left)
            << std::setw(width) << id 
            << std::setw(width) << weight 
            << std::setw(width) << value 
            << std::resetiosflags(std::ios_base::left) << std::endl;
    }
}

//按照单价从小到大对物品排序，采用冒泡排序
template<class T>
void Knapsack<T>::sortByValue()
{
    for(int j = 0; j < count; j++)
        for(int i = 0; i < count - 1 - j; i++)
        {
            if(ks[i].value / ks[i].weight < ks[i + 1].value/ks[i + 1].weight)
            {
                DataType<T> temp = ks[i];
                ks[i] = ks[i + 1];
                ks[i + 1] = temp;
            }
        }
}

//设置边界函数
template<class T>
T Knapsack<T>::bound(int i)
{
    T bound = knapsack.currentValue;
    T leftCapacity = capacity - knapsack.currentWeight;

    while(i < count && ks[i].weight <= leftCapacity)
    {
        leftCapacity -= ks[i].weight;
        bound += ks[i].value;
        i++;
    }
    if(i < count)
        bound += ks[i].value / ks[i].weight * leftCapacity;
}

//进行回溯
template<class T>
void Knapsack<T>::BackTrack(int i)
{
    if(i > count - 1)
    {
        knapsack.currentBestValue = knapsack.currentValue;
        return;
    }
    if(knapsack.currentWeight + ks[i].weight <= capacity)
    {
        knapsack.currentWeight += ks[i].weight;
        knapsack.currentValue += ks[i].value;
        putFlag[i] = true;
        BackTrack(i + 1);
        knapsack.currentWeight -= ks[i].weight;
        knapsack.currentValue -= ks[i].value;
    }
    if(bound(i + 1) > knapsack.currentBestValue)
    {
        putFlag[i] = false;
        BackTrack(i + 1);
    }
}

//输出结果
template<class T>
void Knapsack<T>::output() const
{
    int width = 7;//调整输出宽度
    std::cout << "After sorted by unit value:" << std::endl;
    std::cout << std::setiosflags(std::ios_base::left) 
        << std::setw(width) << "id" 
        << std::setw(width) << "weight" 
        <<  std::setw(width) << "value" 
        << std::resetiosflags(std::ios_base::left) << std::endl;
    for (int i = 0; i < count; i++)
        std::cout << std::setiosflags(std::ios_base::left) 
            << std::setw(width) << ks[i].id 
            << std::setw(width) << ks[i].weight 
            << std::setw(width) << ks[i].value 
            << std::resetiosflags(std::ios_base::left) << std::endl;
    std::cout << "Best value of the knapsack is: " << knapsack.currentBestValue << std::endl;
    std::cout << "The knapsacks selected:" << std::endl;
    int i;
    for(i = 0; i < count - 1; i++)
        if(putFlag[i])
            std::cout << ks[i].id << ", ";
    std::cout << ks[i].id << "." << std::endl;
}
#endif
