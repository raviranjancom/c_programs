#include<iostream>
#include<bits/stdc++.h>
#include<vector>
#include<queue>
using namespace std;

void BFS(vector<vector<int>> &matrix,int start, int n){
    queue<int> q;
    int visited[n]={0};
    printf("%d ",start+1);
    visited[start]=1;
    q.push(start);
    while(!q.empty()){
        int i=q.front();
        q.pop();
        // exploring the nodes
        for(int j=0;j<n;j++){
            if(visited[j]==0 && matrix[i][j]==1){
                printf("%d ",j+1);
                q.push(j);
                visited[j]=1;
            }
        }
    }
}
void DFS(vector<vector<int>> &matrix,int visited[], int start, int n){
    if(visited[start]==0){
        printf("%d ",start+1);
        visited[start]=1;
        for(int i=0;i<n;i++){
            if(matrix[start][i]==1){
                DFS(matrix,visited,i,n);
            }
        }
    }
}
int main(){
    vector<vector<int>> matrix={{0,1,1,1,0,0,0},
                                {1,0,1,0,0,0,0},
                                {1,1,0,1,1,0,0},
                                {1,0,1,0,1,0,0},
                                {0,0,1,1,0,1,1},
                                {0,0,0,0,1,0,0},
                                {0,0,0,0,1,0,0}};
    int n=matrix.size();
    int start=1;
    // BFS(matrix,start-1,n);
    int visited[n]={0};
    DFS(matrix,visited,start-1,n);
    return 0;
}
