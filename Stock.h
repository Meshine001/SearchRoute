
#ifndef CSTOCK_H_
#define CSTOCK_H_

const int STOCK_SIZE = 100;//����ջ�Ĵ�С
typedef int elemType;//����ջԪ�����ͣ�Ŀǰ����int������

class CStock
{
public:
    CStock(); //���캯���������ջ��

    bool push(elemType x); //��ջ������
    bool pop(elemType &x); //��ջ������
    void clear(); //���ջ��
    bool isEmpty(); //�ж��Ƿ�ջ�գ�
    bool isFull(); //�ж��Ƿ�ջ����
    void print(); //��ӡջ��Ԫ�أ�

    ~CStock();

private:
   elemType elem[STOCK_SIZE];
   int top;//ָ��ջ����
};

#endif
