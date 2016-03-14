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
    int inDegree;//���
    int outDegree;//����
    int state;//DFS״̬��������Ӧ���״̬,0 ��ɫ, 1 ��ɫ,2 ��ɫ
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
    void SetSize(int size);
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

template<class type>
SeqStack<type>::SeqStack():
    top(-1),maxsize(MAXSIZE) {
    stacka=new type[maxsize];
    if(stacka==NULL) {
        cerr<<"��̬�洢����ʧ��!"<<endl;
        exit(1);
    }
}
template<class type>
SeqStack<type>::SeqStack(int size):
    top(-1),maxsize(size) {
    stacka=new type[maxsize];    //�����洢ջ������
    if(stacka==NULL) {     //���䲻�ɹ�
        cerr<<"��̬�洢����ʧ��!"<<endl;
        exit(1);
    }
}
template<class type>
SeqStack<type>::SeqStack(type data[],int size):
    top(-1),maxsize(size) {
    stacka=new type[maxsize];    //�����洢ջ������
    if(stacka==NULL) {     //���䲻�ɹ�
        cerr<<"��̬�洢����ʧ��!"<<endl;
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
    stacka=new type[maxsize];    //�����洢ջ������
    if(stacka==NULL) {     //���䲻�ɹ�
        cerr<<"��̬�洢����ʧ��!"<<endl;
        exit(1);
    }
}

template<class type>
void SeqStack<type>::Push(const type& item) {
//��ջ�����������������Ԫ��itemѹջ
    if(Full()) {
        cerr<<"ջ����������ѹջ!"<<endl;
        exit(1);
    }
//�������ǲ���ָ�����ƶ���Ȼ���ٶ�Ԫ�ؽ��в����ķ�ʽ
    top++;

    stacka[top]=item;
}

template<class type>
type SeqStack<type>::Pop() {
    if(Empty()) {
        cerr<<"ջ�ѿ�!"<<endl;
        exit(1);
    }
//ջ���գ�ȡջ��Ԫ��
    type data=stacka[top];
    top--;
//����ջ��Ԫ��
    return data;
}

template<class type>
type SeqStack<type>::GetTop() {
//��ջ���գ�����ջ��Ԫ�ص�ֵ
    if(Empty()) {
        cerr<<"ջ��!"<<endl;
        exit(1);
    }
//����ջ��Ԫ�ص�ֵ
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
