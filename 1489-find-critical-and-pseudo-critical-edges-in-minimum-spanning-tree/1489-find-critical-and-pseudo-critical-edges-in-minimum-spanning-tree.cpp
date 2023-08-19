class Solution {
public:
    // Define a DSU class for union-find operations
    class DSU {
        vector<int> parent, size;
    public:
        DSU(int n) {
            parent.resize(n);
            size.resize(n, 1);
            for (int i = 0; i < n; ++i)
                parent[i] = i;
        }
        
        int find(int x) {
            if (parent[x] != x)
                parent[x] = find(parent[x]);
            return parent[x];
        }
        
        bool unite(int x, int y) {
            int rootX = find(x);
            int rootY = find(y);
            if (rootX == rootY)
                return false;
            
            if (size[rootX] < size[rootY]) {
                parent[rootX] = rootY;
                size[rootY] += size[rootX];
            } else {
                parent[rootY] = rootX;
                size[rootX] += size[rootY];
            }
            
            return true;
        }

        int getSize(int x) {  // Add a public method to get the size of a set
            return size[find(x)];
        }
    };
    
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        int m = edges.size();
        for (int i = 0; i < m; ++i)
            edges[i].push_back(i); // Store the original index
        
        sort(edges.begin(), edges.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[2] < b[2];
        });
        
        DSU dsu(n);
        int mstWeight = 0;
        for (int i = 0; i < m; ++i) {
            if (dsu.unite(edges[i][0], edges[i][1]))
                mstWeight += edges[i][2];
        }
        
        vector<int> critical, pseudoCritical;
        for (int i = 0; i < m; ++i) {
            DSU tempDsu(n);
            int weightWithout = 0;
            for (int j = 0; j < m; ++j) {
                if (i != j && tempDsu.unite(edges[j][0], edges[j][1]))
                    weightWithout += edges[j][2];
            }
            
            if (tempDsu.getSize(0) != n || weightWithout > mstWeight)
                critical.push_back(edges[i][3]); // Store the original index
            else {
                DSU newDsu(n);
                newDsu.unite(edges[i][0], edges[i][1]);
                int weightWith = edges[i][2];
                for (int j = 0; j < m; ++j) {
                    if (i != j && newDsu.unite(edges[j][0], edges[j][1]))
                        weightWith += edges[j][2];
                }
                
                if (weightWith == mstWeight)
                    pseudoCritical.push_back(edges[i][3]); // Store the original index
            }
        }
        
        return {critical, pseudoCritical};
    }
};
