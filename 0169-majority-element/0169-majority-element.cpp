class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ans = 0;
        int e = (int)nums.size() / 2;
        int n = nums.size();
        while(1){
            int ind = rand() % n;
            int cnt = 0;
            for(auto &x : nums)
                if(x == nums[ind])
                {
                    cnt++;
                    if(cnt > e)
                        return nums[ind];
                }
        }
        return ans;
    }
};