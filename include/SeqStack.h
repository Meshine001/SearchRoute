#ifndef SEQSTACK_H
#define SEQSTACK_H
#include <iostream>
#include <stdlib.h>

#define MAXSIZE   0xFFFF

template<class type>
class SeqStack {
    int   top;     //栈顶指示
    type *stacka;    //数组名
    int   maxsize;    //栈最大可容纳元素个数
public:
    SeqStack();
    SeqStack(int size);
    SeqStack(type data[],int size);
    virtual ~SeqStack() {
        delete []stacka;
    }
    void Push(const type &item);    //元素item压栈
    type Pop();        //数据元素出栈,返回之
    type GetTop();       //读栈顶数据元素并返回

    int   Empty()const {
        return top==-1;
    }           //判断栈是否为空
    int   Full()const {
        return top==maxsize-1;
    }           //判断栈是否为满
    void Clear() {
        top=-1;
    }           //清空栈
};

#endif // SEQSTACK_H
