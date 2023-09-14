class Solution {
public:
    unordered_map<string, priority_queue<string, vector<string>, greater<string>>>   
    fly; // fly[From] is a MinHeap
    void build_graph(vector<vector<string>>& tickets){
        for(auto& edge: tickets){
            string From=edge[0], To=edge[1];
            fly[From].push(To);
        }
    }
    vector<string> ans;
    void dfs(string From){
        while(!fly[From].empty()){
            string To=fly[From].top();
            fly[From].pop();
            dfs(To);
        }
        ans.push_back(From);
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        build_graph(tickets);
        dfs("JFK");
        reverse(ans.begin(), ans.end());
        return ans;
    }
};