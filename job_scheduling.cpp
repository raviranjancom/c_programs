#include<iostream>
#include<bits/stdc++.h>
using namespace std;
bool comparator(pair<int,int>& val1,pair<int,int>& val2){
    return (val1.second>val2.second);
}
int main(){
    vector<pair<int,int>> jobs={{2,80},{6,70},{6,65},{5,60},{4,25},{2,22},{4,20},{2,10}};
    sort(jobs.begin(),jobs.end(),comparator);
    int n=8;
    int ans[n];
    int profit=0;
    memset(ans,-1,sizeof(ans));
    for(int i=0;i<8;i++){
        int j=jobs[i].first;
        while(j>=0){
            if(ans[j]==-1){
                ans[j]=jobs[i].second;
                profit+=jobs[i].second;
                break;
            }
            j--;
        }
    }
    for(int it:ans){
        cout<<it<<" ";
    }
    return 0;
}
