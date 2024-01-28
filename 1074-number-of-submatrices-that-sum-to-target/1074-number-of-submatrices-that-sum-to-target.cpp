class Solution {
private:
     void printMat(vector<vector<int>> mat){
         for(auto &row : mat){
             for(auto val : row){
                 cout<<val<<" ";
             }
             cout<<endl;
         }
         cout<<endl;
     }    
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size(), cols = matrix[0].size();
        for(auto &row : matrix){
            for(int col = 1; col < cols; col++){
                row[col] += row[col-1];
            }
        }
        int sumCnt = 0;
        for(int left = 0; left < cols; left++){
            for(int right = left; right < cols; right++){
                int currPrefSum = 0;
                unordered_map<int, int> sumFreq;
                sumFreq[0]++;
                for(int r = 0; r < rows; r++){
                    int prefSumCurrRow = matrix[r][right] - ((left - 1 > -1) ? matrix[r][left - 1] : 0);
                    currPrefSum += prefSumCurrRow;
                    if(sumFreq.count(currPrefSum-target)){
                        sumCnt += sumFreq[currPrefSum-target];
                    }
                    sumFreq[currPrefSum]++;
                }
            }
        }
        return sumCnt;
    }
};