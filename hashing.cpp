#include<iostream>
#include<vector>
using namespace std;

int index(int key){
    return key%10;
}
int linearprobe(int key,vector<int> &hashtable){
    int idx=index(key),i=0;
    while(hashtable[(idx+i)%10]!=-1){
        i++;
    }
    return (idx+i)%10;
}
void linear(vector<int> &hashtable,int v){
    if(hashtable[index(v)]==-1){
        hashtable[index(v)]=v;
        return ;
    }
    int i=linearprobe(v,hashtable);
    hashtable[i]=v;
    return ;
}
int quadraticprobe(int key,vector<int> &hashtable){
    int idx=index(key),i=0;
    while(hashtable[(idx+i*i)%10]!=-1){
        i++;
    }
    return (idx+i*i)%10;
}
void quadratic(vector<int> &hashtable,int v){
    if(hashtable[index(v)]==-1){
        hashtable[index(v)]=v;
        return ;
    }
    int i=quadraticprobe(v,hashtable);
    hashtable[i]=v;
    return ;
}
int h1(int key){
    return key%10;
}
int h2(int key){
    return 7-key%7;
}
int h(int key,int i){
    return (h1(key)+i*h2(key))%10;
}
void doublehashing(vector<int> &hashtable,int v){
    int i=0;
    int idx=h(v,i);
    while(hashtable[idx]!=-1){
        i++;
        idx=h(v,i);
    }
    hashtable[idx]=v;
    return ;
}
int main(){
    vector<int> hashtable(10,-1);
    vector<int> value={5,25,15,35,95}; //{10,22,3,5,2,6,12,20};
    for(auto it:value){
        doublehashing(hashtable,it);
    }
    for(auto it:hashtable){
        cout<<it<<" ";
    }
    return 0;
}

