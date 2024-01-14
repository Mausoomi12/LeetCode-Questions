class Solution {
public:
    bool closeStrings(string word1, string word2) {

        if(word1.size() != word2.size()) return false;

        map<char,int> mp1;
        for(auto it:word1)  mp1[it]++;
        
        map<char,int> mp2;
        for(auto it:word2)  mp2[it]++;

        string UniqueWord1,occUniqueWord1;
        string UniqueWord2,occUniqueWord2;
        
        for(auto it:mp1)
        {
            UniqueWord1+=it.first;
            occUniqueWord1+=to_string(it.second);
        }
        for(auto it:mp2)
        {
            UniqueWord2+=it.first;
            occUniqueWord2+=to_string(it.second);
        }

        if(UniqueWord1!=UniqueWord2)  return false;
        sort(occUniqueWord1.begin(),occUniqueWord1.end());
        sort(occUniqueWord2.begin(),occUniqueWord2.end());
        if(occUniqueWord1 != occUniqueWord2) return false;
        return true;
        
    }
};