#include <bits/stdc++.h>
using namespace std;
class Heap{
    public:
        vector<int> arr;
        Heap(){}
        void push(int x){
            arr.push_back(x);
            int n=arr.size()-1;
            while(n>0){
                if(arr[((n+1)/2-1)]>arr[n]){
                    swap(arr[((n+1)/2-1)],arr[n]);
                }
                else{
                    break;
                }
                n=((n+1)/2)-1;
            }
            return ;
        }
        int top(){
            if(arr.size()==0) return -1;
            return arr[0];
        }
        void pop(){
            if(arr.size()==0) return ;
            arr[0]=arr.back();
            arr.pop_back();
            int n=0;
            
            while(n<arr.size()){
                int x=1e9,y=1e9;
                if(2*(n+1)<arr.size()) x=arr[(2*(n+1))-1];
                if((2*(n+1))+1<arr.size()) y=arr[2*(n+1)];
                int mini=min(x,y);
                if(mini<arr[n]){
                    if(mini==x){
                        swap(arr[(2*(n+1))-1],arr[n]);
                        n=2*(n+1)-1;
                    }
                    else{
                        swap(arr[2*(n+1)],arr[n]);
                        n=2*(n+1);
                    }
                }
                else{
                    break;
                }
            }
            return ;
        }
        void print(){
            for(auto it:arr){
                cout<<it<<" ";
            }
            cout<<endl;
            return ;
        }
};

int main(){
	Heap pq;
	pq.push(3);
	pq.push(2);
	pq.push(5);
	pq.push(1);
	pq.push(4);
	pq.print();
	pq.pop();
	pq.print();
	
	return 0;
}
