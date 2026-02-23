#include<bits/stdc++.h>
using namespace std;
bool isprime(int n){
    int count=0;
    for(int i=2;i<=pow(n, 0.5);i++){
        if(n%i==0) count++;
    }
    if(count>0) return true;
    return false;
}
bool isPrime_(int n){
    if(n<2) return false;
    if(n==2 || n==3 || n==5){
        cout<<"Yes!\n";
        return true;
    }
    if(n%2==0 || n%3==0 || n%5==0){
        cout<<"No!\n";
        return false;
    }
    for(int k=6;(k+1)*(k+1)<=n;k+=6){
        int x=(k-1);
        int y=(k+1);

        if(n%x==0 || n%y==0){
            cout<<"No!\n";
            return false;
        }
    }
    cout<<"Yes!\n";
    return true;
}
int main(){
    int n=293;
    isPrime_(n);
    return 0;
}
