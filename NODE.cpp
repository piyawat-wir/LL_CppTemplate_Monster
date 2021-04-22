#include <iostream>
using namespace std;
#include"NODE.h"

NODE::NODE(int x){
      data=x;
      next=NULL;
      cout<<"adding "<< x<<endl;
}
NODE:: ~NODE(){
      cout<<"Node "<<data<<" is being deleted"<<endl;
}
NODE* NODE::move_next(){
      return next;
}
void  NODE:: show_node(){
         cout<<"Node data:"<<data<<endl;
 }
void NODE::insert(NODE*& x){
     x->next=this; //t->next=hol;

}
