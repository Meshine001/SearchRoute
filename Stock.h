
#ifndef CSTOCK_H_
#define CSTOCK_H_

const int STOCK_SIZE = 100;//定义栈的大小
typedef int elemType;//定义栈元素类型，目前仅用int来练手

class CStock
{
public:
    CStock(); //构造函数，构造空栈；

    bool push(elemType x); //进栈操作；
    bool pop(elemType &x); //出栈操作；
    void clear(); //清空栈；
    bool isEmpty(); //判断是否栈空；
    bool isFull(); //判断是否栈满；
    void print(); //打印栈内元素；

    ~CStock();

private:
   elemType elem[STOCK_SIZE];
   int top;//指向栈顶；
};

#endif
