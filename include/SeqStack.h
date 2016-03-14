#ifndef SEQSTACK_H
#define SEQSTACK_H
#include <iostream>
#include <stdlib.h>

#define MAXSIZE   0xFFFF

template<class type>
class SeqStack {
    int   top;     //ջ��ָʾ
    type *stacka;    //������
    int   maxsize;    //ջ��������Ԫ�ظ���
public:
    SeqStack();
    SeqStack(int size);
    SeqStack(type data[],int size);
    virtual ~SeqStack() {
        delete []stacka;
    }
    void Push(const type &item);    //Ԫ��itemѹջ
    type Pop();        //����Ԫ�س�ջ,����֮
    type GetTop();       //��ջ������Ԫ�ز�����

    int   Empty()const {
        return top==-1;
    }           //�ж�ջ�Ƿ�Ϊ��
    int   Full()const {
        return top==maxsize-1;
    }           //�ж�ջ�Ƿ�Ϊ��
    void Clear() {
        top=-1;
    }           //���ջ
};

#endif // SEQSTACK_H
