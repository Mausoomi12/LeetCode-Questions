class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int L = k, R = k;
        int minVal = nums[k];
        int maxScore = minVal;

        while(L > 0 || R < nums.size() - 1){
            if(L == 0 || (R < nums.size() - 1 && nums[L-1] < nums[R+1])){
                R++;
            }
            else{
                L--;
            }
            minVal = min(minVal, min(nums[L], nums[R]));
            maxScore = max(maxScore, minVal * (R - L + 1));
        }
        return maxScore;
    }
};