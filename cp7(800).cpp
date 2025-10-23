#include<bits/stdc++.h>
#include<string>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m,ans=-1;
        string x,s;
        cin>>n>>m>>x>>s;
        for(int i=0;i<=5;i++){
            auto p=x.find(s);
            if(p!=std::string::npos){
                ans=i;
                break;
            }
            else{
                x=x+x;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
