class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int, int> freq;
        for (auto& num : nums) freq[num]++;
        int op = 0;
        for (auto& [v, f] : freq) {
            if (f == 1) return -1;
            op += getMinOp(f);
        }
        return op;
    }
private:
    int getMinOp(int f) {
        int op = 0;
        if (f >= 3) {
            int times = f / 3;
            f -= (3 * times);
            op += times;
        }
        if (f == 1) f += 3, op--;
        if (f >= 2) {
            int times = f / 2;
            f -= (2 * times);
            op += times;
        }
        return op;
    }
};