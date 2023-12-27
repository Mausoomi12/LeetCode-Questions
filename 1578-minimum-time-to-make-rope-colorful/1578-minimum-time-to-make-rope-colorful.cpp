class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int ans = 0;
        for (int i = 0; i < colors.length() - 1; i++) {
            char curr = colors[i];
            char next = colors[i + 1];
            if (curr == next) {
                ans += min(neededTime[i], neededTime[i + 1]);
                neededTime[i + 1] = max(neededTime[i], neededTime[i + 1]);
            }
        }
        return ans;
    }
};