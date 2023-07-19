class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int ans=0;
        int prev=nums[0][1];
        // for(auto it:nums) cout<<"["<<it[0]<<","<<it[1]<<"]";
        for(int i=1;i<n;i++){
            if(prev>nums[i][0]){
                ans++;
                prev=min(prev,nums[i][1]);
            }
            else prev=nums[i][1];
        }
        return ans;
    }
};