class Solution {
public:
    bool isPalindrome(int x) {
        string s = to_string(x);
        int i = 0, j = s.size();
        while(i<=j/2)
        {
            if(s[i]!=s[j-i-1])
            {
                return false;
                break;
            }
            i++;
        }
        return true;
    }
};