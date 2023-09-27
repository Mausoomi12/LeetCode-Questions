class Solution {
public:
    string decodeAtIndex(string s, int k) {
        long long len=0;
        int n=s.size();
        int s0=0;
        for (int i=0; i<n; i++){
            char c=s[i];
            if (isalpha(c)) {
                len++;
                if (k==len)//good lucky         
                    return string(1, c);
            }
            else{
                len*=(c-'0');
            }
            if (k<=len){
                s0=i;
                break;
            }
        }
    //    cout<<"s0="<<s0<<"-> len="<<len<<endl;
    
        //The last character is a number
        for (int i=s0; i>=0; i--){
            char c=s[i];
            k%=len;
            if (k==0 && isalpha(c)) return string(1, c);
            if (isdigit(c)){
                len/=(c-'0');
            }
            else len--;
        }
        return "X";
    }
};