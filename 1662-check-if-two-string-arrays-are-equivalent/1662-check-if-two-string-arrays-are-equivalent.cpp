class Solution {
public:
    // time/space: O(n)/O(1)
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        // iterate all characters in both word lists
        int w1 = 0, w2 = 0, c1 = 0, c2 = 0;
        while ((w1 < word1.size()) && (w2 < word2.size())) {
            if (word1[w1][c1] != word2[w2][c2]) return false;
            if ((++c1) == word1[w1].size()) w1++, c1 = 0;
            if ((++c2) == word2[w2].size()) w2++, c2 = 0;
        }

        // check both word lists are all iterated
        if (w1 != word1.size()) return false;
        if (w2 != word2.size()) return false;
        return true;
    }
};