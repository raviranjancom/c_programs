#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class segmentTree{
    public:
    int n;
    vector<int> seg;
    segmentTree(int n){
        this->n=4*n;
        seg.resize(this->n);
    }
    void build(int idx,int low,int high,vector<int> &arr){
        if(low==high){
            seg[idx]=arr[low];
            return ;
        }
        int mid=(low+high)/2;
        build(2*idx+1,low,mid,arr);
        build(2*idx+2,mid+1,high,arr);
        
        seg[idx]=min(seg[2*idx+1],seg[2*idx+2]);
        return ;
    }
    int query(int idx,int low,int high,int l,int r){
        // no overlap
        // l r low high      low high l r
        if(l>high || r<low){
            return INT_MAX;
        }
        // complete overlap
        // l low high r
        else if(low>=l && high<=r){
            return seg[idx];
        }
        // partial overlap
        // l low r high      low l high r
        int mid=(low+high)/2;
        int left=query(2*idx+1,low,mid,l,r);
        int right=query(2*idx+2,mid+1,high,l,r);
        return min(left,right);
    }
    void update(int idx,int low,int high,int i,int val){
        if(low==high){
            seg[idx]=val;
            return ;
        }
        int mid=(low+high)>>1;
        if(i<=mid) update(2*idx+1,low,mid,i,val);
        else update(2*idx+2,mid+1,high,i,val);
        seg[idx]=min(seg[2*idx+1],seg[2*idx+2]);
    }
};

void solve(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    segmentTree seg(n);
    seg.build(0,0,n-1,arr);
    int q;
    cin>>q;
    while(q--){
        int type;
        cin>>type;
        if(type==1){
            int l,r;
            cin>>l>>r;
            cout<<seg.query(0,0,n-1,l,r)<<endl;
        }
        else if(type==2){
            int i,val;
            cin>>i>>val;
            seg.update(0,0,n-1,i,val);
            arr[i]=val;
        }
    }
}
int main(){
    solve();
    return 0;
}
