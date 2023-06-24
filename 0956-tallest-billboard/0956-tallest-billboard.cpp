class Solution {
public:
    int dp[20][10001];
    int solve(int idx, int dif, vector<int> &rods)
    {
        if(idx == rods.size())
        {
            if(dif == 0)
            {
                return 0;
            }

            return -1e5;
        }

        if(dp[idx][dif + 5000] != -1)
        {
            return dp[idx][dif + 5000];
        }

        // dif = num1 - nums2
        int ans1 = solve(idx+1, dif, rods);  

        // (nums1 + rods[idx]) - nums2 = (nums1 - nums2) + rods[idx]   = d + rods[idx]
        int ans2 = rods[idx] + solve(idx+1, dif + rods[idx], rods); 

        // nums1 - (nums2 + rods[idx]) = (nums1 - nums2) - rods[idx] = d - rods[idx]
        int ans3 = rods[idx] + solve(idx+1, dif - rods[idx], rods);  

        return dp[idx][dif + 5000] = max(ans1, max(ans2, ans3));
    }
    int tallestBillboard(vector<int>& rods) {
        memset(dp, -1, sizeof(dp));
        int ans = solve(0,0,rods)/2; 
        return ans;
    }
};