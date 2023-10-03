class Solution {
public:
    int numIdenticalPairs(vector<int>& a) {
        int i,c=0;

        unordered_map<int,int>map;

        for(i=0;i<a.size();i++){
            if(map.find(a[i])!=map.end())
            c+=map[a[i]];
                
            map[a[i]]++;
        }
        return c;
    }
};