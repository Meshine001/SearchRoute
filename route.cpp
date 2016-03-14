
#include "route.h"
#include "lib_record.h"
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>


using namespace std;

#define MAX_NODE 600



int temp_param[4];
VNode Adjlist[MAX_NODE];//�ڽӱ�
int source_node;//����յ�
int destination_node;
int sub_node[MAX_NODE];//�Ӽ�
int SUB_NODE = 0;//�Ӽ�����




//int dfs_state[MAX_NODE];//DFS״̬��������Ӧ���״̬,0 ��ɫ, 1 ��ɫ,2 ��ɫ

int dfs_time;

int global_edge_num;
SeqStack<int> route_stack;//������¼��ʱ·��
string routStr = "";

vector<int> dfs_route; //·��
//int visited[MAX_NODE];

//��Ҫ��ɵĹ��������
void search_route(char *topo[5000], int edge_num, char *demand) {
    unsigned short result[] = {2, 6, 3};//ʾ���е�һ����
    global_edge_num = edge_num;
    parse_demand(demand);
    init_adjlist(topo,edge_num);

    route_stack.SetSize(global_edge_num);
    cout<<"��ʼ����..."<<endl;
    search_all_route(source_node);

    // DFS();

//    for(int i=0; i<MAX_NODE; i++) {
//        if(Adjlist[i].first != NULL && Adjlist[i].state  == 2)
//            cout<<"Node: " << i<< " d: " << Adjlist[i].d << " f: " << Adjlist[i].f << endl;
//    }

    for (int i = 0; i < 3; i++)
        record_result(result[i]);
}


/** \brief Ѱ������·��
 *
 * \param
 * \param
 * \return
 *
 */

void search_all_route(int s) {
    for(EdgeNode * head = Adjlist[s].first;head->next!=NULL;head=head->next){
       //���Ѿ��߹�
       if(Adjlist[head->to].state == 1)return;

        Adjlist[s].state = 1;//���Ϊ�Ѿ��߹�
        route_stack.Push(head->id);//��Ӵ�·��
        cout<<head->id<<","<<s<<","<<head->to<<endl;
        //�����ڽӵ���Ŀ���,��ֹ
        if(head->to == destination_node){

            SeqStack<int> tempStack(global_edge_num);
            //
            while(!route_stack.Empty()){
                tempStack.Push(route_stack.Pop());
            }
            while(!tempStack.Empty()){
                int id = tempStack.Pop();
                   cout << id << "|";
                route_stack.Push(id);
            }
            cout<<endl;
            route_stack.Pop();

            continue;
        }

        //�����ڽӵ㲻��Ŀ���,����
        if(head->to != destination_node){
            search_all_route(head->to);
        }
    }

}

//void DFS() {
//    //u.color = WHITE
//    //u.pre = NIL
//    //time = 0
//    dfs_time = 0;
//
//    //for each vertex u in G.V
//    // if u.color == WHITE
//    //   DFS-VISIT(G,u)
//    for(EdgeNode *eg = Adjlist[source_node].first; eg->next != NULL; eg = eg->next) {
//        Adjlist[source_node].state = 1;
//        //dfs_route.insert(dfs_route.end(),eg->id);
//        //cout << eg->id <<", ["<< Adjlist[source_node].from <<","<<eg->to<<"]" <<" dsf_time: "<< dfs_time <<endl;
//        if(Adjlist[eg->to].state == 0) {
//
//            DFS_VISIT(eg);
//        }
//    }
//}

//void DFS_VISIT(EdgeNode *eg) {
//    //time = time +1
//    //u.d = time
//    //u.color = GRAY
//    int s = eg->to;
//    dfs_time++;
//    Adjlist[s].state = 1;
//    Adjlist[s].d = dfs_time;
//    //  cout << s <<", ["<< Adjlist[s].from <<","<<Adjlist[s].first->to<<"]"<<" dsf_time: "<< dfs_time <<endl;
//    route_stack.Push(eg->id);
//
//    for(EdgeNode *p = Adjlist[s].first; p->next != NULL; p = p->next) {//��δ���ǳ���Ϊ0
//        if(Adjlist[p->to].state == 0) {  Adjlist[eg->to].from = s;
//            //�ҵ�һ��·��
//            if(p->to == destination_node) {
//                dfs_route.insert(dfs_route.end(),p->id);//���·��
//                cout<<"�ҵ�һ��·��"<<endl;
//                vector<int>::iterator it;
//                for(it=dfs_route.begin(); it!=dfs_route.end(); it++)
//                    cout<<*it<< " |" ;
//                return;
//            }
//            DFS_VISIT(eg);
//        }
//    }
//
//    Adjlist[s].state = 2;
//    dfs_time++;
//    Adjlist[s].f = dfs_time;
//}



/**
 * ��ʼ���ڽӱ�
 *
 */
void init_adjlist(char *topo[5000],int edge_num) {

    for (int i = 0; i < MAX_NODE; ++i) {
        VNode *node = new VNode();
    }


    for (int i = 0; i < edge_num; ++i) {
        parse_topo(topo[i]);
        //printf("The EDGE: [%d,%d,%d,%d]\n",temp_param[0],temp_param[1],temp_param[2],temp_param[3]);
        add_edgeNode();
    }

    remove_zero_degree();
    remove_zero_degree();
     remove_zero_degree();

    //����ڽӱ�
    int blance_count = 0;
    for (int i = 0; i < MAX_NODE; ++i) {
        for(EdgeNode *eg = Adjlist[i].first; eg != NULL; eg = eg->next) {
            cout << eg->id << "," <<i<<"," << eg->to <<","<<eg->cost<<endl;
            blance_count++;
        }
    }
    cout<<"��ʣ "<<blance_count<<" ���ߡ�"<<endl;

//    for(int i=0;i<MAX_NODE;i++){
//        cout<<in_degree[0]<<endl;
//    }
}




/** \brief ȥ����Ⱥͳ��ȶ�Ϊ0�ķ����ͷ��յ�
 *
 * \param
 * \param
 * \return
 *
 */

void remove_zero_degree() {
//ȥ�����Ϊ0�ĵ�,�Լ�����Ϊ���ı�
    for (int i = 0; i < MAX_NODE; ++i) {

        if(i == destination_node || i == source_node)return;

        //����õ����Ϊ0����ɾ�����ı���Ϣ
        if(Adjlist[i].inDegree==0 || Adjlist[i].outDegree == 0) {
            Adjlist[i].first = NULL;
        }
    }
}






void parse_demand(char *demand) {
    char * subSet;
    cout<<demand<<endl;
    //����","
    const char *d = ",";
    char *p;
    p = strtok(demand,d);
    int index = 0;
    int demand_node[2];
    while(p) {
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
    for(int i = 0 ; i< SUB_NODE; ++i) {
        cout<<sub_node[i]<<",";
    }


}

void parse_subSet(char *subSet) {
    const char *d = "|";
    char *p;
    p = strtok(subSet,d);
    int index = 0;
    while(p) {
        // printf("%s\n", p);
        sub_node[index] = atoi(p);
        ++index;
        p = strtok(NULL,d);
    }

    SUB_NODE = index;

}


void add_edgeNode() {
    EdgeNode *p = new EdgeNode();
    p->id = temp_param[0];
    p->to = temp_param[2];
    p->cost = temp_param[3];

    Adjlist[temp_param[2]].inDegree++;//��ȼ�1
    Adjlist[temp_param[1]].outDegree++;//���ȼ�1

    //���õ��ڽӱ�Ϊ�գ�����Ӵ˱�
    if(Adjlist[temp_param[1]].first == NULL) {
        p->pre = NULL; //�׽ڵ�
        p->next = Adjlist[temp_param[1]].first;
        Adjlist[temp_param[1]].first = p;

    } else {
        //��ԭ���ı����Ƚ�
        bool isReplaced = false;
        //���ر����Ƚϣ�����ȨֵС��
        for(EdgeNode *eg = Adjlist[temp_param[1]].first; eg->next != NULL ; eg = eg->next) {
            if(eg->to == p->to && eg->cost > p->cost) {
                //p�滻eg
                p->pre = eg->pre;
                p->next = eg->pre;
                isReplaced = true;
            }
        }

        //���û���رߣ���Ӵ˱�
        if(!isReplaced) {
            p->pre = NULL;
            Adjlist[temp_param[1]].first->pre = p;
            p->next = Adjlist[temp_param[1]].first;
            Adjlist[temp_param[1]].first = p;
        }
    }
}


void parse_topo(char ch[]) {
    const char *d = ",";
    char *p;
    p = strtok(ch,d);
    int index = 0;
    while(p) {
        //printf("%s\n", p);
        temp_param[index] = atoi(p);
        ++index;
        p = strtok(NULL,d);
    }
}
