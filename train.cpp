#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

void method1(){
    int n=6,ans=0;
    vector<pair<int,int>> schedule={{900,920},{945,1200},{955,1130},{1100,1150},{1500,1900},{1800,2000}};
    vector<bool> check(n,true);
    for(int i=0;i<n;i++){
        int x=i-1;
        bool increase=true;
        while(x>=0){
            if(schedule[i].first>schedule[x].second && check[x]){
                increase=false;
                check[x]=false;
                break;
            }
            x--;
        }
        if(increase) ans++;
    }
    cout<<ans<<endl;
}
void method2(){
    int n=6,ans=0;
    int start[]={900,945,955,1100,1500,1800};
    int depart[]={920,1200,1130,1150,1900,2000};
    int *x=depart;
    sort(x,x+n);
    int i=0,j=0,count=0;
    while(i<n && j<n){
        if(start[i]<depart[j]){
            count++;
            i++;
        }
        else{
            count--;
            j++;
        }
        ans=max(ans,count);
    }
    cout<<ans<<endl;
}
int method3(){ // Incomplete If condition
    int n=6,ans=0;
    vector<pair<int,int>> schedule={{900,920},{945,1200},{955,1130},{1100,1150},{1500,1900},{1800,2000}};
    for(int i=0;i<n;i++){
        int count=0;
        for(int j=i+1;j<n;j++){
            if((schedule[i].first>schedule[j].first && schedule[i].second>schedule[j].second) || 
            (schedule[i].first<schedule[j].first && schedule[i].second<schedule[j].second) || 
            (schedule[i].first<schedule[j].first && schedule[i].second>schedule[j].second) || 
            (schedule[i].first>schedule[j].first && schedule[i].second<schedule[j].second)){
               count++;
            }
            ans=max(ans,count);
        }
    }
    cout<<ans<<endl;
}
int main(){
    method1();
    method2();
    method3();
    return 0;
}
