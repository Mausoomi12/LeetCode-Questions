class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        int n = nums.size();
        int prev = nums[n - 1];
        long long int ans = 0;

        int i = n - 2;
        while(i >= 0){
            if(nums[i] > prev){
                long long int total_divide = (nums[i] - 1)/prev;
                prev = nums[i]/(total_divide + 1);
                ans += total_divide;
            }
            else{
                prev = nums[i];
            }
            i--;
        }
        return ans;
    }
};