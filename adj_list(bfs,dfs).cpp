#include<bits/stdc++.h>
using namespace std;

void dfs(vector<bool> &visited,vector<vector<int>> &adj,int start){
    visited[start]=true;
    cout<<start<<" ";
    for(int i : adj[start]){
        if(!visited[i]){
            dfs(visited,adj,i);
        }
    }
}

int main(){

    int n,temp,t;
    cin>>n;
    vector<vector<int>> adj(n);
    for(int i=0;i<n;i++){
        cin>>temp;
        for(int y=0;y<temp;y++){
            cin>>t;
            adj[i].push_back(t);
        }
    }
    bool visited[n]={};
    queue<int> q;
    cout<<"bfs traversal: ";
    for(int y=0;y<n;y++){
        if(!visited[y]){
            q.push(y);
            while(!q.empty()){

                visited[q.front()]=true;
                temp=q.front();
                q.pop();
                for(int i : adj[temp]){
                    if(!visited[i]){
                        visited[i]=true;
                        q.push(i);
                    }
                }
                cout<<temp<<" ";
            }
        }
    }
    cout<<endl;
    cout<<"dfs traversal: ";
    vector<bool> Visited(n,false);
    dfs(Visited,adj,3);
    for(int i=0;i<Visited.size();i++){
        if(!Visited[i]){
            dfs(Visited,adj,i);
        }
    }


    return 0;
}