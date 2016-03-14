#include "Stock.h"
#include<iostream>
using std::cout;
using std::endl;

//���캯��
CStock::CStock():top(-1)
{

}

//��ջ��������ջ�ɹ�����true,���򷵻�false;
bool CStock::push(elemType x)
{
   if(top == STOCK_SIZE - 1)
   {
       return false;
   }
   elem[++top] = x;
   return true;
}

//��ջ���������β�x��Ԫ�ش���������������ջ�ɹ�����true,���򷵻�false;
bool CStock::pop(elemType &x)
{
   if(top == -1)
   {
       return false;
   }
   x = elem[top--];
   return true;
}

//���ջ��ʹջΪ�գ�
void CStock::clear()
{
    top = -1;
}

//�ж�ջ�Ƿ�Ϊ��
bool CStock::isEmpty()
{
    return top == -1;
}

//�ж�ջ�Ƿ�ջ��
bool CStock::isFull()
{
    return top == STOCK_SIZE - 1;
}

//��ӡջ
void CStock::print()
{
   for(int i = 0; i <= top; i++)
   {
       cout << elem[i] << "\t";

       if( (i+1) % 5 == 0)
           cout << endl;
   }
}
//��������
CStock::~CStock(void)
{

}
