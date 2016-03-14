#ifndef __ROUTE_H__
#define __ROUTE_H__


struct EdgeNode {
    int id; //LinkID
    int to; //DestinationID
    int cost; //Cost Value
    EdgeNode * pre; //Last Edge
    EdgeNode * next; //Next Edge
};
struct VNode {
    int inDegree;//入度
    int outDegree;//出度
    int state;//DFS状态表，表征对应点的状态,0 白色, 1 灰色,2 黑色
    int d;
    int f;
    EdgeNode * first; //AdjTable head
};

#define MAXSIZE   0xFFFF
#include <iostream>
#include <stdlib.h>
using namespace std;
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
    void SetSize(int size);
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
void SeqStack<type>::SetSize(int size){
    top = -1;
    maxsize = size;
    stacka=new type[maxsize];    //创建存储栈的数组
    if(stacka==NULL) {     //分配不成功
        cerr<<"动态存储分配失败!"<<endl;
        exit(1);
    }
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
void search_route(char *graph[5000], int edge_num, char *condition);
void parse_topo(char ch[]);
void init_adjlist(char *topo[5000],int edge_num);
void add_edgeNode();
void parse_demand(char *demand);
void parse_subSet(char *subSet);
void remove_zero_degree();
void search_all_route(int s);

#endif
