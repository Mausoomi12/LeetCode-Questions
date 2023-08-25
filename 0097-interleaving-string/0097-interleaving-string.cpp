class Solution {
public:
    bool c(int i1,int i2,int i3,string &s1,string &s2,string &s3,
    vector<vector<vector<int>>>&dp){
        if(i3==s3.size()){
            if(i2==s2.size() && i1==s1.size())return true;
            else return false;
        }
        char c1='*',c2='*';
        if(dp[i1][i2][i3]!=-1)return dp[i1][i2][i3];
        if(i1<s1.size())c1=s1[i1];
        if(i2<s2.size())c2=s2[i2];
        bool ans=false;
        if(c1==s3[i3])ans |= c(i1+1,i2,i3+1,s1,s2,s3,dp);
        if(c2==s3[i3])ans |= c(i1,i2+1,i3+1,s1,s2,s3,dp);
        return dp[i1][i2][i3]=ans;
        }
    bool isInterleave(string s1, string s2, string s3) {
        vector<vector<vector<int>>>dp(s1.size()+1,vector<vector<int>>(s2.size()+1,vector<int>(s3.size(),-1)));
        return c(0,0,0,s1,s2,s3,dp);
    }
};