class Solution {
public:
    bool isPalindrome(string s) {
        string str;
        for(int i=0;i<s.length();i++)
        {
            if((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z' ) )
                str.push_back(tolower(s[i]));
            else if(s[i]>='0' && s[i]<='9')
                str.push_back(s[i]);
            else
                continue;
        }
       
         int j=0; 
        int n=str.length();
        while(j<(n/2) )
        {
            if(str[j]!=str[n-1-j])
                return false;
            j++;
        }
        
        
        return true;
    }
};