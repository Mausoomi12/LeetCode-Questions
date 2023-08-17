class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        // map <int, int> mp;
        set<int> s1;
        vector<int> ans;

        for (int i = 0; i < nums1.size(); i++) {
            s1.insert(nums1[i]);
        }

        for (int i = 0; i < nums2.size(); i++) {
            if (s1.count(nums2[i])) {
                ans.push_back(nums2[i]);
                s1.erase(nums2[i]); // Remove the element from set to avoid duplicates
            }
        }
        return ans;
    }
};
