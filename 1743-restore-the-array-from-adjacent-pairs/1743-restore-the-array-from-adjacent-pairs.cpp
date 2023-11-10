class Solution {
public:
    // time/space: O(n)/O(n)
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        int n = adjacentPairs.size() + 1;
        // build the graph
        unordered_map<int, vector<int>> graph;
        unordered_map<int, int> indegree;
        for (auto& pair : adjacentPairs) {
            graph[pair[0]].push_back(pair[1]);
            graph[pair[1]].push_back(pair[0]);
            indegree[pair[0]]++;
            indegree[pair[1]]++;
        }

        // find the start/end node
        int start;
        for (auto& [node, deg] : indegree) {
            if (deg == 1) {
                start = node;
                break;
            }
        }

        // traverse the graph
        int curr = start, prev = INT_MIN;
        vector<int> nums;
        while (nums.size() < n) {
            nums.push_back(curr);
            for (auto& next : graph[curr]) {
                if (next != prev) {
                    prev = curr;
                    curr = next;
                    break;
                }
            }
        }
        return nums;
    }
};