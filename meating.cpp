#include<bits/stdc++.h>
using namespace std;
// sort by endtime and then check by endtime that if it will fit or not...
bool comparator(pair<int,int> &a,pair<int,int> &b){
    return (a.second<b.second);
}
int main(void){
    vector<pair<int,int>> meating={{0,5},{3,4},{1,2},{5,9},{5,7},{8,9}};
    sort(meating.begin(),meating.end(),comparator);
    vector<pair<int,int>> ans;
    int endtime=-1;
    for(unsigned i=0;i<meating.size();i++){
        if(meating[i].first>endtime){
            endtime=meating[i].second;
            ans.push_back(meating[i]);
        }
    }
    for(pair<int,int>& it:ans){
        cout<<it.first<<" "<<it.second<<endl;
    }
    return 0;
}
