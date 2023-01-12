class Solution {
public:
    int lengthOfLongestSubstring(string s) {
       int i=0,j=0;
        int n=s.length();
        unordered_map<char,int> m;
        string ans;
        
        while(j<n)
        {
            
            m[s[j]]++;
            
            while(m[s[j]]>1)
            {
                if(m[s[i]]==1)
                    m.erase(s[i]);
                else if(m[s[i]]==2)
                    m[s[i]]--;
                
                i++;
                
            }
            
            if(ans.empty() || ans.length()<(j-i+1))
            {
                  ans=s.substr(i,(j-i+1));
            }
            
           j++; 
        }
      
        
        return ans.length();  
    }
};