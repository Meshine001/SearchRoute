
#include "route.h"
#include "lib_record.h"
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>

using namespace std;

#define MAX_NODE 600

struct EdgeNode
{
    int id; //LinkID
    int to; //DestinationID
    int cost; //Cost Value
    EdgeNode * pre; //Last Edge
    EdgeNode * next; //Next Edge
};
struct VNode
{
    int from; //SourceID
    EdgeNode * first; //AdjTable head
};

int temp_param[4];
VNode Adjlist[MAX_NODE];//�ڽӱ�
int source_node;//����յ�
int destination_node;
int sub_node[MAX_NODE];//�Ӽ�
int SUB_NODE = 0;//�Ӽ�����


int in_degree[MAX_NODE];//����ÿ��������

vector<int> route; //·��
int visited[MAX_NODE];

//��Ҫ��ɵĹ��������
void search_route(char *topo[5000], int edge_num, char *demand)
{
    unsigned short result[] = {2, 6, 3};//ʾ���е�һ����

    parse_demand(demand);
    init_adjlist(topo,edge_num);

    search_all_route(source_node);
    // DFS(demand_node[0]);

    for (int i = 0; i < 3; i++)
        record_result(result[i]);
}

//void show_route(){
// vector<int>::iterator it;
//    for(it=vc.begin();it!=vc.end();it++)
//    cout<<*it<<endl;
//
//
//}



/**
 * ��ʼ���ڽӱ�
 *
 */
void init_adjlist(char *topo[5000],int edge_num)
{

    for (int i = 0; i < MAX_NODE; ++i)
    {
        VNode *node = new VNode();
        node->from = i;
        node->first = NULL;
    }


    for (int i = 0; i < edge_num; ++i)
    {
        parse_topo(topo[i]);
        //printf("The EDGE: [%d,%d,%d,%d]\n",temp_param[0],temp_param[1],temp_param[2],temp_param[3]);
        add_edgeNode();
    }

    remove_in_degree_is_zero();
    remove_in_degree_is_zero();
    remove_in_degree_is_zero();

    //����ڽӱ�
    int blance_count = 0;
    for (int i = 0; i < MAX_NODE; ++i)
    {
        for(EdgeNode *eg = Adjlist[i].first; eg != NULL; eg = eg->next)
        {
            cout << eg->id << "," <<i<<"," << eg->to <<","<<eg->cost<<endl;
            blance_count++;
        }
    }
    cout<<"��ʣ "<<blance_count<<" ���ߡ�"<<endl;

//    for(int i=0;i<MAX_NODE;i++){
//        cout<<in_degree[0]<<endl;
//    }
}

void search_all_route(int s)
{
    for(EdgeNode * head = Adjlist[s].first; head->next!=NULL; head = head->next)
    {
        if(head != NULL)
        {
            cout<<"LinkID:"<<head->id<< " Node:["<< s << "," << head->to << "]" << endl;
            if(search_branch_route(head->to) == destination_node)
            {
                cout<<"�������..."<<endl;
            }
        }
    }
}

int search_branch_route(int s)
{
//    if(s == destination_node)
//    {
//        return s;
//    }

    for(EdgeNode * head = Adjlist[s].first; head->next!=NULL; head = head->next)
    {
        if(head != NULL)
        {

            cout<<"LinkID:"<<head->id<< " Node:["<< s << "," << head->to << "]" << endl;
            return search_branch_route(head->to);
        }
    }
}

void remove_in_degree_is_zero()
{
//ȥ�����Ϊ0�ĵ�,�Լ�����Ϊ���ı�
    for (int i = 0; i < MAX_NODE; ++i)
    {
        //����õ����Ϊ0����ɾ�����ı���Ϣ
        if(in_degree[i]==0)
        {
            if(i == destination_node)
            {
                cout<<"��·��"<<endl;
                return;
            }
            if(i != source_node && i != destination_node)
                //cout<<"��"<< i <<"���Ϊ0�ĵ�,ɾ����������ı�..."<<endl;
                Adjlist[i].first = NULL;
        }
    }
}

void DFS(int s)
{
    EdgeNode *eg;
    int d;
    cout<<"��ʼ���ʵ�:"<<s<<endl;
    visited[s] = 1;
    for(eg = Adjlist[s].first; eg->next != NULL; eg = eg->next)
    {
        cout<<"��:"<<eg->id<<endl;

        if(eg != NULL)
        {
            d = eg->to;
            if(visited[d] == 0)
            {
                DFS(d);
            }
        }
    }


}


void parse_demand(char *demand)
{
    char * subSet;
    cout<<demand<<endl;
    //����","
    const char *d = ",";
    char *p;
    p = strtok(demand,d);
    int index = 0;
    int demand_node[2];
    while(p)
    {
        //printf("%s\n", p);
        if(index < 2)demand_node[index] = atoi(p);
        else subSet = p;
        ++index;
        p = strtok(NULL,d);
    }
    source_node = demand_node[0];
    destination_node = demand_node[1];

    //����"|"
    parse_subSet(subSet);

    cout<<demand_node[0]<<","<< demand_node[1]<<endl;
    for(int i = 0 ; i< SUB_NODE; ++i)
    {
        cout<<sub_node[i]<<",";
    }


}

void parse_subSet(char *subSet)
{
    const char *d = "|";
    char *p;
    p = strtok(subSet,d);
    int index = 0;
    while(p)
    {
        // printf("%s\n", p);
        sub_node[index] = atoi(p);
        ++index;
        p = strtok(NULL,d);
    }

    SUB_NODE = index;

}

//ȥ��
void add_edgeNode()
{
    EdgeNode *p = new EdgeNode();
    p->id = temp_param[0];
    p->to = temp_param[2];
    p->cost = temp_param[3];
    int in_degree_count = in_degree[p->to];
    in_degree[p->to] = in_degree_count + 1;

    if(Adjlist[temp_param[1]].first == NULL)
    {
        p->pre = NULL; //�׽ڵ�
        p->next = Adjlist[temp_param[1]].first;
        Adjlist[temp_param[1]].first = p;
        Adjlist[temp_param[1]].from = temp_param[1];
    }
    else
    {
        bool isReplaced = false;
        //���ر����Ƚϣ�����ȨֵС��
        for(EdgeNode *eg = Adjlist[temp_param[1]].first; eg->next != NULL ; eg = eg->next)
        {
            if(eg->to == p->to && eg->cost > p->cost)
            {
                //p�滻eg
                p->pre = eg->pre;
                p->next = eg->pre;
                isReplaced = true;
            }
        }

        if(!isReplaced)
        {
            p->pre = NULL;
            Adjlist[temp_param[1]].first->pre = p;
            p->next = Adjlist[temp_param[1]].first;
            Adjlist[temp_param[1]].first = p;
            Adjlist[temp_param[1]].from = temp_param[1];
        }
    }
}


void parse_topo(char ch[])
{
    const char *d = ",";
    char *p;
    p = strtok(ch,d);
    int index = 0;
    while(p)
    {
        //printf("%s\n", p);
        temp_param[index] = atoi(p);
        ++index;
        p = strtok(NULL,d);
    }
}
