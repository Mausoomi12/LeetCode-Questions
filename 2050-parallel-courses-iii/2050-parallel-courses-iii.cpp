class Solution {
public:
    int dp[(int)5e4 + 1];
    int dfs(int node, vector<int> &time, vector<int> adj[])
    {
        if (dp[node] != -1)
            return dp[node];

        int ans = 0;
        for (auto i : adj[node])
            ans = max(ans, dfs(i, time, adj));

        return dp[node] = time[node - 1] + ans;
    }

    int minimumTime(int n, vector<vector<int>> &relations, vector<int> &time)
    {
        memset(dp, -1, sizeof(dp));

        vector<int> adj[n + 1], out(n + 1);
        for (auto i : relations)
        {
            adj[i[1]].push_back(i[0]);
            out[i[0]]++;
        }

        int ans = 0;
        for (int i = 1; i <= n; i++)
            if (out[i] == 0)
                ans = max(ans, dfs(i, time, adj));

        return ans;
    }
};