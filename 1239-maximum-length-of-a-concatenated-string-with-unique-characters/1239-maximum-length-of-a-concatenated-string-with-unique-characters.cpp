class Solution {
public:
int solve(vector<string>& arr , string str , int index)
{
    unordered_set<char>uset(str.begin(),str.end());
    if((int)str.length() != uset.size())
    {
        return 0 ;
    }
    int ans = str.length();
    for(int i = index;i < arr.size();i++)
    {
        ans = max(ans,solve(arr,str + arr[i],i+1));   
    }
    return ans ; 
}

    int maxLength(vector<string>& arr) {
        return solve(arr, "", 0 );
    }
};