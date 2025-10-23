#include<bits/stdc++.h>
using namespace std;

int main(){
    int jobs[]={4,3,7,1,2};
    int n=5;
    int *x=jobs;
    sort(x,x+n);
    int wait=0,ans=0;
    for(int i=0;i<n;i++){
        ans+=wait;
        wait+=jobs[i];
    }
    cout<<ans/n<<endl;
    return 0;
}
