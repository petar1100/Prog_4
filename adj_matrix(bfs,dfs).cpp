#include <bits/stdc++.h>
using namespace std;

void dfs(vector<bool> &visited,vector<vector<int>> matrix,int curr){
    visited[curr]=true;
    cout<<curr<<",";
    for(int i=0;i<matrix.size();i++){
        if(matrix[curr][i]==1 && !visited[i]){
            dfs(visited,matrix,i);
        }
    }
}

int main(){

    int n;
    cin>>n;
    vector<vector<int>> matrix(n,vector<int>(n));
    for(int i=0;i<n;i++){
        for(int y=0;y<n;y++){
            cin>>matrix[i][y];
        }
    }
    queue<int>q;
    vector<bool> visited(n,false);
    cout<<"bfs traversal: ";
    for(int i=0;i<n;i++){
        if(!visited[i]){
            q.push(i);
            visited[i]=true;
            while(!q.empty()){
                int temp=q.front();
                q.pop();
                cout<<temp<<",";
                for(int y=0;y<n;y++){
                    if(matrix[temp][y]==1 && !visited[y]){
                        q.push(y);
                        visited[y]=true;
                    }
                }
            }
        }
    }
    cout<<endl;
    vector<bool> v(n,false);
    cout<<"dfs traversal: ";
    for(int i=0;i<n;i++){
        if(!v[i]){
            dfs(v,matrix,i);
        }
    }


    return 0;
}