class Solution {
public:
    int pivotInteger(int n) {
        int Sn=(n)*(n+1)/2;
        return sqrt(Sn) == floor(sqrt(Sn)) ? sqrt(Sn) : -1;
    }
};