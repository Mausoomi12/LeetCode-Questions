class Solution {
public:
    bool search(vector<int>& v, int target) {
        int i=0,j=v.size()-1;
        while(i<=j){
            int m = (i+j)/2;
            if(v[m]==target)return true;
            if(v[i]==v[m] && v[m]==v[j]){
                i++;
                j--;
                continue;
            }
            if(v[m]>=v[i]){
                if(v[i]<= target && target<=v[m])j=m-1;
                else i = m+1;
            }
            else {
                 if(v[j]>= target && target >= v[m])i=m+1;
                else j = m-1;
            }
        }
        return false;
    }
};