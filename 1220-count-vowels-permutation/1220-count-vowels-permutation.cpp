class Solution {
public:
    const long long mod = 1e9+7;
    int countVowelPermutation(int n) {
        vector<vector<long long>> dp(2, vector<long long>(5, 0));
        dp[n & 1].assign(5, 1);

        for (int j = n - 1; j >= 1; j--) {
            dp[j&1][0] = (dp[(j+1)&1][1]) % mod;
            dp[j&1][1] = (dp[(j+1)&1][0] + dp[(j+1)&1][2]) % mod;
            dp[j&1][2] = (dp[(j+1)&1][0] + dp[(j+1)&1][1] + dp[(j+1)&1][3] + dp[(j+1)&1][4]) % mod;
            dp[j&1][3] = (dp[(j+1)&1][2] + dp[(j+1)&1][4]) % mod;
            dp[j&1][4] = (dp[(j+1)&1][0]) % mod;
        }

        long long ans = 0;
        for (int j = 0; j < 5; j++) {
            ans = (ans + dp[1][j]) % mod;
        }

        return ans;
    }
};