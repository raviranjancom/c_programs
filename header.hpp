#ifndef HEADER_HPP
#define HEADER_HPP
#include<iostream>
using namespace std;
class node{
    public:
        int data;
        node* next;
        node(int data, node* next=nullptr){
            this->data=data;
            this->next=next;
        }
};
node *sortedInsert(node *root,int key){
    node *r=root;
    node *temp=new node(key);
    if(r==nullptr){
        root=temp;
    }
    else{
        node *last=r;
        while(r && r->data<key){
            last=r;
            r=r->next;
        }
        last->next=temp;
        temp->next=r;
    }
    return root;
}

node *search(node *r,int key){
    while(r && r->data!=key){
        r=r->next;
    }
    return r;
}
#endif