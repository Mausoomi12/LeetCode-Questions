class Solution {
public:
    string largestGoodInteger(string num) {
        map<char,int>mp;
        int flag=0;
        int count=1;
        for(int i=0;i<num.size();i++){
            if(num[i]==num[i+1]) count++;
            else count=1;
            if(count>=3){
                mp[num[i]]++;
                flag=1;
            }
        }
        string s="";
        if(flag==0) return s;
        for(int i=0;i<3;i++){
            s+=mp.rbegin()->first;
        }
        return s;
    }
};