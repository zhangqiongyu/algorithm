#include "MaxLoad.h"
using namespace std;

MaxLoad::MaxLoad(ifstream &infile): 
    count(0), bestWeight(0.0), crtNode(NULL), extendWeight(0), crtBestNode(NULL)
{
    if(!infile)
    {
        cerr << "Error opening file!";
        exit(EXIT_FAILURE);
    }
    infile >> capacity;
    cout << "The capacity of the boat is:" << capacity << endl;
    cout << "The infomation of the container is:" << endl;
    int width = 7;
    cout << setiosflags(ios_base::left)
        << setw(width) << "id"
        << setw(width) << "weight"
        << resetiosflags(ios_base::left) << endl;
    while(true)
    {
        double _weight;
        infile >> _weight;
        if(infile.eof())
            break;
        weight.push_back(_weight);
        flag.push_back(false);
        cout << setiosflags(ios_base::left)
            << setw(width) << count + 1
            << setw(width) << _weight
            << resetiosflags(ios_base::left) << endl;
        count++;
    }
    q.push(NULL);//队列中先加入空节点，表示同层节点尾部标志
}

void MaxLoad::enqueue(Node *node, int i)
{
    if(i == count - 1)//可行叶节点
    {
        if(node->weight == bestWeight)
        {
            crtBestNode = node->parent;
            flag[count - 1] = node->lchild;
        }
        return;
    }
    q.push(node);
}

void MaxLoad::getBestLoad()
{
    int level = 0;//当前节点所处的层
    double rest = 0;//剩余集装箱重量 
    for(int i = 1; i < count; i++)
        rest += weight[i];
    while(true)
    {
        //检查左子女节点
        if(extendWeight + weight[level] <= capacity)
        {
            if(extendWeight + weight[level] > bestWeight)
                bestWeight = extendWeight + weight[level];
            Node *leftNode = new Node(crtNode, extendWeight + weight[level], true);
            enqueue(leftNode, level);
        }
        if(extendWeight + rest > bestWeight)
        {
            Node *rightNode = new Node(crtNode, extendWeight, false);
            enqueue(rightNode, level);
        }
        crtNode = q.front();
        q.pop();

        if(!crtNode)
        {
            if(q.empty())
                break;
            q.push(NULL);
            crtNode = q.front();
            q.pop();
            level++;
            rest -= weight[level];
        }
        extendWeight = crtNode->weight;
    }
    /*for(int i = count - 2; i >= 0; i--)
    {
        flag[i] = crtNode->lchild;
        crtNode = crtNode->parent;
    }*/
}

void MaxLoad::output() const
{
    cout << "The best load is:" << bestWeight << endl;
    /*cout << "The containers' id selected are: ";
    for(int i = 0; i < count; i++)
    {
        if(flag[i])
            cout << i + 1 << endl;
    }*/   
}