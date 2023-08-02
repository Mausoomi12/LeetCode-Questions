class Solution {
public:
    vector<vector<int>> arr;
    void backtrack(vector<int>& nums, int n, int index){
        if(index == n - 1){
            arr.push_back(nums);
            return;
        }
        for(int i=index; i<n; i++){
            swap(nums[index], nums[i]);
            backtrack(nums, n, index+1);
            swap(nums[index], nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        backtrack(nums, n, 0);
        return arr;
    }
};