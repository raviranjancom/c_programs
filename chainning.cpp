#include "header.hpp"
#include<iostream>
using namespace std;

int hashFunction(int n, int k){
    return n%k;
}
int main(){
    node* hash[10]={nullptr};
    int values[10]={5,15,2,3,6,7,4,25};
    for(int i=0;i<10;i++){
        int hash_index=hashFunction(values[i], 10);
        hash[hash_index]=sortedInsert(hash[hash_index],values[i]);
    }
    node *r=hash[5];
    while(r){
        cout<<r->data<<" ";
        r=r->next;
    }
    return 0;
}
