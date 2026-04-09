#include <bits/stdc++.h>
using namespace std;
    
vector<int> bfs(vector<vector<int>> & adj){
    int V = adj.size();
    vector<bool> visited(V, false);
    vector<int> ant(V, -1);
    queue<int> q;

    int src = 0;
    visited[src] = true;
    q.push(src);
    
    while(!q.empty()){
        int curr = q.front();
        q.pop();
        
        for(auto x: adj[curr]){
            if(!visited[x]){
                visited[x] = true;
                q.push(x);
                ant[x] = curr;
            }
        }
    }
    return ant;
}

int main(){
    vector<vector<int>> graph;
    int V, E;
    cin >> V >> E;

    graph.resize(V);

    for (int i = 0; i < E; i++){
        int v1, v2;
        cin >> v1 >> v2;
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }
}