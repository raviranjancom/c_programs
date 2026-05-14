class Solution {
  public:
  //my solution
    int n,m;
    vector<int> LPS;
    vector<int> ans;
    void fillLPS(vector<int> &b){
        LPS[0]=0;
        int i=1;
        int length=0;
        while(i<m){
            if(b[i]==b[length]){
                length++;
                LPS[i]=length;
                i++;
            }
            else{
                if(length>0) length=LPS[length-1];
                else{
                    LPS[i]=0;
                    i++;
                }
            }
        }
        return ;
    }
    void solve(vector<int> &a, vector<int> &b){
        int i=0,j=0;
        while(i<n){
            if(a[i]==b[j]){
                i++;
                j++;
                if(j==m){
                    ans.push_back(i-j);
                    j=LPS[j-1];
                }
            }
            else{
                if(j>0) j=LPS[j-1];
                else i++;
            }
        }
    }
    vector<int> search(vector<int> &a, vector<int> &b) {
        n=a.size();
        m=b.size();
        LPS.assign(m,0);
        fillLPS(b);
        solve(a,b);
        return ans;
    }
};
