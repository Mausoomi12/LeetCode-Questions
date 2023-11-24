class Solution {
public:
    int maxCoins(vector<int>& piles) {      
        int maxi = 0 ;
        sort(piles.begin(),piles.end());
        int start = 0 ; 
        int end = piles.size()-1;
        while(start++<piles.size()/3) 
        {
            maxi += piles[end-1];
            end = end-2;
        }
        return maxi;      
    }
};