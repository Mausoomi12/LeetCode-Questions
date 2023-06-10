class Solution {
public:
    int maxValue(int n, int index, int maxSum) {
        int lo = 1, hi = INT_MAX;
        while(lo < hi - 1) {
            long mid = lo + (hi - lo) / 2;
            long sum = Sum(index, n, mid);
            if (sum == maxSum) {
                return mid;
            } else if (sum > maxSum) {
                hi = mid;
            } else {
                lo = mid;
            }
        }
        return Sum(index, n, hi) <= maxSum ? hi : lo;
    }
private:
    long Sum(int index, int n, int val) {
        return SumSide(index + 1, val) + SumSide(n - index, val) - val;
    }
    long SumSide(int num, int val) {
        return GaussSum(std::min(num, val), val) + std::max(0, num - val);
    }
    long GaussSum(int num, int val) {
        long left = val - num + 1;
        long right = val;
        long sum = static_cast<long>(num / 2) * (left + right);
        if (num % 2 == 1) sum += left + (right - left) / 2;
        return sum;
    }
};