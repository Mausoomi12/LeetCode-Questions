class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for(int i=31;i>=0;i--){
            int count = 0;
            for(int j=0;j<nums.size();j++){
                if((nums[j]>>i) & 1){
                    count++;
                }
            }
            if(count%3){
                ans += (1<<i);
            }
        }
        return ans;
    }
};