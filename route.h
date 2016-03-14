#ifndef __ROUTE_H__
#define __ROUTE_H__



void search_route(char *graph[5000], int edge_num, char *condition);
void parse_topo(char ch[]);
void init_adjlist(char *topo[5000],int edge_num);
void add_edgeNode();
void parse_demand(char *demand);
void parse_subSet(char *subSet);
void remove_in_degree_is_zero();

#endif
