class Solution {
public:
    int totalMoney(int n) {
    int totalMoney = 0;

    for (int day = 1, dailySum = 0, weeksCount = 0; day <= n; ++day) {
      if (day % 7 == 1) {
        weeksCount++;
        dailySum = weeksCount;
      }
      else
        dailySum++;

      totalMoney += dailySum;
    }

    return totalMoney;
  }
};