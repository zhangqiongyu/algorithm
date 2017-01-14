#ifndef MAXLOAD_H
#include <iostream>
#include <queue>
#include <iomanip>
#include <fstream>
#include <cstdlib>

//子集树节点及其定义
struct Node
{
    Node *parent;
    double weight;
    bool lchild;
    Node(Node *parent = NULL, double weight = 0.0, bool lchild = false):
        parent(parent), weight(weight), lchild(lchild) {}
};

class MaxLoad
{
private:
    double capacity;//轮船载重量
    std::vector<double> weight;//每个货物重量
    std::vector<bool> flag;//标志被装载的
    int count;//货物数量
    std::queue<Node*> q;//辅助队列
    double bestWeight;//最大载重
    Node *crtNode;//当前扩展节点
    double extendWeight;//扩展节点对应的重量
    Node *crtBestNode;//当前最优扩展节点
public:
    MaxLoad(std::ifstream &infile);//构造函数，读取文件数据
    void enqueue(Node *node, int i);//将节点入队列
    void getBestLoad();//获取最优装载
    void output() const;//输出结果
};

#define MAXLOAD_H
#endif