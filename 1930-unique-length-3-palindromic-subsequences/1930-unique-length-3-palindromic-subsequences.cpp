class Solution {
public:
    int countPalindromicSubsequence(string s) {
        vector<int>left(26);
        vector<int>right(26);
        unordered_set<string>uset;
        for(int i = 0 ; i <s.size(); i++)
        {
            right[s[i]-'a']++;
        }

        for(int i = 0 ;i<s.size();i++)
        {
            right[s[i]-'a']--;
            for(int j = 0; j<26;j++)
            {
                if(left[j]>0 && right[j]>0)
                {
                    char x = 'a' + j; 
                    string pali = ""; 
                    pali+=x;
                    pali+=s[i];
                    pali+=x;   
                    if(uset.count(pali)==true)
                    {
                        continue;
                    }  
                    uset.insert(pali);
                }
            }
            left[s[i]-'a']++;
        }
        return uset.size();
    }
};