class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        int n=nums.size();
        int m =n/3;
        vector<vector<int>> ans(m);
        vector<vector<int>> invalid;
        sort(nums.begin(),nums.end());
        int index=0;
        int count=1;
        int dif=0;
        ans[index].push_back(nums[0]);

        for(int i=1;i<n;i++){
            if((nums[i]-nums[i-1] + dif)>k) return invalid;
            dif+=nums[i]-nums[i-1];
            ans[index].push_back(nums[i]);
            count++;
            if(count==3 && i!=n-1){
                count=0;
                index++;
                dif=0;
                i++;
                ans[index].push_back(nums[i]);
                count++;
            }
        }

        return ans;

    }
};