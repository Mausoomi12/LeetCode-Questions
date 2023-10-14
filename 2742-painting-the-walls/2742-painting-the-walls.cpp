class Solution {
public:
    int n, sum_cost;
    vector<int> cost, time;
    vector<vector<int>> dp; //(i, number of walls painted)
    int f(int i, int walls){
        if (walls>=n) return 0;
        if (i==n) return dp[i][walls]=sum_cost;//base case
        if (dp[i][walls]!=-1) return dp[i][walls];
        int ans=cost[i]+f(i+1, walls+(1+time[i])); //paid worker paints i-th wall
        ans=min(ans, f(i+1, walls));//paid worker does not paint i-th wall
        return dp[i][walls]=ans;
    }

    int paintWalls(vector<int>& cost, vector<int>& time) {
        this->cost=cost, this->time=time;
        n=cost.size();
        dp.assign(n+1, vector<int>(n+1, -1));
        sum_cost=accumulate(cost.begin(), cost.end(), 0);
        return f(0, 0);
    }
};