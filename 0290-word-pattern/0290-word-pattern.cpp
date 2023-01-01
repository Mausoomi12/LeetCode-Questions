class Solution {
public:
    bool wordPattern(string pattern, string str) {
        map<char, string> mp1;
        map<string, char> mp2;
        
        string tmp = "";
        int j = 0;
        for (int i=0;i<=str.size();i++){
            if (j == pattern.size()){ return false; }
            
            if (str[i]==' ' || i == str.size()){
                if (mp1.find(pattern[j]) == mp1.end() && mp2.find(tmp) == mp2.end()){
                    mp1[pattern[j]] = tmp;
                    mp2[tmp] = pattern[j++];
                }else{
                    if (mp1[pattern[j]] == tmp && mp2[tmp] == pattern[j]){ j++; }
                    else{   return false;  }
                }
                
                tmp = "";
                
            }else{
                tmp += str[i];    
            }
        }
        
        if (j != pattern.size()){return false;}
        
        return true;
    }
};