class Solution {
public:
    string reorganizeString(string s) {
        map<int,int>m;
        for(auto i:s)m[i]++;
        priority_queue<pair<int,char>>pq;
        for(auto i:m)pq.push({i.second,i.first});
        string ans = "";
        while(pq.size()>=2){
            auto c1 = pq.top();pq.pop();
            auto c2 = pq.top();pq.pop();
            ans += c1.second;
            ans += c2.second;
            if(c1.first-1>0)pq.push({c1.first-1,c1.second});
            if(c2.first-1>0)pq.push({c2.first-1,c2.second});
        }
        if(pq.size()){
            if(pq.top().first>1)return "";
            ans += pq.top().second;
        }
        return ans;
    }
};