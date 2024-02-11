class Solution {
public:
               // please upvote if it help you\U0001f60a\U0001f60a
    int cherryPickup(vector<vector<int>>& grid) {
         int n=grid.size();
        int m=grid[0].size();

   vector < vector < vector < int >>> dp(n, vector < vector < int >> (m, 
  vector < int > (m, 0)));

        for(int i=0;i<m;i++){
            for(int j=0;j<m;j++){
                if(i==j) dp[n-1][i][j]=grid[n-1][i];
                else 
                dp[n-1][i][j]=grid[n-1][i]+grid[n-1][j];
            }
        }



        for (int i = n - 2; i >= 0; i--) {
    for (int j1 = 0; j1 < m; j1++) {
      for (int j2 = 0; j2 < m; j2++) {

        int maxi = INT_MIN;

   
        for (int di = -1; di <= 1; di++) {
          for (int dj = -1; dj <= 1; dj++) {

            int ans;

            if (j1 == j2)
              ans = grid[i][j1];
            else
              ans = grid[i][j1] + grid[i][j2];

            if ((j1 + di < 0 || j1 + di >= m) ||
              (j2 + dj < 0 || j2 + dj >= m))

              ans += -1e9;
            else
              ans += dp[i + 1][j1 + di][j2 + dj];

            maxi = max(ans, maxi);
          }
        }
        dp[i][j1][j2] = maxi;
      }
    }
  }

  return dp[0][0][m - 1];
    }
};