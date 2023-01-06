class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
    int n = nums.size();

    // Sort the array in ascending order
    sort(nums.begin(), nums.end());

    for (int i = 0; i < n - 2; i++) {
        // Skip duplicate values of nums[i]
        if (i > 0 && nums[i] == nums[i - 1]) continue;

        int j = i + 1, k = n - 1;
        while (j < k) {
            int sum = nums[i] + nums[j] + nums[k];
            if (sum == 0) {
                // Add the triplet to the result vector
                result.push_back({nums[i], nums[j], nums[k]});
                // Skip duplicate values of nums[j] and nums[k]
                while (j < k && nums[j] == nums[j + 1]) j++;
                while (j < k && nums[k] == nums[k - 1]) k--;
                j++;
                k--;
            } else if (sum < 0) {
                // If the sum is negative, increase j to decrease the sum
                j++;
            } else {
                // If the sum is positive, decrease k to decrease the sum
                k--;
            }
        }
    }

    return result;
}

int main() {
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> result = threeSum(nums);

    for (auto& triplet : result) {
        cout << triplet[0] << " " << triplet[1] << " " << triplet[2] << endl;
    }

    return 0;
    }
};