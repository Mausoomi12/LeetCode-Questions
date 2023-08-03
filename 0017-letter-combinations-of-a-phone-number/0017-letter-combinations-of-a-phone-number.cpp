class Solution {
public:
    void generateCombos(int idx, string& digits, string& temp, vector<string>& sol, vector<string>& charMap){
        if(idx==digits.length()){
            if(temp.length()) sol.push_back(temp);
            return;
        }
        int num=digits[idx]-'0';
        string str=charMap[num];

        for(int i=0;i<str.length();i++){
            temp.push_back(str[i]);
            generateCombos(idx+1, digits, temp, sol, charMap);
            temp.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        string temp;
        vector<string> sol;
        vector<string> charMap={"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        generateCombos(0, digits, temp, sol, charMap);
        return sol;
    }
};