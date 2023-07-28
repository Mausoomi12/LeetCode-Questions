class Solution {
public:
    int dfs(int i , int j ,vector<int>& nums , int turn){
        if(i == nums.size() || j == -1) return 0;
        if(i > j) return 0;
        if(turn == 0){
            return max(nums[i] + dfs(i + 1 , j , nums , 1), 
                       nums[j] + dfs(i , j - 1 , nums , 1));
        }
        else{
            return min(-nums[i] + dfs(i + 1 , j , nums , 0),
                       -nums[j] + dfs(i , j - 1 , nums , 0));
        }
    }
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        int val = dfs(0 , n - 1 , nums , 0);
        return val >= 0;
    }
};