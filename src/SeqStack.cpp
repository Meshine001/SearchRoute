#include "SeqStack.h"

using namespace std;
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
