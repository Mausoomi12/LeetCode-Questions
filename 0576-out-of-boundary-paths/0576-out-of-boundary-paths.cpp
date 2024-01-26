class Solution {
private:
    int dfs(int m, int n, int maxMove, int row, int col , vector<vector<vector<int>>>& dp) {
        // Base case: if out of bounds, return 1 (since it contributes to the answer)
        if (row < 0 || row >= m || col < 0 || col >= n) {
            return 1;
        }
        // Base case: if maxMove is reached, return 0 (no more moves)
        if (maxMove == 0) {
            return 0;
        }
        if(dp[row][col][maxMove] != -1) return dp[row][col][maxMove];


        long long ans = 0;
        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};

        for (int i = 0; i < 4; i++) {
            int new_row = row + delrow[i];
            int new_col = col + delcol[i];

            // Recursive call to explore the next position
            ans += dfs(m, n, maxMove - 1, new_row, new_col , dp);
            ans %= 1000000007;
        }

        return dp[row][col][maxMove] = ans;
    }
public:
    int findPaths(int m, int n, int maxMove, int sr, int sc) {
        vector<vector<vector<int>>>dp(m , vector<vector<int>>(n , vector<int>(maxMove + 1 , -1)));
        return dfs(m, n, maxMove, sr, sc , dp) % 1000000007;
    }
};
