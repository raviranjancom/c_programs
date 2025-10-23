#include<iostream>
#include<vector>
using namespace std;

int count(vector<int> &ratings){
    int n=ratings.size();
    int i=1,peek=1,ans=1,down=1;
    while(i<n){
        if(ratings[i-1]==ratings[i]){
            ans+=1;
            i++;
        }
        
        while(i<n && ratings[i]>ratings[i-1]){
            peek++;
            ans+=peek;
            i++;
        }

        while(i<n && ratings[i]<ratings[i-1]){
            if(i==1) down=2;
            ans+=down;
            down++;
            i++;
        }
        down=1;
        if(peek<down){
            ans+=(peek-down);
        }
        peek=1;
        down=1;
    }
    return ans;
}
int main(){
    vector<int> ratings={0,1,2,5,3,2,7}; //{0,2,4,3,2,1,1,3,5,6,4,0,0};    // {0,2,4,7,6,5,4,3,2,1,1,1,2,3,4,2,1,1,1};
    cout<<count(ratings)<<endl;
    return 0;
}
