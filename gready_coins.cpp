#include<iostream>
#include<vector>
using namespace std;

int main(){
    int coins[]={1,2,3,5,10,20,50,100,500,1000};
    int target=49,count=0;
    vector<int> ans;
    for(int i=sizeof(coins)/sizeof(coins[0])-1;i>=0;i--){
        while(coins[i]<=target){
            ans.push_back(coins[i]);
            count++;
            target-=coins[i];
        }
    }
    cout<<count<<endl;
    return 0;
}
