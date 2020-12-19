//
// Created by LDX-Mac on 2020/12/15.
//

#ifndef JD_DIRECTED_GRAPH_DIRECTED_GRAPH_H
#define JD_DIRECTED_GRAPH_DIRECTED_GRAPH_H

#include<iostream>
#include<string>
#include <vector>
#include <fstream>
#include "json.hpp"

using json = nlohmann::json;
using namespace std;

struct node{
int val ;
node* next = nullptr;
node(int val, node* next):val(val), next(next){};
};
extern vector<node> node_list;

class directed_graph{
public:

    static void creat_node();
    static void creat_edge(int n_num, int next_num);
    static void del_edge(int n_num, int next_num);
    static void del_node(int n_num);
    static void push_node();
    static vector<int> write_node_connectivity(int id);
    static void writeFileJson();
    static int node_num ;

private:

    static void find_node(int n_num, int next_num);
};

#endif //JD_DIRECTED_GRAPH_DIRECTED_GRAPH_H