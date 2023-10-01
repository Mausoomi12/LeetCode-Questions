class Solution {
public:
    string reverseWords(string s) {
        int start = 0;
        int end = 0;
        int n = s.length();
        
        while (end < n) {
            // Find the start of a word
            while (end < n && s[end] != ' ') {
                end++;
            }
            
            // Reverse the word from start to end
            reverse(s.begin() + start, s.begin() + end);
            
            // Move to the next word (skip spaces)
            while (end < n && s[end] == ' ') {
                end++;
            }
            
            // Update the start position for the next word
            start = end;
        }
        
        return s;
    }
};
