class Solution {
public:
    string largestOddNumber(string num) {
        int n = num.length();
        int last = 0;
        bool flag = false;
        for(int i = n-1; i >= 0; i--)
            if((num[i] - '0') % 2 == 1){
                last = i;
                flag = !flag;
                break;
            }
                
        if(last == 0 && !flag) return "";
        else return num.substr(0,abs(0 - last)+1);
    }
};