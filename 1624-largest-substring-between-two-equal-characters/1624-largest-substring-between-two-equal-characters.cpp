class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        vector<int> idx(26,-1);
        int curr = 0 ;
        int ans = -1;
        for(int i =0;i<s.size();i++){
            char x = s[i];
            if (idx[x-'a']==-1){
                idx[x-'a'] = i;
            }
            else{
                curr = i-idx[x-'a']-1;
                ans = max(curr,ans);
            }
        }
        return ans;
    }
}; 