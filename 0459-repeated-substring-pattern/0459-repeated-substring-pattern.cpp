class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        string t = s; 

        for(int i=0; i<s.size()-1; i++){ 
            char c = t[0];  // Store the first char
            t.erase(0,1); // Remove the first char
            t.push_back(c); // Append the char

            if(t==s) { 
                return true; 
            }
        }
        return false;
    }
};