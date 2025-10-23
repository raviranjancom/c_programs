#include<iostream>
#include<stdio.h>
#include<stack>
#include<queue>
#include<bits/stdc++.h>

using namespace std;

class node{
  public:
    int data;
    int height;
    node *left, *right;

    node(int v){
      data=v;
      left=right=nullptr;
    }
};

vector<int> post_order_2stack(node *r){
  vector<int> ans;
  if(r==nullptr) return ans;
  stack<node *> st1,st2;
  while(!st1.empty() || r){
    
  }
}

node *create(){
    queue<node *> q;
    cout<<"Enter root node = ";
    int v;
    cin>>v;
    node *root=new node(v);
    q.push(root);
    while(!q.empty()){
      node *t=q.front();
      q.pop();
      cout<<"Enter the left child = ";
      cin>>v;
      if(v!=-1){
	      node *leftnode=new node(v);
        t->left=leftnode;
        q.push(leftnode);
      }
      cout<<"Enter the right child = ";
      cin>>v;
      if(v!=-1){
        node *rightnode=new node(v);
        t->right=rightnode;
        q.push(rightnode);
      }
   }
  return root;
}

void Inorder(node *r){
  if(r){
    Inorder(r->left);
    cout<<r->data<<" ";
    Inorder(r->right);
  }
}

void preorder(node *r){
  if(r!=nullptr){
    cout<<r->data<<" ";
    preorder(r->left);
    preorder(r->right);
  }
}

void Ipreorder(node* r){
  stack<node *> st;
  while(r || !st.empty()){
    if(r){
      cout<<r->data<<" ";
      st.push(r);
      r=r->left;
    }
    else{
      r=st.top();
      st.pop();
      r=r->right;
    }
  }
}

void IInorder(node *r){
    stack<node *> st;
    while(r || !st.empty()){
        if(r){
            st.push(r);
            r=r->left;
        }
        else{
            r=st.top();
            st.pop();
            cout<<r->data<<" ";
            r=r->right;
        }
    }
}

void Ilevelorder(node *r){
  queue<node *> q;
  q.push(r);
  while(!q.empty()){
    node *t=q.front();
    q.pop();
    cout<<t->data<<" ";
    if(t->left) q.push(t->left);
    if(t->right) q.push(t->right);
  }
}

int countnode(node* r){
  if(r==nullptr) return 0;
  int x=countnode(r->left);
  int y=countnode(r->right);
  return x+y+1;
}

int value(node* r){
  if(r==nullptr) return 0;
  int x=value(r->left);
  int y=value(r->right);
  return x+y+r->data;
}

int binarynode(node *r){
  if(r==nullptr) return 0;
  if(r->left && r->right) return binarynode(r->left) + binarynode(r->right) + 1;
}

int height(node* r){
  if(r==nullptr) return 0;
  int x=height(r->left);
  int y=height(r->right);
  if(x>y) return x+1;
  else return y+1;
}

int leafnode(node* r){
  if(r==nullptr) return 0;
  if(!r->left && !r->right){
    return 1;
  }
  return leafnode(r->left) + leafnode(r->right);
}

bool BIsearch(node* r, int key){
  while(r){
    if(r->data==key) return true;
    else if(r->data<key){
      r=r->right;
    }
    else{
      r=r->left;
    }
  }
  return false;
}

bool BRsearch(node *r, int key){
  if(r==nullptr){
    return false;
  }
  else if(r->data==key) return true;
  else if(r->data<key){
    return BRsearch(r->right,key);
  }
  else{
    return BRsearch(r=r->left,key);
  }
}

node *Binsert(node* r,int key){
  node *t=new node(key),*root=r;
  if(r==nullptr) return t;
  node *last=r;
  while(r){
    if(r->data>key){
      last=r;
      r=r->left;
    }
    else{
      last=r;
      r=r->right;
    }
  }
  if(r==nullptr){
    if(last->data>key){
      last->left=t;
    }
    else{
      last->right=t;
    }
  }
  return root;
}

node* RBinsert(node *r, int key){
  if(r==nullptr){
    node* temp=new node(key);
    return temp;
  }
  else if(r->data>key){
    node* t=RBinsert(r->left,key);
    if(r->data>t->data){
      r->left=t;
      return r;
    }
    else{
      r->right=t;
      return r;
    }
  }
  else{
    node *t=RBinsert(r->right,key);
    if(r->data>t->data){
      r->left=t;
      return r;
    }
    else{
      r->right=t;
      return r;
    }
  }
}

node *inorderpredecesor(node *r){
  r=r->left;
  while(r->right){
    r=r->right;
  }
  return r;
}

node *Bdelete(node *r, int key){
  if(r==nullptr){
    return nullptr;
  }
  else if(!r->left && !r->right && r->data==key){
    delete r;
    return nullptr;
  }
  else if((!r->left && r->right && r->data==key) || (r->left && !r->right && r->data==key)){
    return (r->left)?r->left:r->right;
  }
  else if(key < r->data){
    r->left=Bdelete(r->left,key);
  }
  else if(key > r->data){
    r->right=Bdelete(r->right,key);
  }
  else{
    node * p=inorderpredecesor(r);
    r->data=p->data;
    r->left=Bdelete(r->left,p->data);
  }
  return r;
}

node* bst_from_preorder(vector<int> arr){
  node *root=nullptr;
  stack<node *> st;
  if(root==nullptr){
    root=new node(arr[0]);
  }
  unsigned i=1;
  node *last=root;
  while(!st.empty() || i<arr.size()){
    if(last->data > arr[i]){
      node *t=new node(arr[i]);
      st.push(last);
      last->left=t;
      st.push(last);
      last=t;
      i++;
    }
    else if(st.empty()){
      node *t=new node(arr[i]);
        last->right=t;
        last=t;
        i++;
    }
    else{
      node *x=st.top();
      if(x->data > arr[i]){
        node *t=new node(arr[i]);
        last->right=t;
        last=t;
        i++;
      }
      else{
        last=x;
        st.pop();
      }
    }
  }
  return root;
}

int calculateHeight(node *r){
  int x=(r && r->left)?r->left->height:0;
  int y=(r && r->right)?r->right->height:0;

  return (x>y)?x+1:y+1;
}

int balancefactor(node *r){
  return calculateHeight(r->left) - calculateHeight(r->right);
}

node *LLrotation(node *r){
  node *rl=r->left;
  r->left=r->left->right;
  rl->right=r;
  r->height=calculateHeight(r);
  rl->height=calculateHeight(rl);
  return rl;
}

node *LRrotation(node *r){
  node* rl=r->left,*rlr=r->left->right;
  rl->right=rlr->left;
  rlr->left=rl;
  r->left=rlr;
  r->height=calculateHeight(r);
  rl->height=calculateHeight(rl);
  rlr->height=calculateHeight(rlr);
  return LLrotation(r);
}

node *RRrotation(node *r){
  node* rr=r->right;
  r->right=rr->left;
  rr->left=r;
  r->height=calculateHeight(r);
  rr->height=calculateHeight(rr);
  return rr;
}

node *RLrotation(node *r){
  node* rr=r->right, *rrl=r->right->left;
  rr->left=rrl->right;
  rrl->right=rr;
  r->right=rrl;
  r->height=calculateHeight(r);
  rrl->height=calculateHeight(rrl);
  rr->height=calculateHeight(rr);
  return RRrotation(r);
}

node *InsertAVL(node *root, int key){
  if(!root){
    node *t=new node(key);
    t->height=1;
    return t;
  }
  else if(key > root->data){
    root->right=InsertAVL(root->right, key);
  }
  else if(key < root->data){
    root->left=InsertAVL(root->left, key);
  }
  root->height=calculateHeight(root);

  if(balancefactor(root)==2 && balancefactor(root->left)==1){
    // LL rotation
    return LLrotation(root);
  }
  else if(balancefactor(root)==2 && balancefactor(root->left)==-1){
    // LR rotation
    return LRrotation(root);
  }
  else if(balancefactor(root)==-2 && balancefactor(root->right)==1){
    // RL rotation
    return RLrotation(root);
  }
  else if(balancefactor(root)==-2 && balancefactor(root->right)==-1){
    // RR rotation
    return RRrotation(root);
  }

  return root;
}

void left_boundary(node *r, vector<int> &ds){
  if(!r->left && !r->right){
    return ;
  }
  if(r->left){
    r=r->left;
    ds.push_back(r->data);
  }
  else if(r->right){
    r=r->right;
    ds.push_back(r->data);
  }
  left_boundary(r,ds);
}

void leaf_traversal(node *r, vector<int> &ds){
  if(r){
    leaf_traversal(r->left,ds);
    if(!r->left && !r->right){
      ds.push_back(r->data);
    }
    leaf_traversal(r->right,ds);
  }
}

void right_boundary(node *r, vector<int> &ds){
  if(r->right){
    r=r->right;
    right_boundary(r,ds);
    ds.push_back(r->data);
  }
  else if(r->left){
    r=r->left;
    right_boundary(r,ds);
    ds.push_back(r->data);
  }
}

vector<int> boundary_order(node *r){
  vector<int> ans;
  ans.push_back(r->data);
  left_boundary(r,ans);
  leaf_traversal(r,ans);
  right_boundary(r,ans);
  return ans;
}

void topview(node *r){
  queue<pair<node *,int>> q;
  map<int,int> mp;
  if(r) q.push({r,0});

  while(!q.empty()){
    pair<node *,int> t=q.front(); q.pop();
    node *node_value=t.first;
    int x=t.second;
    if(mp.find(x)==mp.end()){
      mp[x]=node_value->data;
    }

    if(node_value->left){
      q.push({node_value->left,x-1});
    }
    if(node_value->right){
      q.push({node_value->right,x+1});
    }
  }
  for(auto it:mp){
    cout<<it.second<<" ";
  }
}

void bottomview(node *r){
  queue<pair<node *,int>> q;
  map<int,int> mp;
  if(r) q.push({r,0});

  while(!q.empty()){
    pair<node *,int> t=q.front(); q.pop();
    node *node_value=t.first;
    int x=t.second;
    
    mp[x]=node_value->data;

    if(node_value->left){
      q.push({node_value->left,x-1});
    }
    if(node_value->right){
      q.push({node_value->right,x+1});
    }
  }
  for(auto it:mp){
    cout<<it.second<<" ";
  }
}

void root2node(node* r,int key,bool &flag, vector<int> &ans){
  if(r){
    if(flag) ans.push_back(r->data);
    if(r->data==key){
      flag=false;
    }
    
    root2node(r->left,key,flag, ans);
    
    root2node(r->right,key,flag,ans);
    if(flag) ans.pop_back();
  }
}

node *children_sum_tree(node *r){
  if(!r){
    return nullptr;
  }
  int child=0;
  if(r->left) child+=r->left->data;
  if(r->right) child+=r->right->data;

  if(child >= r->data){
    r->data=child;
  } else{
    if(r->left) r->left->data=r->data;
    if(r->right) r->right->data=r->data;
  }
  children_sum_tree(r->left);
  children_sum_tree(r->right);

  int tot=0;
  if(r->left) tot+=r->left->data;
  if(r->right) tot+=r->right->data;

  if(r->left || r->right) r->data=tot;

  return r;
}

void mapping_parent(node *r,unordered_map<node *,node *> &mp,unordered_map<node *,bool> &marked){
  if(r){
    if(r->left) mp[r->left]=r;
    if(r->right) mp[r->right]=r;
    marked[r]=false;
    mapping_parent(r->left, mp, marked);
    mapping_parent(r->right, mp, marked);
  }
}

int burn_tree(node * p, node *r){
  unordered_map<node *,node *> mp;
  unordered_map<node *,bool> marked;
  mapping_parent(p,mp,marked);
  queue<node *> visited;
  if(r){
    visited.push(r);
    marked[r]=true;
  }
  int ans=0;
  while(!visited.empty()){
    int n=visited.size();
    for(int i = 0; i < n; i++) {
      node *cur = visited.front();
      visited.pop();

      if(cur->left && !marked[cur->left]) {
          visited.push(cur->left);
          marked[cur->left] = true;
      }
      if(cur->right && !marked[cur->right]) {
          visited.push(cur->right);
          marked[cur->right] = true;
      }
      if(mp.count(cur) && !marked[mp[cur]]) {
          visited.push(mp[cur]);
          marked[mp[cur]] = true;
      }
    }
    ans++;
  }
  return ans-1;
}

int main(){
  node* r=create();
  return 0;
}

