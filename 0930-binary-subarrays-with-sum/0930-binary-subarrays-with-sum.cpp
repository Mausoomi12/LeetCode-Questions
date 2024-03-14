class Solution {
public:
    int sumAtMost(const vector<int>& nums, int goal) {
        if (goal < 0) return 0;

        int res = 0;
        int prev = 0;
        int cur = 0;
        for (int i = 0; i < nums.size(); i++) {
            cur += nums[i];
            while (cur > goal)
                cur -= nums[prev++];
            res += i - prev + 1;
        }

        return res;
    }
    
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return sumAtMost(nums, goal) - sumAtMost(nums, goal - 1);
    }
};