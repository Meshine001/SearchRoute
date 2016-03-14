#include "Stock.h"
#include<iostream>
using std::cout;
using std::endl;

//构造函数
CStock::CStock():top(-1)
{

}

//进栈操作，进栈成功返回true,否则返回false;
bool CStock::push(elemType x)
{
   if(top == STOCK_SIZE - 1)
   {
       return false;
   }
   elem[++top] = x;
   return true;
}

//出栈操作，由形参x将元素带出主调函数，出栈成功返回true,否则返回false;
bool CStock::pop(elemType &x)
{
   if(top == -1)
   {
       return false;
   }
   x = elem[top--];
   return true;
}

//清空栈，使栈为空；
void CStock::clear()
{
    top = -1;
}

//判断栈是否为空
bool CStock::isEmpty()
{
    return top == -1;
}

//判断栈是否栈满
bool CStock::isFull()
{
    return top == STOCK_SIZE - 1;
}

//打印栈
void CStock::print()
{
   for(int i = 0; i <= top; i++)
   {
       cout << elem[i] << "\t";

       if( (i+1) % 5 == 0)
           cout << endl;
   }
}
//析构函数
CStock::~CStock(void)
{

}
