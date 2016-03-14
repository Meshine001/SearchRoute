#include "SeqStack.h"

using namespace std;
template<class type>
SeqStack<type>::SeqStack():
    top(-1),maxsize(MAXSIZE) {
    stacka=new type[maxsize];
    if(stacka==NULL) {
        cerr<<"动态存储分配失败!"<<endl;
        exit(1);
    }
}
template<class type>
SeqStack<type>::SeqStack(int size):
    top(-1),maxsize(size) {
    stacka=new type[maxsize];    //创建存储栈的数组
    if(stacka==NULL) {     //分配不成功
        cerr<<"动态存储分配失败!"<<endl;
        exit(1);
    }
}
template<class type>
SeqStack<type>::SeqStack(type data[],int size):
    top(-1),maxsize(size) {
    stacka=new type[maxsize];    //创建存储栈的数组
    if(stacka==NULL) {     //分配不成功
        cerr<<"动态存储分配失败!"<<endl;
        exit(1);
    }
    for(int i=0; i<maxsize; i++) {
        stacka[i]=data[i];
    }

    top+=maxsize;
}

template<class type>
void SeqStack<type>::Push(const type& item) {
//若栈已满，出错处理；否则把元素item压栈
    if(Full()) {
        cerr<<"栈已满，不能压栈!"<<endl;
        exit(1);
    }
//这里我们采用指针先移动，然后再对元素进行操作的方式
    top++;

    stacka[top]=item;
}

template<class type>
type SeqStack<type>::Pop() {
    if(Empty()) {
        cerr<<"栈已空!"<<endl;
        exit(1);
    }
//栈不空，取栈顶元素
    type data=stacka[top];
    top--;
//返回栈顶元素
    return data;
}

template<class type>
type SeqStack<type>::GetTop() {
//若栈不空，返回栈顶元素的值
    if(Empty()) {
        cerr<<"栈空!"<<endl;
        exit(1);
    }
//返回栈顶元素的值
    return stacka[top];
}
