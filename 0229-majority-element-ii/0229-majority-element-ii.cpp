class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n=nums.size();
        int count=n/3;
        vector<pair<int,int>> vp;
        vector<int> v;
        map<int,int> mp;
        for(int i=0;i<n;i++)
        {
            mp[nums[i]]++;
        }    
        for(auto x:mp)
        {
            vp.push_back(make_pair(x.second,x.first));
        }
        for(int i=0;i<vp.size();i++)
        {
            if(vp[i].first>count)
            v.push_back(vp[i].second);
        }
        return v;
    }
};