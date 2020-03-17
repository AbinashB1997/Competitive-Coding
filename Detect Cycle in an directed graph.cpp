bool check(int u, vector<bool>visited, vector<int> adj[]) {
    visited[u] = true;
    for(int i : adj[u]) {
        if(visited[i]) {
            return true;
        }else if(check(i, visited, adj)){
            return true;
        }
    }
    visited[u] = false;
    return false;
}


bool isCyclic(int V, vector<int> adj[])
{
    vector<bool> visited(V, false);
    for(int i = 0; i < V; i++) {
        if(check(i, visited, adj)) {
            return true;
        }
    }
    return false;
}