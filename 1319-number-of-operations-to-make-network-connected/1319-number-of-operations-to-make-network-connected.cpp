class Solution {
public:
	//Depth First search function
    void dfs(int node,vector<vector<int>>&g,vector<int>&vis){
        vis[node]=0;
        for(auto&child:g[node]){
            if(vis[child]){
                dfs(child,g,vis);
            }
        }
    }
    int makeConnected(int n, vector<vector<int>>& conn) {
		//When we have no. of edges less than n-1 we cant make it happen as tree will not form
		//so return -1
        if(conn.size()<n-1){
            return -1;
        }
		//vector of vector for the adj list
        vector<vector<int>>g(n);
        for(int i=0;i<conn.size();i++){
            g[conn[i][0]].push_back(conn[i][1]);
            g[conn[i][1]].push_back(conn[i][0]);
        }
		//vector of int for storing the visited nodes
        vector<int>vis(n,1);
		//no of different connected components
        int connectedComponents=0;
		//Traversing to all the different connected components nodes
        for(int i=0;i<n;i++){
		//if not visited
            if(vis[i]){
                dfs(i,g,vis);
				//increase no of components
                connectedComponents++;
            }
        }
		//return no of components-1
        return connectedComponents-1;
    }
};