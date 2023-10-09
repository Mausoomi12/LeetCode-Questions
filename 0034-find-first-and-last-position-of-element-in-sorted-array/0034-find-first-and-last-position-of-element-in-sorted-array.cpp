class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n=nums.size();
        if (n==0) return {-1, -1};
        int i=lower_bound(nums.begin(), nums.end(), target)-nums.begin();
        if (i==n || nums[i]>target) return {-1, -1};
        int j=upper_bound(nums.begin(), nums.end(), target)-nums.begin();
    //    cout<<i<<","<<j-1<<endl;
        return {i, j-1};
    }
};