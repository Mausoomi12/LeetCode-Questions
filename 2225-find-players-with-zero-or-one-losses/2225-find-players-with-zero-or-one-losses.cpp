class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        map<int, pair<int, int>> mp;
        for(auto i : matches){
            mp[i[0]].first++;
            mp[i[1]].second++;
        }
        vector<vector<int>> ans(2);
        for(auto [i, v] : mp){
            if(v.second == 0) ans[0].push_back(i);
            else if(v.second == 1) ans[1].push_back(i);
        }
        return ans;
    }
};