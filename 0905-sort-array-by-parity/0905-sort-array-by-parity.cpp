class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int j=nums.size()-1;
        for(int i=0; i<j; ){
            if((nums[i]&1)==1 && (nums[j]&1)==0){
                swap(nums[i], nums[j]);
                i++, j--;
            }
            else{
                if ((nums[i]&1)==0) i++;
                if ((nums[j]&1)==1) j--;
            } 
        }
        return nums;
    }
};