class Solution {
public:
    int longestPalindromeSubseq(string s) {
         int n=s.length();
    string t=s;
        
        reverse(t.begin(),t.end());
        
        vector<vector<int>> dp(n+1,vector<int> (n+1,0));
        int ans=0;
        
        for(int i=1;i<n+1;i++)
        {
            for(int j=1;j<n+1;j++)
            {
                
                if(s[i-1]==t[j-1])
                {
            dp[i][j]=1+dp[i-1][j-1];
                  //  ans=max(ans,dp[i][j]);
                }
                else
                {
                    dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
                    
                }
                
            }
        }
        
        
        
        
    return dp[n][n];
    }
};