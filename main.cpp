//
// Created by LDX-Mac on 2020/12/9.
//
#include "directed_graph.h"

int main(){

   directed_graph::creat_node();
   directed_graph::creat_node();
   directed_graph::creat_node();
   directed_graph::creat_node();
//   directed_graph::creat_node();
//   directed_graph::creat_node();

   directed_graph::creat_edge(0,1);
   directed_graph::creat_edge(0,2);
   directed_graph::creat_edge(0,3);
//   directed_graph::creat_edge(1,2);
//   directed_graph::creat_edge(2,0);
//   directed_graph::creat_edge(2,3);
//   directed_graph::creat_edge(3,0);
//   directed_graph::creat_edge(3,4);
//   directed_graph::creat_edge(4,2);
//   directed_graph::creat_edge(4,3);
//   directed_graph::creat_edge(5,4);
//   directed_graph::creat_edge(5,3);
//   directed_graph::creat_edge(3,5);

   directed_graph::del_node(3);
   cout <<"node_num: "<< directed_graph::node_num <<endl;
   directed_graph::creat_node();
   directed_graph::creat_edge(0,2);
   directed_graph::creat_node();
   directed_graph::creat_node();
   directed_graph::del_node(4);
   directed_graph::creat_node();
//   directed_graph::del_edge(0,1);
   // node_list.clear();



   directed_graph::push_node();
   directed_graph::writeFileJson();

   cout <<"directed_graph::node_num: "<< directed_graph::node_num <<endl;

    return 0;
}