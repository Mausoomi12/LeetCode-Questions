class Solution {
public:
    int numRollsToTarget(int n, int k, int target) {
        int mod = 1e9+7;
        vector<int> prev(target+1);
        prev[0] = 1;
        for(int i=1;i<=n;i++){
            vector<int> cur(target+1);
            for(int t=target;t>=0;t--){
                int ans = 0;
                for(int j=1;j<=min(k,t);j++){
                    ans=(0LL+ans+prev[t-j])%mod;
                }
                cur[t] = ans;
            }
            prev = cur;
        }
        return prev[target];
    }
};