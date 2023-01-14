class Solution {
public:
    char getParent(char c, vector<int> &parent){
        if(parent[c - 'a'] == -1)
            return c;
    return getParent(parent[c - 'a'], parent);
    }
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        vector<int> parent(26, -1);
        for(int i=0; i<s1.size();i++){
            char p1 = getParent(s1[i], parent);
            char p2 = getParent(s2[i], parent);
            if(p1 == p2)
                continue;
            else if(p1 > p2)
                parent[p1 - 'a'] = p2;
            else
                parent[p2 - 'a'] = p1;
        }
        string ans = "";
        for(auto x: baseStr){
            ans += getParent(x, parent);
        }
        return ans;
    }
};