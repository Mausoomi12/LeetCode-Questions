class Solution {
public:
    pair<int, int> PalindromeC(int i, int j, string& s) {
        int l = i, r = j;
        while (l >= 0 && r < s.size() && s[l] == s[r]) {
            l--;
            r++;
        }
        return { l + 1, r - 1 };
    }

    string longestPalindrome(string s) {
        int ll = 0, rr = INT_MIN;
        #pragma unroll// Add this faster
        for (int i = 0; i < s.size(); i++) {
            auto [l, r] = PalindromeC(i, i, s);
            if (r - l > rr - ll) {
                ll = l;
                rr = r;
            }
            tie(l, r) = PalindromeC(i, i + 1, s);
            if (r - l > rr - ll) {
                ll = l;
                rr = r;
            }
        }
        return s.substr(ll, rr - ll + 1);
    }
};