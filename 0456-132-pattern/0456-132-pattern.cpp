class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        stack<int> s;
        int currMax = INT_MIN;

        for (int i = nums.size() - 1; i >= 0; --i) {
            if (nums[i] < currMax) return true;

            while (!s.empty() && nums[i] > s.top()) {
                currMax = s.top();
                s.pop();
            }

            s.push(nums[i]);
        }

        return false;
    }
};