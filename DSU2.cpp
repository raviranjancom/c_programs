class rollback{
    public:
    int u,v;
    int sizeU,sizeV;
};
class DSU{
    public:
        vector<int> parent;
        vector<int> size;
        stack<rollback> history;
        DSU(int n){
            parent.resize(n+1);
            size.resize(n+1,1);
            for(int i=0;i<=n;i++){
                parent[i]=i;
            }
        }

        int findUPar(int node){
            while(node!=parent[node]){
                node=parent[node];
            }
            return node;
        }
        bool combine(int u,int v){
            int upU=findUPar(u);
            int upV=findUPar(v);
            if(upU==upV) return false;
            if(size[upU]<size[upV]){
                history.push({upU,upV,size[upU],size[upV]});
                parent[upU]=upV;
                size[upV]+=size[upU];
            }
            else{
                history.push({upV,upU,size[upV],size[upU]});
                parent[upV]=upU;
                size[upU]+=size[upV];   // larger one will grow in rank
            }
            return true;
        }
        void revert(){
            if(history.empty()) return ;
            auto it=history.top(); history.pop();
            parent[it.v]=it.v;
            parent[it.u]=it.u;
            size[it.v]=it.sizeV;
            size[it.u]=it.sizeU;
        }
};
class Solution {
  public:
    int m;
    bool check(DSU &ds,int n,int k){
        if(n-1==k){
            int p=ds.findUPar(0);
            for(int i=1;i<n;i++){
                if(p!=ds.findUPar(i)) return false;
            }
            return true;
        }
        return false;
    }
    int solve(DSU &ds,int n,vector<vector<int>>& edges,int idx,int k){
        if(k==n-1) return 1;
        if(idx==m) return 0;
        if(m-idx<n-1-k) return 0;
        
        int ans=0;
        int x=0;
        if(ds.combine(edges[idx][0],edges[idx][1])){
            x=solve(ds,n,edges,idx+1,k+1);
            ds.revert();
        }
        int y=solve(ds,n,edges,idx+1,k);
        return x+y;
    }
    int countSpanTree(int n, vector<vector<int>>& edges){
        DSU ds(n);
        m=edges.size();
        return solve(ds,n,edges,0,0);
    }
};

// 5 6
// 0 1
// 0 3
// 0 4
// 1 2
// 1 3
// 1 4
