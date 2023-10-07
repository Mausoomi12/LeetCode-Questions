class Solution {
public:
    const long long mod = 1e9+7;

    int dp[51][101][51]; // (n, maxN, cost)
    
    int f(int n, int maxN, int cost) {
        if (cost < 1 || maxN < 1) return 0;
        if (n == 1) return cost == 1;
        if (dp[n][maxN][cost] != -1) return dp[n][maxN][cost];
        // current maxN is not a new max, cost unchanged
        long long ans = ((long long)maxN * f(n-1, maxN, cost)) % mod;
        // current maxN is a new max, cost+1
        for (int i = 1; i < maxN; i++) // i is the old max
            ans = (ans + f(n-1, i, cost-1)) % mod;// old cost = cost-1
        return dp[n][maxN][cost] = ans % mod;
    }

    int numOfArrays(int n, int m, int k) {
        memset(dp, -1, sizeof(dp));
        long long ans = 0;
        for (int i = 1; i <= m; i++) 
            ans = (ans + f(n, i, k)) % mod;
        
        return ans;
    }
};