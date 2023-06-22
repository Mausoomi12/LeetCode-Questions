class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
       
        
        int n=prices.size();
       
      vector<int>ahead(2,0);
      vector<int>curr(2,0);
     
        for(int index=n-1;index>=0;index--)
        {
            curr[1]=max(-prices[index]+ ahead[0],ahead[1]);
      
          curr[0]=max(prices[index]-fee+ahead[1],ahead[0]);
          
        ahead=curr;
            }
        

        return curr[1];
    }
};
