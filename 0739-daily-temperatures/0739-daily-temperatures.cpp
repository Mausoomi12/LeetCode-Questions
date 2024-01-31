class Solution {
public:
    vector<int> dailyTemperatures( vector<int>& temp) {
        vector<int> ans(temp.size(),0);
        stack <int> stk;  // Stack
        for(int i=temp.size()-1;i>=0;i--){
            if(stk.empty()){
                stk.push(i);
                ans[i] = 0;
            }
            else{

                // For a given index , check the stack
                while(!stk.empty() && temp[i]>=temp[stk.top()]){
                    stk.pop();
                }

                // if stack is empty then no wormer day
                if(stk.empty()){
                    ans[i] = 0;
                }
                // Calculate the wormer day
                else{
                    ans[i] = stk.top()-i;
                }
                stk.push(i);
            }
            
        }
        return ans;
    }
}; 