#include<iostream>
using namespace std;

int probe(int hashtable[], int key, int size){
    int hashindex=key%size;
    int i=0;
    while(hashtable[(hashindex+i)%size]!=-1){
        i++;
    }
    return (hashindex+i)%size;
}
void insert(int key,int hashtable[],int size){
    int hashindex=key%size;
    if(hashtable[hashindex]!=-1){
        hashindex=probe(hashtable,key,size);
    }
    hashtable[hashindex]=key;
}
int search(int key,int hashtable[], int size){
    int hashindex=key%size;
    if(hashtable[hashindex]!=-1){
        return -1;
    }
    return key;
}
int main(void){
    int hashtable[10]={-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
    int value[]={12,3,4,15,22,2,6,24};
    for(int i=0;i<8;i++){
        insert(value[i],hashtable,10);
    }
    for(int i=0;i<10;i++){
        cout<<hashtable[i]<<" ";
    }
    return 0;
}
