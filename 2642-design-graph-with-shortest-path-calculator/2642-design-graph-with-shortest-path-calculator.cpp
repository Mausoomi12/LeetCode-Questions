class Graph {
public:
    vector<vector<pair<int,int>>>adj;
    
    Graph(int n, vector<vector<int>>& edges) {
        for(int i=0;i<n;i++)
        {
            vector<pair<int,int>>vp;
            adj.push_back(vp);
        }
        for(int i=0;i<edges.size();i++)
            adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
    }
    
    void addEdge(vector<int> edge) {
        adj[edge[0]].push_back({edge[1],edge[2]});
    }
    
    int shortestPath(int node1, int node2) {
        if(node1==node2)
            return 0;
        vector<int>visited(adj.size(),INT_MAX);
        queue<int>q;
        q.push(node1);
        visited[node1]=0;
        while(!q.empty())
        {
            int temp=q.front();
            q.pop();
            if(temp==node2)
            {
                continue;
            }
            for(int i=0;i<adj[temp].size();i++)
            {
                if(visited[adj[temp][i].first]>visited[temp]+adj[temp][i].second)
                {
                    visited[adj[temp][i].first]=visited[temp]+adj[temp][i].second;
                    q.push(adj[temp][i].first);
                }
            }
        }
        return visited[node2]==INT_MAX?-1:visited[node2];
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */