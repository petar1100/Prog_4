#include <bits/stdc++.h>
using namespace std;

void dfs(vector<bool> &visited,vector<pair<int,int>> &el,int curr){
    visited[curr]=true;
    cout<<curr<<",";
    for(int i=0;i<el.size();i++){
        if(el[i].first==curr && !visited[el[i].second]){
            dfs(visited,el,el[i].second);
        }
        if(el[i].second==curr && !visited[el[i].first]){
            dfs(visited,el,el[i].first);
        }
    }
}

int main(){

    int n,t;
    cin>>n>>t;
    vector<pair<int,int>> el(t);
    for(int i=0;i<t;i++){
        cin>>el[i].first>>el[i].second;
    }
    queue<int> q;
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
                for(int y=0;y<t;y++){
                    if(el[y].first==temp && !visited[el[y].second]){
                        q.push(el[y].second);
                        visited[el[y].second]=true;
                    }
                    if(el[y].second==temp && !visited[el[y].first]){
                        q.push(el[y].first);
                        visited[el[y].first]=true;
                    }
                }
            }
        }
    }
    cout<<endl;
    cout<<"dfs traversal: ";
    vector<bool> v(n,false);
    for(int i=0;i<v.size();i++){
        if(!v[i]){
            dfs(v,el,i);
        }
    }




    return 0;
}