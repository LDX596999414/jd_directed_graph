//
// Created by LDX-Mac on 2020/12/9.
//
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
vector<node> node_list;


class directed_graph{
public:

    static void creat_node(){
        node t_node = {node_num, nullptr};
        //auto n = new node(1, nullptr);  // 为啥不能放到vec中
       // cout << "node_num:" << node_num <<endl;
        node_list.push_back(t_node);
        node_num++;
    }

    static void creat_edge(int n_num, int next_num){

        find_node(n_num, next_num);

        if(node_list[n_num].next == nullptr){
            node_list[n_num].next = new node(next_num, nullptr);
        }else{  //尾插入法插入新的node；
            node* p = node_list[n_num].next;
            while(p->next != nullptr){
                p = p->next;
            }
            p->next = new node(next_num, nullptr);

        }

    }

    static void del_edge(int n_num, int next_num){
        find_node(n_num, next_num);
        for(auto & x :node_list){
            if(x.val == n_num && x.next != nullptr){
                node* p = node_list[n_num].next;
                node* p_back = p->next;  //可能为空；
                if(p->val == next_num){
                    x.next = x.next->next;
                    break;
                } else{
                    while(p_back != nullptr){
                        if(p_back->val == next_num){
                            p->next = p->next->next;
                            break;
                        }
                        p = p->next;
                        p_back = p_back->next;
                    }
                }

            }
        }


    }

    static void del_node(int n_num){   // 遍历所有节点，并利用双指针删除节点；

        for(auto &x : node_list){
            if(x.val == n_num){
                x.val = -1;  //TODO：删除
                x.next = nullptr;
//                node* free_node_1 = x.next;
//                while(free_node_1 != nullptr){
//                    node* free_node_2 = free_node_1;
//                    free_node_1 = free_node_1->next;
//                    free(free_node_2);
//                }
            } else if(x.next != nullptr){
                node* temp = x.next;
                if(temp->val == n_num){
                    x.next = temp->next;
                    free(temp);
                    continue;
                }
                node* temp_back = temp->next;  //有可能为空
                while(temp_back != nullptr){
                    if(temp_back->val == n_num){
                        temp->next = temp_back->next;
                        free(temp_back);
                        break;
                    }else{
                        temp = temp->next;
                        temp_back = temp_back->next;
                    }
                }
            }
        }
    }

    static void push_node(){
        for(auto & i : node_list){
                cout << i.val;
                node* ptr = i.next;
                while (ptr != nullptr){
                    cout <<" -> "<<ptr->val;
                    ptr = ptr->next;
                }
                cout << endl;
        }
    }

static vector<int> write_node_connectivity(int id){
         vector<int>res_node;
          for(auto & i : node_list){
              if(i.val == id){
                  res_node.push_back(i.val);
                  node* ptr = i.next;
                  while(ptr != nullptr){
                    //TODO:
                    res_node.push_back(ptr->val);
                      ptr= ptr->next;
                  }
              }
          }
    return res_node;
    }

private:
    static int node_num ;
    static void find_node(int n_num, int next_num){  //因为是选择框所有不会存在找不到；
        bool find_n_num = false;
        bool find_next_num = false;
        for(auto & x : node_list){
            if(x.val == n_num ){
                find_n_num = true;
                break;
            }
        }
        for(auto & x : node_list){
            if(x.val == next_num){
                find_next_num = true;
                break;
            }
        }
        if(!find_n_num) cout << "没有发现"<<n_num<<"节点，无法创建连接"<<endl;
        if(!find_next_num) cout << "没有发现"<<next_num<<"节点，无法创建连接"<<endl;
    }
};

int directed_graph::node_num = 0;

 void writeFileJson(){

     json  root, line , array_line, point, array_point;

     for(int i = 0; i < 100; i++){  //TODO: i = id;
          // 其他信息写在这里？
          point["id"] = i;
          point["x"] =  i;
          point["y"] =  i;
          array_point.push_back(point);

        vector<int> t_node = directed_graph::write_node_connectivity(i);
        for(int j = 1; j < t_node.size();j++){
             //TODO:这里写入json；
             cout << "from_node_id: " << t_node[0]<<" ";
             cout << "to_node_id: " << t_node[j]<<endl;

             line["id"] = "TODO";
             line["cost"] = 1;
             line["from_node_id"] = t_node[0];
             line["to_node_id"] = t_node[j];
             array_line.push_back(line);
        }

     }

    root["line"] = array_line;
     root["node"] = array_point;
    ofstream os;
    os.open("test.json",ios::out );
    os<< root.dump(4)<<endl;
    os.close();
 }


int main(){


   directed_graph::creat_node();
   directed_graph::creat_node();
   directed_graph::creat_node();
   directed_graph::creat_node();
   directed_graph::creat_node();
   directed_graph::creat_node();

   directed_graph::creat_edge(0,1);
   directed_graph::creat_edge(0,2);
   directed_graph::creat_edge(0,3);
   directed_graph::creat_edge(1,2);
   directed_graph::creat_edge(2,0);
   directed_graph::creat_edge(2,3);
   directed_graph::creat_edge(3,0);
   directed_graph::creat_edge(3,4);
   directed_graph::creat_edge(4,2);
   directed_graph::creat_edge(4,3);
   directed_graph::creat_edge(5,4);
   directed_graph::creat_edge(5,3);
   directed_graph::creat_edge(3,5);

//   directed_graph::del_node(3);
//   directed_graph::del_edge(0,1);
   directed_graph::push_node();
   writeFileJson();

    return 0;
}