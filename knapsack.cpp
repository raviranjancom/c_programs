#include<bits/stdc++.h>
using namespace std;

bool comp(pair<double,double> &a,pair<double,double> &b){
    return (a.first/a.second)>(b.first/b.second);
}
int main(){
    vector<pair<double,double>> ds={{100,20},{60,10},{100,50},{200,50}};
    double wt=90,ans=0;
    sort(ds.begin(),ds.end(),comp);
    for(auto &it:ds){
        if(it.second<wt){
            ans+=it.first;
            wt-=it.second;
        }
        else{
            ans+=(wt/it.second)*it.first;
            wt=0;
            break;
        }
    }
    cout<<ans;
    return 0;
}
