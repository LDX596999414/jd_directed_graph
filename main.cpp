//
// Created by LDX-Mac on 2020/12/9.
//
#include<iostream>
#include<string>
#include <vector>

using namespace std;

class directed_graph{
public:

    void creat_node(){
        node t_node = {node_num, nullptr};
        //auto n = new node(1, nullptr);  // 为啥不能放到vec中
       // cout << "node_num:" << node_num <<endl;
        node_list.push_back(t_node);
        node_num++;
    }

    void creat_edge(int n_num, int next_num){   //TODO：如果把边删除掉了怎么处理？
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

    void del_node(int n_num){   // 遍历所有节点，并利用双指针删除节点；
//        for(auto it=node_list.begin();it!=node_list.end();){
//            node t = *it;
//            if(t.val == n_num){
//                it = node_list.erase(it);
//            } else{
//                ++it;
//            }
//
//        }

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

    void push_node(){
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

private:
    int node_num = 0;
    struct node{
    int val ;
    node* next = nullptr;
    node(int val, node* next):val(val), next(next){};
    };
    vector<node> node_list;

};



int main(){

   auto dp = new directed_graph();
   dp->creat_node();
   dp->creat_node();
   dp->creat_node();
   dp->creat_node();
   dp->creat_node();
   dp->creat_node();



   dp->creat_edge(0,1);
    dp->creat_edge(0,2);
     dp->creat_edge(0,3);

   dp->creat_edge(1,2);
   dp->creat_edge(2,0);
   dp->creat_edge(2,3);
   dp->creat_edge(3,0);
   dp->creat_edge(3,4);
   dp->creat_edge(4,2);
   dp->creat_edge(4,3);
   dp->creat_edge(5,4);
   dp->creat_edge(5,3);
   dp->creat_edge(3,5);

   dp->del_node(3);
   dp->push_node();

    return 0;
}